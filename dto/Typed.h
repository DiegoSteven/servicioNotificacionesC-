#pragma once
#include <string>

struct Typed {
    std::string type;

    Typed() = default;

    Typed(const std::string& type)
        : type(type) {}
};
