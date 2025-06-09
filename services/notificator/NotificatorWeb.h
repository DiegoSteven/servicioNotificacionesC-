#pragma once
#include "Notificator.h"
#include "../services/NotificationFormatter.h"
#include <iostream>

class NotificatorWeb : public Notificator {
private:
    NotificationFormatter* formatter;

public:
    NotificatorWeb(NotificationFormatter* formatter) : formatter(formatter) {}

    std::string getType() const override {
        return "web";
    }

    void send(const Notification& notification, const UserDTO& user, const EventDTO& event, const PositionDTO* position) override {
        NotificationMessage message = formatter->format(notification, user, event, position);

        std::cout << "📡 [WEB Notification]\n";
        std::cout << "Usuario: " << user.email << "\n";
        std::cout << "Asunto: " << message.subject << "\n";
        std::cout << "Mensaje:\n" << message.body << "\n";
        std::cout << "-------------------------------\n";
    }
};
