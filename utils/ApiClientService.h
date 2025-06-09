#pragma once
#include <string>
#include <iostream>
#include <httplib.h>
#include "SessionUtil.h"

class ApiClientService {
public:
    static crow::json::rvalue getJsonFrom(const std::string& url, const crow::request& req) {
        std::string sessionCookie = SessionUtil::extractSessionCookie(req);

        // Usa la IP real de Windows (ajusta si cambia)
        httplib::Client client("192.168.100.81", 8082);  // ← ajusta a tu IP
        httplib::Headers headers = {
            { "Cookie", sessionCookie },
            { "Accept", "application/json" }
        };

        std::cout << "GET " << url << std::endl;

        auto res = client.Get(url.c_str(), headers);
        if (!res) {
            throw std::runtime_error("Sin respuesta al consumir " + url);
        }
        if (res->status != 200) {
            throw std::runtime_error("Error HTTP " + std::to_string(res->status) + " al consumir " + url);
        }

        auto json = crow::json::load(res->body);
        if (!json) {
            throw std::runtime_error("Respuesta inválida (JSON) al consumir " + url);
        }

        return json;
    }

    static crow::json::rvalue getDeviceById(const crow::request& req, long deviceId) {
        return getJsonFrom("/api/devices/" + std::to_string(deviceId), req);
    }

    static crow::json::rvalue getUserById(const crow::request& req, long userId) {
        return getJsonFrom("/api/users/" + std::to_string(userId), req);
    }

    static crow::json::rvalue getEventById(const crow::request& req, long eventId) {
        return getJsonFrom("/api/events/" + std::to_string(eventId), req);
    }

    static crow::json::rvalue getPositions(const crow::request& req) {
        return getJsonFrom("/api/positions", req);
    }
};
