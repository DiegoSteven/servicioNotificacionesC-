#pragma once
#include <string>
#include <iostream>

class MailService {
public:
    void send(const std::string& to, const std::string& subject, const std::string& body) {
        // Simulación de envío de correo
        std::cout << "📧 Enviando correo a: " << to << "\n";
        std::cout << "Asunto: " << subject << "\n";
        std::cout << "Contenido:\n" << body << "\n";
        std::cout << "---------------------------\n";
    }
};
