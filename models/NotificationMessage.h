#pragma once
#include <string>

struct NotificationMessage {
    std::string subject;
    std::string body;

    NotificationMessage(const std::string& s, const std::string& b)
        : subject(s), body(b) {}
};
