#pragma once
#include <string>
#include <sstream>
#include "../models/NotificationMessage.h"
#include "../models/Notification.h"
#include "../clientmodels/UserDTO.h"
#include "../clientmodels/EventDTO.h"
#include "../clientmodels/DeviceDTO.h"
#include "../clientmodels/PositionDTO.h"

class NotificationFormatter {
public:

    NotificationMessage format(
        const Notification& notification,
        const UserDTO& user,
        const EventDTO& event,
        const PositionDTO* position) const
    {
        std::ostringstream body;
        body << "📢 Evento: " << event.type;

        if (!user.email.empty()) {
            body << "\n👤 Usuario: " << user.email;
        }

        if (position != nullptr) {
            body << "\n📍 Ubicación: " << position->latitude << ", " << position->longitude;
        }

        if (!notification.description.empty()) {
            body << "\n📝 Descripción: " << notification.description;
        }

        return NotificationMessage("Notificación: " + event.type, body.str());
    }

    static std::string formatMessage(
        const EventDTO& event,
        const DeviceDTO& device,
        const PositionDTO* position)
    {
        std::ostringstream body;

        body << "📢 Evento: " << event.type;

        if (!device.name.empty()) {
            body << "\n📱 Dispositivo: " << device.name;
            body << "\n🔢 Unique ID: " << device.uniqueId;
        }

        if (position != nullptr) {
            body << "\n📍 Ubicación: " << position->latitude << ", " << position->longitude;
            body << "\n🚀 Velocidad: " << position->speed << " nudos";
        }

        if (event.eventTime.has_value()) {
            body << "\n📅 Fecha evento: " << event.eventTime.value();
        }

        return body.str();
    }
};
