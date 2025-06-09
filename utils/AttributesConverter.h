#pragma once
#include <string>
#include <map>
#include <sstream>
#include "crow.h"

class AttributesConverter {
public:
    static std::string toJson(const std::map<std::string, crow::json::rvalue>& attributes) {
        std::ostringstream json;
        json << "{";
        bool first = true;

        for (const auto& [key, value] : attributes) {
            if (!first) json << ",";
            json << "\"" << key << "\":";

            // serializar según tipo
            switch (value.t()) {
                case crow::json::type::Null:
                    json << "null";
                    break;
                case crow::json::type::False:
                    json << "false";
                    break;
                case crow::json::type::True:
                    json << "true";
                    break;
                case crow::json::type::Number:
                    json << value.i();  // entero
                    break;
                case crow::json::type::String:
                    json << "\"" << value.s() << "\"";
                    break;
                default:
                    json << "\"<no-serializable>\"";  // placeholder
                    break;
            }

            first = false;
        }

        json << "}";
        return json.str();
    }

    static std::map<std::string, crow::json::rvalue> fromJson(const std::string& jsonStr) {
        auto parsed = crow::json::load(jsonStr);
        std::map<std::string, crow::json::rvalue> map;

        if (!parsed) return map;

        for (const auto& key : parsed.keys()) {
            map[key] = parsed[key];
        }
        return map;
    }
};
