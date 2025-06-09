#pragma once
#include <string>
#include <map>
#include <optional>
#include "crow.h"

struct EventDTO {
    long id = 0;
    std::string type;
    long deviceId = 0;
    long positionId = 0;
    long geofenceId = 0;
    long maintenanceId = 0;
    std::optional<std::string> eventTime;
    std::map<std::string, crow::json::rvalue> attributes;
    std::optional<std::string> message;
};
