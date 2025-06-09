#pragma once
#include "../models/Notification.h"
#include "../models/NotificationMessage.h"
#include "../clientmodels/UserDTO.h"
#include "../clientmodels/EventDTO.h"
#include "../clientmodels/PositionDTO.h"

class Notificator {
public:
    virtual std::string getType() const = 0;

    virtual void send(
        const Notification& notification,
        const UserDTO& user,
        const EventDTO& event,
        const PositionDTO* position) = 0;

    virtual void send(
        const UserDTO& user,
        const NotificationMessage& message,
        const EventDTO* event = nullptr,
        const PositionDTO* position = nullptr) {
        throw std::runtime_error("Método no implementado en este notificator");
    }

    virtual ~Notificator() = default;
};
