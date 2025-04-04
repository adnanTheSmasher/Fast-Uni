#include<iostream>
#include<string.h>
#include<cstdlib>
#include<ctime> 
using namespace std;

class Ghost
{
    protected:
        string nameOfWorker;
        string nameOfGhost;
        int scareLevel;
    public:
        Ghost(string Workername, string ghostName): nameOfWorker(Workername), nameOfGhost(ghostName)
        {
            scareLevel = rand() % 10 + 1;
        };
        virtual void hunt(){};

        friend ostream& operator << (ostream& out, const Ghost& ghost)
        {
            out << "Ghost playing worker Name: " << ghost.nameOfWorker <<", Ghost Name: " << ghost.nameOfGhost << ", Ghost Scare level: " << ghost.scareLevel<<endl;
            return out;
        }

        int getScarelevel(){return scareLevel;}
        Ghost operator+ (const Ghost& other)
        {
            string upgradedGhostWorkerName = this->nameOfWorker + other.nameOfWorker;
            string upgradedGhostName = this->nameOfGhost + other.nameOfGhost;

            Ghost upgradedGhost(upgradedGhostWorkerName, upgradedGhostName);
            upgradedGhost.scareLevel = this->scareLevel + other.scareLevel;
            if(upgradedGhost.getScarelevel() > 10)
                upgradedGhost.scareLevel = 10;
            return upgradedGhost;
        }

        string getNameofWorker(){return nameOfWorker;}
        string getNameofGhost(){return nameOfGhost;}
};

class Poltergeist: virtual public Ghost
{
    private:
        string power;
    public:
        Poltergeist(string n, string gn): Ghost(n, gn){
            power = "Moves Objects";
        };

        virtual void hunt() override
        {
            cout<< nameOfGhost<< " is using his power: "<< power;
        }
        string getPower(){return power;}

};

class Banshee: virtual public Ghost
{
    private:
        string power;
    public:
        Banshee(string n, string gn): Ghost(n, gn){
            power = "Screams Loudly";
        };

        virtual void hunt() override
        {
            cout<< nameOfGhost<< " is using his power: "<< power;
        }
        string getPower(){return power;}
};

class ShadowGhost: virtual public Ghost
{
    private:
        string power;
    public:
        ShadowGhost(string n, string gn): Ghost(n, gn){
            power = "Whisper Creepily";
        };

        virtual void hunt() override
        {
            cout<< nameOfGhost<< " is using his power: "<< power;
        }
        string getPower(){return power;}
};

class ShadowPotergeist: public Poltergeist, public ShadowGhost 
{
    public:
        ShadowPotergeist(string n1, string gn1, string n2, string gn2) 
            : Poltergeist(n1, gn1), ShadowGhost(n2, gn2), Ghost(n1 + n2, gn1 + gn2) {}

        void hunt() override
        {
            cout << getNameofGhost() << " is using both powers: " << Poltergeist::getPower() << " and " << ShadowGhost::getPower() << endl;
        }
};

class ShadowBanshee: public Banshee, public ShadowGhost 
{
    public:
        ShadowBanshee(string n1, string gn1, string n2, string gn2) 
            : Banshee(n1, gn1), ShadowGhost(n2, gn2), Ghost(n1 + n2, gn1 + gn2) {}

        void hunt() override
        {
            cout << getNameofGhost() << " is using both powers: " << Banshee::getPower() << " and " << ShadowGhost::getPower() << endl;
        }
};

class Visitor
{
    private: 
        string name;
        int bravery;
    public:
        Visitor(string n, int b): name(n), bravery(b){

        };
        void visit(Ghost* ghost)
        {
            cout << name << " is visiting the haunted house." << endl;
        ghost->hunt();
        if (ghost->getScarelevel() < bravery) {
            cout << name << " laughs at the ghost!" << endl;
        } else if (ghost->getScarelevel() > bravery) {
            cout << name << " screams and runs away!" << endl;
        } else {
            cout << name << " has a shaky voice!" << endl;
        }
        }
};

class HauntedHouse {
private:
    string name;
    Ghost* ghosts[4]; 
public:
    HauntedHouse(string n, Ghost* g1, Ghost* g2, Ghost* g3, Ghost* g4) : name(n) {
        ghosts[0] = g1;
        ghosts[1] = g2;
        ghosts[2] = g3;
        ghosts[3] = g4;
    }

    void simulateVisit(Visitor* visitors, int numVisitors) {
        cout << "Visitors are entering the " << name << "!" << endl;
        for (int i = 0; i < numVisitors; i++) {
            visitors[i].visit(ghosts[i % 4]); 
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); 

    Poltergeist* p1 = new Poltergeist("James", "poltergeist");
    Banshee* b1 = new Banshee("Jane", "Banshee");
    ShadowGhost* s1 = new ShadowGhost("Mary", "Shadowy");
    ShadowPotergeist* sp1 = new ShadowPotergeist(p1->getNameofWorker(), "Poltergeist", s1->getNameofWorker(), "ShadowGhost"); 
    
    Poltergeist* p2 = new Poltergeist("Dove", "poltergeist");
    Banshee* b2 = new Banshee("Hittler", "Banshee");
    ShadowGhost* s2 = new ShadowGhost("Napolean", "Shadowy");
    ShadowPotergeist* sp2 = new ShadowPotergeist(p2->getNameofWorker(), "Poltergeist", s2->getNameofWorker(), "ShadowGhost"); 

    Poltergeist* p3 = new Poltergeist("Alexandar", "poltergeist");
    Banshee* b3 = new Banshee("Akbar", "Banshee");
    ShadowGhost* s3 = new ShadowGhost("Ertugrul", "Shadowy");
    ShadowBanshee* sp3 = new ShadowBanshee(b3->getNameofWorker(), "Banshee", s3->getNameofWorker(), "ShadowGhost"); 


    HauntedHouse hauntedHouse1("Spooky Mansion", p1, b1, s1, sp1);
    HauntedHouse hauntedHouse2("Spooky Mansion", p2, b2, s2, sp2);
    HauntedHouse hauntedHouse3("Spooky Mansion", p3, b3, s3, sp3);

    Visitor visitors1[4] = {
        Visitor("Alice", 5),   
        Visitor("Bob", 8),     
        Visitor("Charlie", 3), 
        Visitor("David", 6)    
    };

    Visitor visitors2[4] = {
        Visitor("Yushaa", 5),   
        Visitor("Murtaza", 8),     
        Visitor("Abizer", 3), 
        Visitor("Turab", 10)    
    };

    Visitor visitors3[4] = {
        Visitor("Thesues", 5),   
        Visitor("Tom", 8),     
        Visitor("Robert", 3), 
        Visitor("Hulk", 6)    
    };
    


    cout<<"\n---------Merging Ghosts---------\n";
    Ghost merging = *p1 + *s1;
    cout << merging;
    cout<<"---------Merging Ghosts---------\n";
    
    cout<<"\n---------Simulating House No 1---------\n";
    hauntedHouse1.simulateVisit(visitors1, 4);
    cout<<"---------Simulating House No 1---------\n";

    cout<<"\n---------Simulating House No 2---------\n";
    hauntedHouse1.simulateVisit(visitors2, 4);
    cout<<"---------Simulating House No 2---------\n";   

    cout<<"\n---------Simulating House No 3---------\n";
    hauntedHouse1.simulateVisit(visitors3, 4);
    cout<<"---------Simulating House No 3---------\n";

    delete p1;
    delete b1;
    delete s1;
    delete sp1;
    
    delete p2;
    delete b2;
    delete s2;
    delete sp2;
    
    delete p3;
    delete b3;
    delete s3;
    delete sp3;
    
    return 0;

}
