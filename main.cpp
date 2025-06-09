#include "crow.h"
#include <pqxx/pqxx>
#include "../controller/NotificationRoutes.h"

int main() {
    crow::SimpleApp app;
    pqxx::connection conn("dbname=notifications user=root password=root host=localhost port=5432");

    registerNotificationRoutes(app, conn);

    app.port(18080).multithreaded().run();
}
