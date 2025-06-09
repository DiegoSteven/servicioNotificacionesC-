#pragma once
#include <string>
#include <map>
#include <optional>
#include "crow.h"

struct PositionDTO {
    long id = 0;
    std::map<std::string, crow::json::rvalue> attributes;
    long deviceId = 0;
    std::string protocol;
    std::optional<std::string> serverTime;
    std::optional<std::string> deviceTime;
    std::optional<std::string> fixTime;
    bool valid = false;
    double latitude = 0;
    double longitude = 0;
    double altitude = 0;
    double speed = 0;
    double course = 0;
    double accuracy = 0;
    std::string address;
    std::optional<bool> outdated;
    crow::json::rvalue network;
    crow::json::rvalue geofenceIds;
};
