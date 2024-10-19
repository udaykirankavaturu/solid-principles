#include <iostream>
using namespace std;

// VIOLATION
// Base class
// class PizzaDelivery {
// public:
//     virtual void deliverPizza() {
//         cout << "Delivering pizza to your doorstep!" << endl;
//     }
// };

// // Subclass for regular delivery
// class RegularDelivery : public PizzaDelivery {
// public:
//     void deliverPizza() override {
//         cout << "Pizza delivered by our friendly driver to your doorstep!" << endl;
//     }
// };

// // Subclass for drone delivery (Violation: Asking customer if they're ready for pickup)
// class DroneDelivery : public PizzaDelivery {
// public:
//     void deliverPizza() override {
//         string ready;
//         cout << "Is the customer ready to pick up the pizza at the door? (yes/no): ";
//         cin >> ready;

//         if (ready == "yes") {
//             cout << "Drone is lowering the pizza to your doorstep!" << endl;
//         } else {
//             cout << "Please come to the door to collect your pizza!" << endl;
//         }
//     }
// };

// Function to handle pizza deliveries
// void sendPizza(PizzaDelivery* deliveryService) {
//     deliveryService->deliverPizza();  // Expecting consistent pizza delivery behavior
// }

// int main() {
//     RegularDelivery regularDelivery;
//     DroneDelivery droneDelivery;

//     sendPizza(&regularDelivery);  // Works as expected, pizza delivered to the door
//     sendPizza(&droneDelivery);    // Violation! Asks if customer is ready, breaks LSP

//     return 0;
// }



// FIXED
// Base class
class PizzaDelivery {
public:
    virtual void deliverPizza() {
        cout << "Delivering pizza to your doorstep!" << endl;
    }
};

// Subclass for regular delivery
class RegularDelivery : public PizzaDelivery {
public:
    void deliverPizza() override {
        cout << "Pizza delivered by our friendly driver to your doorstep!" << endl;
    }
};

// Subclass for drone delivery (Fix: Drone delivers pizza without any user input)
class DroneDelivery : public PizzaDelivery {
public:
    void deliverPizza() override {
        cout << "Drone is carefully lowering the pizza to your doorstep!" << endl;
    }
};

// Function to handle pizza deliveries
void sendPizza(PizzaDelivery* deliveryService) {
    deliveryService->deliverPizza();  // Consistent pizza delivery behavior for all
}

int main() {
    RegularDelivery regularDelivery;
    DroneDelivery droneDelivery;

    sendPizza(&regularDelivery);  // Works as expected, pizza delivered to the door
    sendPizza(&droneDelivery);    // Now works as expected too, no interaction needed

    return 0;
}

