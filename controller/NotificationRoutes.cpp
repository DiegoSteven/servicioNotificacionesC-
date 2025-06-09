#include "NotificationRoutes.h"
#include "../utils/SessionUtil.h"
#include "../repositories/NotificationRepository.h"

void registerNotificationRoutes(crow::SimpleApp &app, pqxx::connection &conn)
{
    CROW_ROUTE(app, "/api/notifications").methods("GET"_method)([&conn](const crow::request &req)
                                                                {
        try {
            long userId = SessionUtil::extractUserIdFromSession(req);
            auto list = NotificationRepository::findByUserId(conn, userId);

            crow::json::wvalue res;
            int i = 0;

            for (const auto& n : list) {
                res[i]["id"] = n.id;
                res[i]["type"] = n.type;
                res[i]["description"] = n.description;
                res[i]["notificators"] = n.notificators;
                res[i]["always"] = n.always;
                res[i]["calendarId"] = n.calendarId;
                res[i]["commandId"] = n.commandId;

                // Manejo seguro de attributes: nunca null
                if (n.attributes.empty()) {
                    res[i]["attributes"] = crow::json::wvalue::object();  // {}
                } else {
                    crow::json::wvalue attrs;
                    attrs = crow::json::wvalue::object();
                    for (const auto& [key, value] : n.attributes) {
                        attrs[key] = value;
                    }
                    res[i]["attributes"] = std::move(attrs);

                }

                ++i;
            }

            return crow::response(res);
        } catch (const std::exception& e) {
            return crow::response(500, e.what());
        } });
}
