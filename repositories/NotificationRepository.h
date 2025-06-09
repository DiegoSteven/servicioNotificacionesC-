#pragma once
#include <vector>
#include "../models/Notification.h"
#include <pqxx/pqxx>

class NotificationRepository {
public:

    static std::vector<Notification> findByType(pqxx::connection& conn, const std::string& type) {
        std::vector<Notification> result;
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(
            "SELECT * FROM tc_notifications WHERE type = $1",
            type
        );

        for (const auto& row : r) {
            result.push_back(Notification::fromRow(row));
        }

        return result;
    }

    static std::vector<Notification> findByTypeAndAlwaysTrue(pqxx::connection& conn, const std::string& type) {
        std::vector<Notification> result;
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(
            "SELECT * FROM tc_notifications WHERE type = $1 AND always = true",
            type
        );

        for (const auto& row : r) {
            result.push_back(Notification::fromRow(row));
        }

        return result;
    }

    static std::vector<Notification> findByUserId(pqxx::connection& conn, long userId) {
        std::vector<Notification> result;
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(R"(
            SELECT n.* FROM tc_notifications n
            INNER JOIN tc_user_notification un ON n.id = un.notificationid
            WHERE un.userid = $1
        )", userId);

        for (const auto& row : r) {
            result.push_back(Notification::fromRow(row));
        }

        return result;
    }

    static std::vector<Notification> findByDeviceId(pqxx::connection& conn, long deviceId) {
        std::vector<Notification> result;
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(R"(
            SELECT n.* FROM tc_notifications n
            INNER JOIN tc_device_notification dn ON n.id = dn.notificationid
            WHERE dn.deviceid = $1
        )", deviceId);

        for (const auto& row : r) {
            result.push_back(Notification::fromRow(row));
        }

        return result;
    }

    static std::vector<Notification> findByGroupId(pqxx::connection& conn, long groupId) {
        std::vector<Notification> result;
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(R"(
            SELECT n.* FROM tc_notifications n
            INNER JOIN tc_group_notification gn ON n.id = gn.notificationid
            WHERE gn.groupid = $1
        )", groupId);

        for (const auto& row : r) {
            result.push_back(Notification::fromRow(row));
        }

        return result;
    }

    static bool isLinkedToUser(pqxx::connection& conn, long userId, long notificationId) {
        pqxx::work txn(conn);

        pqxx::result r = txn.exec_params(R"(
            SELECT EXISTS (
                SELECT 1 FROM tc_user_notification
                WHERE userid = $1 AND notificationid = $2
            )
        )", userId, notificationId);

        return r[0][0].as<bool>();
    }
};
