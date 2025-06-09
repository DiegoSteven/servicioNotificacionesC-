#pragma once
#include <string>
#include <map>
#include "crow.h"
#include <pqxx/pqxx>
#include "../utils/AttributesConverter.h"

struct Notification
{
    long id = 0;
    std::map<std::string, crow::json::rvalue> attributes;
    std::string description;
    long calendarId = 0;
    long commandId = 0;
    std::string type;
    std::string notificators;
    bool always = false;

    // Método para cargar desde pqxx::row
    static Notification fromRow(const pqxx::row &row)
    {
        Notification n;
        n.id = row["id"].as<long>();

        n.description = row["description"].is_null() ? "" : row["description"].c_str();
        n.calendarId = row["calendarid"].is_null() ? 0 : row["calendarid"].as<long>();
        n.commandId = row["commandid"].is_null() ? 0 : row["commandid"].as<long>();
        n.type = row["type"].is_null() ? "" : row["type"].c_str();
        n.notificators = row["notificators"].is_null() ? "" : row["notificators"].c_str();
        n.always = row["always"].is_null() ? false : row["always"].as<bool>();

        // Manejo de attributes si no es null
        if (!row["attributes"].is_null())
        {
            n.attributes = AttributesConverter::fromJson(row["attributes"].c_str());
        }
        else
        {
            n.attributes = {};
        }

        return n;
    }

    // Método para convertir a string JSON para INSERT/UPDATE
    std::string attributesJson() const
    {
        return AttributesConverter::toJson(attributes);
    }
};
