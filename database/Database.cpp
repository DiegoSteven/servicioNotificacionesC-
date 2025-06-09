#include "Database.h"
#include <pqxx/pqxx>
#include <sstream>  
std::ostringstream os;

std::string comprobarConexion() {
    try {
        pqxx::connection conn("host=localhost port=5432 dbname=notifications user=root password=root");
        pqxx::work txn(conn);
        pqxx::result r = txn.exec("SELECT NOW()");

        
        os << "Conexión exitosa. Fecha/hora del servidor: " << r[0][0].c_str();
        return os.str();  
    } catch (const std::exception& e) {
        return std::string("Error: ") + e.what();
    }
}
