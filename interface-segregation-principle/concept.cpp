#include <iostream>


// VIOLATION

// // A bloated interface with multiple unrelated methods
// class RobotInterface {
// public:
//     virtual void clean() = 0;
//     virtual void cook() = 0;
//     virtual void dance() = 0;
//     virtual ~RobotInterface() {} 
// };

// // CleaningRobot is forced to implement unrelated methods
// class CleaningRobot : public RobotInterface {
// public:
//     void clean() override {
//         std::cout << "Cleaning the house." << std::endl;
//     }

//     // Irrelevant methods for CleaningRobot
//     void cook() override {
//         std::cout << "I don't know how to cook!" << std::endl;
//     }

//     void dance() override {
//         std::cout << "I can't dance!" << std::endl;
//     }
// };
 
// int main() {
//     CleaningRobot cleaner;
//     cleaner.clean();
//     cleaner.cook();  // Violates ISP: Forced to implement this
//     cleaner.dance(); // Violates ISP: Forced to implement this
    
//     return 0;
// }










// FIXED

// Separate interfaces for specific capabilities
class CleaningRobotInterface {
public:
    virtual void clean() = 0;
    virtual ~CleaningRobotInterface() {}
};

class CookingRobotInterface {
public:
    virtual void cook() = 0;
    virtual ~CookingRobotInterface() {}
};

class DancingRobotInterface {
public:
    virtual void dance() = 0;
    virtual ~DancingRobotInterface() {}
};

// CleaningRobot now only implements the cleaning interface
class CleaningRobot : public CleaningRobotInterface {
public:
    void clean() override {
        std::cout << "Cleaning the house." << std::endl;
    }
};

int main() {
    CleaningRobot cleaner;
    cleaner.clean();  // Only implements what is necessary

    // cleaner.cook(); // This won't compile, which is correct
    // cleaner.dance(); // This won't compile, which is correct
    
    return 0;
}
