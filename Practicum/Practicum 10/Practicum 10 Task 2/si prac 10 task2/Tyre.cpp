#include "Tyre.h"

Tyre::Tyre(double width, double profile, double diam, const char* manufacturer, const char* desc) : CarPart(manufacturer, desc) {
    setValue(width, profile, diam);
}
std::ostream& operator<<(std::ostream& os, const Tyre& tyre) {
    os << (const CarPart&)tyre << tyre.width << "/" << tyre.profile << "R" << tyre.diam << std::endl;
    return os;
}
void Tyre::setValue(double width, double profile, double diam) {
    if ((width < 155 || width>365) || (profile < 30 || profile>80) || (diam < 13 || diam>21)) {
        throw std::out_of_range("Invalid ranges");
    }
    this->width = width;
    this->profile = profile;
    this->diam = diam;
}