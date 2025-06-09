#pragma once
#include <vector>
#include <memory>
#include "../models/Notification.h"
#include "../repositories/NotificationRepository.h"
#include "../utils/SessionUtil.h"
#include <pqxx/pqxx>

class NotificationService {
public:

    // Obtener todas las notificaciones
    static std::vector<Notification> getAll(pqxx::connection& conn) {
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT * FROM tc_notifications");

        std::vector<Notification> list;
        for (const auto& row : r) {
            list.push_back(Notification::fromRow(row));
        }
        return list;
    }

    // Crear notificación y vincularla al usuario
    static void create(
        pqxx::connection& conn,
        const Notification& notification,
        long userId)
    {
        pqxx::work txn(conn);

        // Ajustar campos nulos
        long calendarId = notification.calendarId == 0 ? -1 : notification.calendarId;
        long commandId  = notification.commandId == 0 ? -1 : notification.commandId;

        pqxx::result r = txn.exec_params(R"(
            INSERT INTO tc_notifications (description, type, commandid, calendarid, notificators, always, attributes)
            VALUES ($1, $2, NULLIF($3, -1), NULLIF($4, -1), $5, $6, $7)
            RETURNING id
        )",
            notification.description,
            notification.type,
            commandId,
            calendarId,
            notification.notificators,
            notification.always,
            notification.attributesJson()
        );

        long newId = r[0][0].as<long>();

        txn.exec_params(R"(
            INSERT INTO tc_user_notification (userid, notificationid)
            VALUES ($1, $2)
        )", userId, newId);

        txn.commit();
    }
};
