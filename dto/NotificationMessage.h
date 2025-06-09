#pragma once
#include <string>

struct NotificationMessage {
    std::string subject;
    std::string body;

    NotificationMessage() = default;

    NotificationMessage(const std::string& subject, const std::string& body)
        : subject(subject), body(body) {}
};
