#include <iostream>

// VIOLATION

// // Email service class
// class EmailService {
// public:
//     void sendEmail(const std::string& message) {
//         std::cout << "Sending email: " << message << std::endl;
//     }
// };

// // SMS service class
// class SMSService {
// public:
//     void sendSMS(const std::string& message) {
//         std::cout << "Sending SMS: " << message << std::endl;
//     }
// };

// // NotificationService directly depends on EmailService and SMSService (violation)
// class NotificationService {
// public:
//     void sendEmailNotification(const std::string& message) {
//         EmailService emailService;
//         emailService.sendEmail(message);
//     }

//     void sendSMSNotification(const std::string& message) {
//         SMSService smsService;
//         smsService.sendSMS(message);
//     }
// };

// int main() {
//     NotificationService notificationService;
//     notificationService.sendEmailNotification("Hello via Email!");  // Email
//     notificationService.sendSMSNotification("Hello via SMS!");      // SMS

//     return 0;
// }





// FIXED

// Abstraction: NotificationChannel interface
class NotificationChannel {
public:
    virtual void send(const std::string& message) const = 0;  // Pure virtual function
    virtual ~NotificationChannel() {}
};

// EmailService implements NotificationChannel
class EmailService : public NotificationChannel {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

// SMSService implements NotificationChannel
class SMSService : public NotificationChannel {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

// New PushNotification implements NotificationChannel
class PushNotification : public NotificationChannel {
public:
    void send(const std::string& message) const override {
        std::cout << "Sending push notification: " << message << std::endl;
    }
};

// NotificationService now depends on the abstraction (NotificationChannel)
class NotificationService {
public:
    void sendNotification(const NotificationChannel& channel, const std::string& message) const {
        channel.send(message);  // No need to modify this for new notification methods
    }
};

int main() {
    EmailService emailService;
    SMSService smsService;
    PushNotification pushNotification;  // New push notification service

    NotificationService notificationService;
    notificationService.sendNotification(emailService, "Hello via Email!");  // Email
    notificationService.sendNotification(smsService, "Hello via SMS!");      // SMS
    notificationService.sendNotification(pushNotification, "Hello via Push!"); // Push (new!)

    return 0;
}
