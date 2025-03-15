#include <iostream>
using namespace std;

class GraphicsEngine {
public:
    void render() {
        cout << "Rendering graphics..." << endl;
    }
};


class InputHandler {
public:
    void processInput() {
         cout << "Processing input..." <<  endl;
    }
};

class PhysicsEngine {
public:
    void updatePhysics() {
         cout << "Updating physics..." <<  endl;
    }
};

class GameEngine {
private:
    GraphicsEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void run() {
        while (true) {
            inputHandler.processInput();
            physicsEngine.updatePhysics();
            graphicsEngine.render();
            break;
        }
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();
    return 0;
}