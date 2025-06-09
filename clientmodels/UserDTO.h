#pragma once
#include <string>
#include <map>
#include <optional>
#include "crow.h"

struct UserDTO {
    long id = 0;
    std::map<std::string, crow::json::rvalue> attributes;
    std::string name;
    std::string login;
    std::string email;
    std::string phone;
    bool readonly = false;
    bool administrator = false;
    std::string map;
    double latitude = 0;
    double longitude = 0;
    int zoom = 0;
    std::string coordinateFormat;
    bool disabled = false;
    std::optional<std::string> expirationTime;
    int deviceLimit = 0;
    int userLimit = 0;
    bool deviceReadonly = false;
    bool limitCommands = false;
    bool disableReports = false;
    bool fixedEmail = false;
    std::string poiLayer;
    std::string totpKey;
    bool temporary = false;
    std::string password;
};
