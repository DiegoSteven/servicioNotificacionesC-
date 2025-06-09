#pragma once
#include "Notificator.h"
#include <iostream>

class NotificatorCommand : public Notificator {
public:
    std::string getType() const override {
        return "command";
    }

    void send(const Notification& notification, const UserDTO& user, const EventDTO& event, const PositionDTO* position) override {
        if (notification.commandId <= 0) {
            std::cerr << "❌ commandId no definido. No se ejecuta ningún comando.\n";
            return;
        }

        std::cout << "⚙️ Ejecutando comando con ID: " << notification.commandId
                  << " para el dispositivo ID: " << event.deviceId << "\n";
    }
};
