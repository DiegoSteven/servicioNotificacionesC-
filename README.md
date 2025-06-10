
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
```

---

## 🔧 Compilar el proyecto

```bash
git clone <repo-url> NotificationService
cd NotificationService
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j$(nproc)
```

---

## 🐳 Configuración de Base de Datos con Docker

### Levantar PostgreSQL y pgAdmin

```bash
cd notificationsBaseDocker
docker-compose up -d
```

Esto iniciará:
- **PostgreSQL**: Puerto 5432 (usuario: `root`, contraseña: `root`, base de datos: `notifications`)
- **pgAdmin**: Puerto 5050 (email: `admin@admin.com`, contraseña: `admin`)

### Configurar esquema de base de datos

```bash
# Copiar archivo SQL al contenedor
docker cp notifications_postgres.sql postgres-notifications:/notifications_postgres.sql

# Ejecutar SQL en el contenedor
docker exec -it postgres-notifications bash
psql -U root -d notifications -f /notifications_postgres.sql
```

---

## ▶️ Ejecutar el proyecto

```bash
# Desde el directorio build/
./main
```

El servicio se ejecutará en **http://localhost:18080**

---

## 📡 API Endpoints

### GET /api/notifications
Obtiene todas las notificaciones del usuario autenticado.

**Headers requeridos:**
- `Cookie: JSESSIONID=<session-id>`

**Respuesta:**
```json
[
  {
    "id": 1,
    "type": "deviceOffline",
    "description": "Dispositivo desconectado",
    "notificators": "web,mail",
    "always": false,
    "calendarId": null,
    "commandId": null,
    "attributes": {}
  }
]
```

---

## 🔧 Configuración

### Variables de conexión
El servicio se conecta por defecto a:
- **Base de datos**: `localhost:5432/notifications` (usuario: `root`, contraseña: `root`)
- **Puerto del servicio**: `18080`
- **API externa**: `192.168.100.81:8082` (configurable en `utils/ApiClientService.h`)

### Autenticación
El servicio utiliza cookies de sesión (`JSESSIONID`) para autenticar usuarios contra un backend externo en el puerto 8082.

---

## 🏗️ Arquitectura

```
NotificationService/
├── main.cpp                    # Punto de entrada
├── controller/
│   ├── NotificationRoutes.h    # Definición de rutas
│   └── NotificationRoutes.cpp  # Implementación de endpoints
├── database/
│   └── Database.cpp           # Conexión a PostgreSQL
├── services/
│   └── NotificationService.h  # Lógica de negocio
├── utils/
│   ├── SessionUtil.h          # Manejo de sesiones
│   └── ApiClientService.h     # Cliente HTTP para APIs externas
└── notificationsBaseDocker/
    └── docker-compose.yml     # Configuración de PostgreSQL
```

---

## 🚀 Desarrollo

### Compilación en modo Debug
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j$(nproc)
```

### Compilación en modo Release
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j$(nproc)
```


