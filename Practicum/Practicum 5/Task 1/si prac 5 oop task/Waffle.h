#pragma once
#include <iostream>
#pragma warning (disable:4996)

const unsigned MAXSIZE = 21;

class Waffle {
    char name[20] = "";
    double weight = 0.0;
    double priceForBusiness = 0.0;
    double priceForClient = 0.0;
public:
    Waffle() {

    }
    Waffle(const char* name, double weight, double priceForBusiness, double priceForClient) {
        setName(name);
        setWeight(weight);
        setPriceForBusiness(priceForBusiness);
        setPriceForClient(priceForClient);
    }
    void setName(const char* name);
    void setWeight(double weight);
    void setPriceForBusiness(double priceForBusiness);
    void setPriceForClient(double priceForClient);
    double getPriceForBusiness() const;
    double getPriceForClient() const;
    const char* getWaffleName() const;

};
