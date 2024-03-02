#pragma once
#include "CarPart.h"
class Accumulator : public CarPart {
    size_t capacity;
    char* batterryId;
public:
    Accumulator(size_t capacity,const char* batteryId, const char* manufacturer, const char* desc);
    friend std::ostream& operator<<(std::ostream& os, const Accumulator& acc);
};
std::ostream& operator<<(std::ostream& os, const Accumulator& acc);