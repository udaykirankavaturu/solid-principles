#include <iostream>
#include <string>

// VIOLATION
// class Robot {
// public:
//     // Function to move the robot
//     void move() {
//         std::cout << "Robot is moving forward." << std::endl;
//     }

//     // Function to make the robot talk
//     void talk() {
//         std::cout << "Robot says: 'Hello, world!'" << std::endl;
//     }
// };

// int main() {
//     Robot robot;
//     robot.move();
//     robot.talk();
//     return 0;
// }


// FIXED
#include <iostream>
#include <string>

// Class responsible for robot movement
class Movement {
public:
    void move() {
        std::cout << "Robot is moving forward." << std::endl;
    }
};

// Class responsible for robot speech
class Speech {
public:
    void talk() {
        std::cout << "Robot says: 'Hello, world!'" << std::endl;
    }
};

int main() {
    Movement movement;
    Speech speech;

    movement.move();
    speech.talk();

    return 0;
}
