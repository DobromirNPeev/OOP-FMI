#include "Waffle.h"

void Waffle::setName(const char* name) {
    if (strlen(name) > MAXSIZE || name==nullptr) {
        strcpy(this->name, "");
        return;
    }
    strcpy(this->name, name);
}
void Waffle::setWeight(double weight) {
    if (weight < 0.0) {
        this->weight = 0.0;
    }
    this->weight = weight;
}
void Waffle::setPriceForBusiness(double priceForBusiness) {
    if (priceForBusiness < 0.0) {
        this->priceForBusiness = 0.0;
        return;
    }
    this->priceForBusiness = priceForBusiness;
}
void Waffle::setPriceForClient(double priceForClient) {
    if (priceForClient < 0.0) {
        this->priceForClient = 0.0;
        return;
    }
    this->priceForClient = 0.0;
}
double Waffle::getPriceForBusiness() const {
    return this->priceForBusiness;
}
const char* Waffle::getWaffleName() const {
    return this->name;
}
double Waffle::getPriceForClient() const {
    return this->priceForClient;
}