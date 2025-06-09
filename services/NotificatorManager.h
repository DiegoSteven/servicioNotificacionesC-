#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include "../services/notificator/Notificator.h"

class NotificatorManager {
private:
    std::map<std::string, std::shared_ptr<Notificator>> notificators;

public:
    NotificatorManager() = default;

    void registerNotificator(const std::shared_ptr<Notificator>& notificator) {
        notificators[notificator->getType()] = notificator;
    }

    std::shared_ptr<Notificator> get(const std::string& type) const {
        auto it = notificators.find(type);
        if (it == notificators.end()) {
            throw std::runtime_error("Notificator not found: " + type);
        }
        return it->second;
    }

    std::vector<std::string> getAllTypes() const {
        std::vector<std::string> keys;
        for (const auto& [key, _] : notificators) {
            keys.push_back(key);
        }
        return keys;
    }
};
