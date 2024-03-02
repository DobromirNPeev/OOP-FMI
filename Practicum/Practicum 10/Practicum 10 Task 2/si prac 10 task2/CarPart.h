#pragma once
#include <iostream>
#pragma warning (disable:4996)
class CarPart {
    static unsigned idCounter;
    unsigned id;
    char* manufacturer;
    char* desc;
public:
    CarPart(const char* manufacturer, const char* desc);
    CarPart();
    CarPart(const CarPart& other);
    CarPart& operator=(const CarPart& other);
    ~CarPart();
    CarPart(CarPart&& other) noexcept;
    CarPart& operator=(CarPart&& other) noexcept;
    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
private:
    void moveFrom(CarPart&& other);
    void copyFrom(const CarPart& other);
    void free();
};
std::ostream& operator<<(std::ostream& os, const CarPart& part);