#include<iostream>
#include<string.h>
using namespace std;

class Robot
{
    private:
        string name;
        int hits;
    public:
        Robot(): name(""), hits(0){};
        Robot(string _name, int _hits = 0)
        {
            name = _name;
            hits = _hits;
        }
        void hitBall(int &ballX, int &ballY, const string &direction)
        {
            if (direction == "up")
                ballY++;
            else if (direction == "down")
                ballY--;
            else if (direction == "left") 
                ballX--;
            else if (direction == "right") 
                ballX++;
            hits++;
        }

        int getHits()
        {
            return hits;
        }
        string getName()
        {
            return name;
        }
};

class Ball
{
    private:
        int X;
        int Y;
    
    public:
        Ball(): X(0), Y(0){};

        void move(int dx, int dy)
        {
            X += dx;
            Y += dy;
        }

        tuple<int, int> getPosition() 
        {
            return make_tuple(X, Y);
        }

        int getX()
        {
            return X;
        }
        void setX(int x)
        {
            X = x;
        }
        void setY(int y)
        {
            Y = y;
        }
        int getY()
        {
            return Y;
        }
};

class Goal
{
    private:
        int X;
        int Y;
    public:
        Goal(): X(3), Y(3){};

        bool isGoalReached(int ballX, int ballY)
        {
            if(ballX == X && ballY == Y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

class Team
{
    private:
        Robot* r;
        string TeamName;

    public:
        Team(string _name, Robot *robot)
        {
            TeamName = _name;
            r = robot;
        }

        string getTeamName() 
        {
            return TeamName;
        }

        Robot* getRobot()
        {
            return r;
        }
};

class Game
{
    private:
        Team* t1;
        Team* t2;
        Ball ball;
        Goal goal;
    public:

        Game(Team* team1, Team* team2): t1(team1), t2(team2){};

        void startGame() 
        {
            play(t1);
            ball.setX(0);
            ball.setY(0);

            play(t2);
            declareWinner();
        }

        void play(Team *team)
        {
            Robot* r = team->getRobot();
            int ballX = ball.getX();
            int ballY = ball.getY();
            string direction = "";

            while(!goal.isGoalReached(ballX, ballY))
            {
                cout << team->getTeamName() << "'s turn. Current ball position: (" << ballX << ", " << ballY << ")\n";
                cout << "Enter direction to hit the ball (up, down, left, right): ";
                cin >> direction;

                r->hitBall(ballX, ballY, direction);
                ball.move(ballX - ball.getX(), ballY - ball.getY());

                ball.setX(ballX);
                ball.setY(ballY);
            }
            cout << team->getTeamName() << " reached the goal with " << r->getHits() << " hits!\n";

        }

        void declareWinner()
        {
            int teamOneHits = t1->getRobot()->getHits();
            int teamTwoHits = t2->getRobot()->getHits();

            if (teamOneHits < teamTwoHits)
                cout << t1->getTeamName() << " wins!\n";
            else if (teamTwoHits < teamOneHits) 
                cout << t2->getTeamName() << " wins!\n";
            else
                cout << "It's a tie!\n";
        }
};

int main()
{
    Robot robot1("Robot1", 0);
    Robot robot2("Robot2", 0);

    Team team1("Team A", &robot1);
    Team team2("Team B", &robot2);

    Game game(&team1, &team2);
    game.startGame();

    return 0;
}