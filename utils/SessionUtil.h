#pragma once
#include <string>
#include <stdexcept>
#include <iostream>
#include "crow.h"
#include "httplib.h"

class SessionUtil {
public:
    // Extrae la cookie JSESSIONID del header
    static std::string extractSessionCookie(const crow::request& req) {
        std::string cookie = req.get_header_value("Cookie");

        if (cookie.find("JSESSIONID=") == std::string::npos) {
            throw std::runtime_error("Sesión no encontrada (JSESSIONID no presente)");
        }

        std::cout << "🔍 Cookie recibida: " << cookie << std::endl;
        return cookie;
    }

    // Consulta el backend monolítico para extraer el userId desde la sesión
    static long extractUserIdFromSession(const crow::request& req) {
        std::string sessionCookie = extractSessionCookie(req);

        // IMPORTANTE: No uses http://, solo host y puerto
        httplib::Client client("192.168.100.81", 8082);
        httplib::Headers headers = {
            { "Cookie", sessionCookie }
        };

        auto res = client.Get("/api/session", headers);

        if (!res || res->status != 200) {
            std::cerr << "❌ Error al consultar /api/session: "
                      << (res ? std::to_string(res->status) : "sin respuesta") << std::endl;
            throw std::runtime_error("Error consultando sesión");
        }

        auto json = crow::json::load(res->body);
        if (!json || !json.has("id")) {
            throw std::runtime_error("No se pudo extraer ID de usuario desde JSON");
        }

        long userId = json["id"].i();
        std::cout << "✅ ID de usuario extraído: " << userId << std::endl;
        return userId;
    }
};
