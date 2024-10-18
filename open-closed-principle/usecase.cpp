#include <iostream>
#include <string>


// VIOLATION
// class PaymentProcessor {
// public:
//     void processPayment(const std::string& paymentType) {
//         if (paymentType == "CreditCard") {
//             std::cout << "Processing credit card payment." << std::endl;
//         } else if (paymentType == "PayPal") {
//             std::cout << "Processing PayPal payment." << std::endl;
//         }
//         // Adding a new payment method would require modifying this method.
//     }
// };

// int main() {
//     PaymentProcessor processor;
//     processor.processPayment("CreditCard");
//     processor.processPayment("PayPal");

//     // Adding a new payment type (e.g., Bitcoin) requires modifying the method
//     // processor.processPayment("Bitcoin");
//     return 0;
// }










// FIXED
// // Abstract class for PaymentMethod
class PaymentMethod {
public:
    virtual void processPayment() const = 0; // Pure virtual method
    virtual ~PaymentMethod() {}
};

// CreditCard class implements PaymentMethod
class CreditCard : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processing credit card payment." << std::endl;
    }
};

// PayPal class implements PaymentMethod
class PayPal : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processing PayPal payment." << std::endl;
    }
};

// UPI class implements PaymentMethod
class UPI : public PaymentMethod {
public:
    void processPayment() const override {
        std::cout << "Processing UPI payment." << std::endl;
    }
};

// PaymentProcessor is now open for extension, but closed for modification
class PaymentProcessor {
public:
    void process(const PaymentMethod& paymentMethod) {
        paymentMethod.processPayment();  // Calls the appropriate payment method
    }
};

int main() {
    PaymentProcessor processor;
    CreditCard creditCard;
    PayPal payPal;
    UPI upi;

    processor.process(creditCard);
    processor.process(payPal);
    processor.process(upi);

    // To add a new payment method like Bitcoin, we don't need to modify PaymentProcessor
    return 0;
}

