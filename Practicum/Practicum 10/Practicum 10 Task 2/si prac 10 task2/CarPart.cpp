#include "CarPart.h"

unsigned CarPart::idCounter = 0;

CarPart::CarPart(const char* manufacturer, const char* desc) {
    this->manufacturer = new char[strlen(manufacturer) + 1];
    this->desc = new char[strlen(desc) + 1];
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->desc, desc);
    id = idCounter++;
}
CarPart::CarPart() :manufacturer(nullptr), desc(nullptr), id(idCounter++) {};
CarPart::CarPart(const CarPart& other) {
    copyFrom(other);
}
CarPart& CarPart::operator=(const CarPart& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}
CarPart::~CarPart() {
    free();
}
CarPart::CarPart(CarPart&& other) noexcept {
    moveFrom(std::move(other));
}
CarPart& CarPart::operator=(CarPart&& other) noexcept {
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, const CarPart& part) {
    os << "(" << part.id << ")" << " by " << part.manufacturer << " - " << part.desc << " - ";
    return os;
}
void CarPart::moveFrom(CarPart&& other) {
        manufacturer = other.manufacturer;
        other.manufacturer = nullptr;

        desc = other.desc;
        other.desc = nullptr;

        id = other.id;
    }
    void CarPart::copyFrom(const CarPart& other) {
        manufacturer = new char[strlen(other.manufacturer) + 1];
        desc = new char[strlen(other.desc) + 1];
        strcpy(manufacturer, other.manufacturer);
        strcpy(desc, other.desc);
        id = idCounter++;
    }
    void CarPart::free() {
        delete[] manufacturer;
        delete[] desc;
        manufacturer = desc = nullptr;
    }