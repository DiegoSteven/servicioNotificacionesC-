# Imagen base
FROM debian:stable-slim

# Instalar dependencias
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    && apt-get clean

# Crear carpeta de trabajo
WORKDIR /app

# Copiar archivos al contenedor
COPY . /app

# Crear carpeta de build
RUN mkdir -p build && cd build && \
    cmake .. && \
    make

# Comando por defecto al iniciar el contenedor
CMD ["./build/main"]
