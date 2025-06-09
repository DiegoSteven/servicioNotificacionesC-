cmake_minimum_required(VERSION 3.20)
project(NotificationService LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Boost es necesario para Crow
find_package(Boost REQUIRED COMPONENTS system thread chrono)
find_package(PostgreSQL REQUIRED)
# Descargar Crow desde GitHub
include(FetchContent)
FetchContent_Declare(
  crow
  GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
  GIT_TAG v1.2.0
)
FetchContent_MakeAvailable(crow)

# Ejecutable
add_executable(main
    main.cpp
    database/Database.cpp
    controller/NotificationRoutes.cpp
)

# Vincular librerías
target_link_libraries(main
  PRIVATE
    Crow::Crow
    Boost::system
    Boost::thread
    Boost::chrono
    pqxx
    pq
)

target_include_directories(main
  PRIVATE
    ${PostgreSQL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/database
    ${CMAKE_SOURCE_DIR}/external
)
