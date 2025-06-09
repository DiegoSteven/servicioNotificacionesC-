#pragma once
#include "Notificator.h"
#include "../services/NotificationFormatter.h"
#include <iostream>

class NotificatorMail : public Notificator {
public:
    std::string getType() const override {
        return "mail";
    }

    void send(const Notification& notification, const UserDTO& user, const EventDTO& event, const PositionDTO* position) override {
        if (user.email.empty()) {
            std::cerr << "❌ Usuario sin email. Notificación ignorada.\n";
            return;
        }

        // Aquí iría el envío real por correo, ahora es solo simulación
        std::cout << "✅ Correo enviado a " << user.email << " (simulado)\n";
    }
};
