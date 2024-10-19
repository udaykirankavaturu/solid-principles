#include <iostream>
using namespace std;


// VIOLATION
// Base class
// class Payment {
// public:
//     virtual void processPayment() {
//         cout << "Processing general payment" << endl;
//     }
// };

// // Subclass for Credit Card
// class CreditCard : public Payment {
// public:
//     void processPayment() override {
//         cout << "Processing credit card payment" << endl;
//     }
// };

// // Subclass for Debit Card (Violation: Asking for PIN during payment process)
// class DebitCard : public Payment {
// public:
//     void processPayment() override {
//         string pin;
//         cout << "Enter PIN to process debit card payment: ";
//         cin >> pin;

//         if (isPinValid(pin)) {
//             cout << "Processing debit card payment with PIN" << endl;
//         } else {
//             cout << "Error: Invalid PIN!" << endl;
//         }
//     }

//     bool isPinValid(const string& pin) const {
//         // Simple check, in real cases you'd verify the PIN
//         return pin == "1234";
//     }
// };

// // Function that works with any Payment type
// void makePayment(Payment* payment) {
//     payment->processPayment();  // DebitCard breaks the expected behavior
// }

// int main() {
//     CreditCard creditCard;
//     DebitCard debitCard;

//     makePayment(&creditCard);   // Works fine
//     makePayment(&debitCard);    // Unexpected: asks for PIN input, breaks LSP

//     return 0;
// }




// FIXED

// // Base class
class Payment {
public:
    virtual void processPayment() {
        cout << "Processing general payment" << endl;
    }
};

// Subclass for Credit Card
class CreditCard : public Payment {
public:
    void processPayment() override {
        cout << "Processing credit card payment" << endl;
    }
};

// Subclass for Debit Card (Fix: Handle PIN before calling processPayment)
class DebitCard : public Payment {
private:
    string pin;
public:
    DebitCard(const string& inputPin) : pin(inputPin) {}

    void processPayment() override {
        if (isPinValid()) {
            cout << "Processing debit card payment with PIN" << endl;
        } else {
            cout << "Error: Invalid PIN!" << endl;
        }
    }

    bool isPinValid() const {
        // Simple check, in real cases you'd verify the PIN
        return pin == "1234";
    }
};

// Function that works with any Payment type
void makePayment(Payment* payment) {
    payment->processPayment();  // Works for all payment types
}

int main() {
    CreditCard creditCard;
    DebitCard debitCard("1234");  // Correct PIN
    DebitCard wrongPinCard("4321");  // Incorrect PIN

    makePayment(&creditCard);   // Works fine
    makePayment(&debitCard);    // Works fine, PIN already handled
    makePayment(&wrongPinCard); // Fails due to invalid PIN

    return 0;
}
