#include <iostream>
#include <string>

// VIOLATION
// class USBDeviceManager {
// public:
//     void connectDevice(const std::string& device) {
//         if (device == "keyboard") {
//             std::cout << "Connecting a keyboard." << std::endl;
//         } else if (device == "mouse") {
//             std::cout << "Connecting a mouse." << std::endl;
//         }
//         // Adding a new device would require modifying this method.
//     }
// };

// int main() {
//     USBDeviceManager manager;
//     manager.connectDevice("keyboard");
//     manager.connectDevice("mouse");
    
//     // To add a printer, we would need to modify the existing method.
//     // manager.connectDevice("printer");
//     return 0;
// }











// FIXED
// // Abstract class for USBDevice
class USBDevice {
public:
    virtual void connect() const = 0; // Pure virtual method
    virtual ~USBDevice() {}
};

// Keyboard class implements USBDevice
class Keyboard : public USBDevice {
public:
    void connect() const override {
        std::cout << "Connecting a keyboard." << std::endl;
    }
};

// Mouse class implements USBDevice
class Mouse : public USBDevice {
public:
    void connect() const override {
        std::cout << "Connecting a mouse." << std::endl;
    }
};

class Printer : public USBDevice {
public:
    void connect() const override {
        std::cout << "Connecting a Printer." << std::endl;
    }
};

// USBDeviceManager is now open for extension, but closed for modification
class USBDeviceManager {
public:
    void connectDevice(const USBDevice& device) {
        device.connect();  // Calls the appropriate connect method based on the object type
    }
};

int main() {
    USBDeviceManager manager;
    Keyboard keyboard;
    Mouse mouse;
    Printer printer;

    manager.connectDevice(keyboard);
    manager.connectDevice(mouse);
    manager.connectDevice(printer);

    // Adding a new device like Printer doesn't require modifying USBDeviceManager
    return 0;
}
