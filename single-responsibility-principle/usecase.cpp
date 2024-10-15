#include <iostream>
#include <fstream>
#include <string>

// VIOLATION
class Logger {
public:
    // Function to log a message
    void logMessage(const std::string& message) {
        std::cout << "Logging message: " << message << std::endl;
        saveToFile(message);
    }

private:
    // Function to save message to a file
    void saveToFile(const std::string& message) {
        std::ofstream file("log.txt", std::ios::app);
        if (file.is_open()) {
            file << message << std::endl;
            file.close();
        }
    }
};

int main() {
    Logger logger;
    logger.logMessage("System started.");
    return 0;
}

// FIXED
// // Class responsible for logging messages
// class ConsoleLogger {
// public:
//     void logMessage(const std::string& message) {
//         std::cout << "Logging message: " << message << std::endl;
//     }
// };

// // Class responsible for saving messages to a file
// class FileManager {
// public:
//     void saveToFile(const std::string& message) {
//         std::ofstream file("log.txt", std::ios::app);
//         if (file.is_open()) {
//             file << message << std::endl;
//             file.close();
//         }
//     }
// };

// int main() {
//     ConsoleLogger consoleLogger;
//     FileManager fileManager;

//     consoleLogger.logMessage("System started.");
//     fileManager.saveToFile("System started.");

//     return 0;
// }