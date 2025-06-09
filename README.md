# NotificationService (WCF Microservice en C++)

Microservicio de notificaciones desarrollado en C++ usando [Crow](https://github.com/CrowCpp/Crow), PostgreSQL y Boost. Diseñado para ejecutarse en entornos tipo Linux (preferiblemente **WSL2**) y con integración sencilla a otros microservicios como parte de un sistema mayor.

---

## 🚀 Requisitos

- Linux / WSL2 (Ubuntu 20.04 o superior)
- CMake ≥ 3.15
- GCC ≥ 10
- PostgreSQL ≥ 13
- Boost ≥ 1.74
- ASIO
- Crow (incluido en el repositorio como submódulo o descargado)
- Docker (opcional)

---

## 🔧 Instalación del entorno (WSL2)

```bash
sudo apt update && sudo apt install -y \
    build-essential cmake libpq-dev \
    libboost-system-dev libboost-thread-dev \
    libboost-chrono-dev libboost-dev \
    libasio-dev
---

## 🔧 compilar el proyecto
git clone <repo-url> NotificationService
cd NotificationService
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j$(nproc)
