#include<iostream>
#include<string>
using namespace std;

int const MAX_SkillS = 5;
int const MAX_SPORTS = 5;


class Skill
{
    private:
        int skillID;
        string skillName;
        string description;

    public:
        Skill() : skillID(0), skillName(""), description("") {}

        Skill(int sk_ID, string sk_name, string sk_desc)
        {
            skillID = sk_ID;
            skillName = sk_name;
            description = sk_desc;
        }
        void showSkillDetails()
        {
            cout<<"\nSkill Details are as follows....\n";
            cout<<"Skill Name: "<< skillName <<"\n";
            cout<<"Description: "<<description<<"\n";
        }

        void updateSkillDescription(string newDescription)
        {
            description = newDescription;
            cout<<"\nNew Description of the Skill Uploaded";
        }

        int get_skillID()
        {
            return skillID;
        }
        string get_skillName()
        {
            return skillName;
        }
        string get_description()
        {
            return description;
        }


};


class Sport
{
    private:
        int sportID;
        string name;
        string description;
        Skill requiredSkills[MAX_SkillS];
        int numOfSkill = 0;

    public:
        Sport() : sportID(0), name(""), description(""), numOfSkill(0) {}

        Sport(int id, string name, string sp_desc)
        {
            sportID = id;
            this->name = name;
            description = sp_desc;
        }


        void addSkill(Skill s)
        {
            if(numOfSkill < MAX_SkillS)
            {
                requiredSkills[numOfSkill] = s;
                numOfSkill++;
            }
            else
            {
                cout<< "Cannot Add more skill as Maximum reached....";
            }
        }

        void removeSkill(Skill s)
        {
            int found = 0;
            for(int i=0; i<numOfSkill; i++)
            {
                if(requiredSkills[i].get_skillID() == s.get_skillID())
                {
                    found = 1;
                    for(int j = i; j<numOfSkill-1; j++)
                    {
                        requiredSkills[j] = requiredSkills[j+1];
                    }
                    numOfSkill--;
                    break;
                }
            }
            if(!found)
            {
                cout << "Skill with ID " << s.get_skillID() << " not found in " << name << ".\n";
            }
        }

        int get_sportID()
        {
            return sportID;
        }

        string get_sportname()
        {
            return name;
        }


};

class Student; // Forward declaration

class Mentor {
private:
    int mentor_ID;
    string name;
    int maxLearners;
    Sport sportsExpertise[MAX_SPORTS];
    Student* assignedLearners[MAX_SPORTS]; // Changed to MAX_SPORTS for consistency
    int numOfLearner;

public:
    Mentor(int id, string m_name, int m_Maxlearners) {
        mentor_ID = id;
        name = m_name;
        maxLearners = m_Maxlearners;
        numOfLearner = 0; // Initialize number of learners
        for (int i = 0; i < MAX_SPORTS; i++) {
            assignedLearners[i] = nullptr; // Initialize pointers to nullptr
        }
    }

    bool assignLearner(Student* s);
    void removeLearner(Student* s);
    void viewLearners();
    void addSportExpertise(Sport s) {
        if (numOfLearner < MAX_SPORTS) {
            sportsExpertise[numOfLearner] = s;
            numOfLearner++;
        } else {
            cout << "Cannot add more sports expertise as maximum reached....";
        }
    }

    void provideGuidance()
    {
        cout<<"Mentor: "<< name<< " is providing Guidance";
    }

    int get_mentorID() {
        return mentor_ID;
    }
    string get_mentorName() {
        return name;
    }
};

class Student {
private:
    int student_ID;
    string name;
    int age;
    Sport sportInterest[MAX_SPORTS];
    Mentor* mentorAssigned;
    int numOfSportInterestedIN;

public:
    Student() : student_ID(0), name(""), age(0), mentorAssigned(nullptr), numOfSportInterestedIN(0) {}

    Student(int s_ID, string s_name, int s_age) {
        student_ID = s_ID;
        name = s_name;
        age = s_age;
        mentorAssigned = nullptr; // Initialize mentorAssigned
        numOfSportInterestedIN = 0; // Initialize number of sports interested
    }

    void registerForMentorship(Mentor* m) {
        if (m->assignLearner(this)) {
            mentorAssigned = m;
            cout << "\nStudent: " << name << " has been assigned to instructor " << m->get_mentorName();
        } else {
            cout << "\nStudent cannot be assigned to Instructor " << m->get_mentorName();
        }
    }

    void updateSportsInterest(Sport s) {
        if (numOfSportInterestedIN < MAX_SPORTS) {
            sportInterest[numOfSportInterestedIN] = s;
            numOfSportInterestedIN++;
            cout << "\nSport interest updated for student: " << name;
        } else {
            cout << "Cannot add more sports interest as maximum reached....";
        }
    }

     void viewMentorDetails() {
        if (mentorAssigned != nullptr) {
            cout << "\nMentor Details:\n";
            cout << "Mentor ID: " << mentorAssigned->get_mentorID() << "\n";
            cout << "Mentor Name: " << mentorAssigned->get_mentorName() << "\n";
        } else {
            cout << "No mentor assigned to student: " << name << "\n";
        }
    }

    int get_stuID() {
        return student_ID;
    }
    string get_stu_name() {
        return name;
    }
};

bool Mentor::assignLearner(Student* s) {
    if (numOfLearner < maxLearners) {
        assignedLearners[numOfLearner] = s;
        numOfLearner++;
        return true;
    } else {
        cout << "Cannot assign learners as maximum learner reached";
        return false;
    }
}

void Mentor::removeLearner(Student* s) {
    int found = 0;
    for (int i = 0; i < numOfLearner; i++) {
        if (assignedLearners[i] != nullptr && assignedLearners[i]->get_stuID() == s->get_stuID()) {
            found = 1;
            for (int j = i; j < numOfLearner - 1; j++) {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            assignedLearners[numOfLearner - 1] = nullptr; // Set last pointer to nullptr
            numOfLearner--;
            break;
        }
    }
    if (!found) {
        cout << "Student not found among " << name << "'s assigned learners.\n";
    }
}

void Mentor::viewLearners() {
    cout << "\n-----------Learner Assigned Till now-------------\n";
    if (numOfLearner == 0) {
        cout << "No learner assigned yet.....\n"; // Corrected message
    } else {
        for (int i = 0; i < numOfLearner; i++) {
            if (assignedLearners[i] != nullptr) { // Check for nullptr
                cout << "\n------------------------\n";
                cout << "Student ID: " << assignedLearners[i]->get_stuID()
                     << ", Name: " << assignedLearners[i]->get_stu_name() << "\n";
                cout << "\n------------------------\n";
            }
        }
    }
}

int main()
{
    Skill skill1(1, "Serve", "Ability to serve effectively in tennis.");
    Skill skill2(2, "Forehand", "Strong forehand shot in tennis.");
    cout<<"skills added";
    Sport tennis(101, "Tennis", "A sport played with rackets and balls.");
    tennis.addSkill(skill1);
    tennis.addSkill(skill2);
    cout<<"sport added";
    Mentor mentorAli(201, "Ali", 3);
    mentorAli.addSportExpertise(tennis);
    cout<<"mentor added";
    Student studentSaad(301, "Saad", 20);
    studentSaad.updateSportsInterest(tennis);

    studentSaad.registerForMentorship(&mentorAli);

    mentorAli.viewLearners();

    studentSaad.viewMentorDetails();

    mentorAli.provideGuidance();


    mentorAli.viewLearners();

    return 0;
}