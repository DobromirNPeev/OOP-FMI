#pragma once
#include "CarPart.h"
class Engine : public CarPart {
    size_t horsePower;
public:
    Engine(size_t horsePower, const char* manufacturer, const char* desc);
    size_t getHorsePower() const;
    friend std::ostream& operator<<(std::ostream& os, const Engine& engine);
};
std::ostream& operator<<(std::ostream& os, const Engine& engine);