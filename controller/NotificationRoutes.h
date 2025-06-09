#pragma once
#include "crow.h"
#include <pqxx/pqxx>

void registerNotificationRoutes(crow::SimpleApp& app, pqxx::connection& conn);
