#pragma once
#include "CarPart.h"
class Tyre : public CarPart {
    double width=0;
    double profile=0;
    double diam=0;
public:
    Tyre() = default;
    Tyre(double width, double profile, double diam, const char* manufacturer, const char* desc);
    friend std::ostream& operator<<(std::ostream& os, const Tyre& tyre);
    void setValue(double width, double profile, double diam);
};
std::ostream& operator<<(std::ostream& os, const Tyre& tyre);
