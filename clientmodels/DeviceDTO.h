#pragma once
#include <string>
#include <map>
#include <optional>
#include "crow.h"

struct DeviceDTO {
    long id = 0;
    std::map<std::string, crow::json::rvalue> attributes;
    long groupId = 0;
    long calendarId = 0;
    std::string name;
    std::string uniqueId;
    std::string status;
    long positionId = 0;
    std::string phone;
    std::string model;
    std::string contact;
    std::string category;
    bool disabled = false;
    std::optional<std::string> expirationTime;
    std::optional<std::string> lastUpdate;
};
