#include <iostream>


// VIOLATION


// Apple Charger class
// class AppleCharger {
// public:
//     void charge() {
//         std::cout << "Charging with Apple charger." << std::endl;
//     }
// };

// // Samsung Charger class
// class SamsungCharger {
// public:
//     void charge() {
//         std::cout << "Charging with Samsung charger." << std::endl;
//     }
// };

// // Phone class directly depends on specific chargers (violation)
// class Phone {
// public:
//     void chargeWithAppleCharger() {
//         AppleCharger appleCharger;
//         appleCharger.charge();
//     }

//     void chargeWithSamsungCharger() {
//         SamsungCharger samsungCharger;
//         samsungCharger.charge();
//     }
// };

// int main() {
//     Phone phone;
//     phone.chargeWithAppleCharger();    // Charging with Apple Charger
//     phone.chargeWithSamsungCharger();  // Charging with Samsung Charger

//     return 0;
// }


// FIXED


// Abstraction: Charger interface
class Charger {
public:
    virtual void charge() const = 0;  // Pure virtual function (abstraction)
    virtual ~Charger() {}
};

// AppleCharger implements Charger interface
class AppleCharger : public Charger {
public:
    void charge() const override {
        std::cout << "Charging with Apple charger." << std::endl;
    }
};

// SamsungCharger implements Charger interface
class SamsungCharger : public Charger {
public:
    void charge() const override {
        std::cout << "Charging with Samsung charger." << std::endl;
    }
};

// New USBCharger implements Charger interface
class USBCharger : public Charger {
public:
    void charge() const override {
        std::cout << "Charging with USB charger." << std::endl;
    }
};

// Phone class depends on Charger abstraction instead of specific chargers
class Phone {
public:
    void charge(const Charger& charger) const {
        charger.charge();  // Phone can now charge with any charger!
    }
};

int main() {
    AppleCharger appleCharger;
    SamsungCharger samsungCharger;
    USBCharger usbCharger;  // New USB charger

    Phone phone;
    phone.charge(appleCharger);   // Charging with Apple charger
    phone.charge(samsungCharger); // Charging with Samsung charger
    phone.charge(usbCharger);     // Charging with USB charger (new!)

    return 0;
}
