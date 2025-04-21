#include <iostream>

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0; 
    virtual ~Activity() {} 
};

class Running : public Activity {
private:
    double distance;
    double time;    

public:
    Running(double dist, double t) : distance(dist), time(t) {}

    double calculateCaloriesBurned() override {
        double caloriesBurned = time * distance; 
        std::cout << "Running: Distance = " << distance << " km, Time = " << time << " min, Calories Burned = " << caloriesBurned << " kcal" << std::endl;
        return caloriesBurned;
    }
};

class Cycling : public Activity {
private:
    double speed; 
    double time; 

public:
    Cycling(double spd, double t) : speed(spd), time(t) {}

    double calculateCaloriesBurned() override {
        
        double caloriesBurned = time * speed; 
        std::cout << "Cycling: Speed = " << speed << " km/h, Time = " << time << " hours, Calories Burned = " << caloriesBurned << " kcal" << std::endl;
        return caloriesBurned;
    }
};

int main() {
    
    Running myRun(5.0, 30.0); 
    Cycling myCycle(20.0, 1.5); 

 
    myRun.calculateCaloriesBurned();
    myCycle.calculateCaloriesBurned();

    return 0;
}