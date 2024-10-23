#include <iostream>

// VIOLATION

// Bloated interface
class PrinterInterface {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
    virtual ~PrinterInterface() {}
};

// InkJetPrinter doesn't need to implement fax(), but is forced to
class InkJetPrinter : public PrinterInterface {
public:
    void print() override {
        std::cout << "Printing using InkJet." << std::endl;
    }

    void scan() override {
        std::cout << "Scanning using InkJet." << std::endl;
    }

    void fax() override {
        std::cout << "I don't support faxing!" << std::endl;
    }
};

int main() {
    InkJetPrinter printer;
    printer.print();
    printer.scan();
    printer.fax();  // Violates ISP: Forced to implement fax()
    
    return 0;
}






// FIXED

// // Separate interfaces for specific functionalities
// class Printable {
// public:
//     virtual void print() = 0;
//     virtual ~Printable() {}
// };

// class Scannable {
// public:
//     virtual void scan() = 0;
//     virtual ~Scannable() {}
// };

// class Faxable {
// public:
//     virtual void fax() = 0;
//     virtual ~Faxable() {}
// };

// // InkJetPrinter now only implements Printable and Scannable
// class InkJetPrinter : public Printable, public Scannable {
// public:
//     void print() override {
//         std::cout << "Printing using InkJet." << std::endl;
//     }

//     void scan() override {
//         std::cout << "Scanning using InkJet." << std::endl;
//     }
// };

// int main() {
//     InkJetPrinter printer;
//     printer.print();
//     printer.scan();
    
//     // printer.fax(); // This won't compile, which is correct

//     return 0;
// }

