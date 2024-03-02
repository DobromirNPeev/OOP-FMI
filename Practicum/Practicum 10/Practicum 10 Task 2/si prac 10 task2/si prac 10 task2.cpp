#include "Car.h"

int main()
{
    Accumulator acc(55, "89", "Ford", "Good acc");
    FuelTank fuelt(0.2, "Honda", "Large tank");
    Engine eng(150, "Yamaha", "New engine");
    Tyre tyre(200, 45, 15.5,"Volfswagen","Winter tyre");
    Tyre tyre1(200, 45, 15.5,"Volfswagen","Winter tyre");
    Tyre tyre2(200, 45, 15.5,"Volfswagen","Winter tyre");
    Tyre tyre3(200, 45, 15.5,"Volfswagen","Winter tyre");
    Tyre tyres[4] = { tyre,tyre1,tyre2,tyre3 };
    Car car(fuelt, eng, tyres, acc, 1000);
    Accumulator acc1(70, "LOL", "Lamborghini", "Very good acc");
    FuelTank fuelt1(0.3, "Unknown", "Large tank");
    Engine eng1(175, "Kia", "New engine");
    Tyre tyre10(156, 45, 15.5, "BMW", "Winter tyre");
    Tyre tyre11(156, 45, 15.5, "BMW", "Winter tyre");
    Tyre tyre12(156, 45, 15.5, "BMW", "Winter tyre");
    Tyre tyre13(156, 45, 15.5, "BMW", "Winter tyre");
    Tyre tyres1[4] = { tyre10,tyre11,tyre12,tyre13 };
    Car car1(fuelt1, eng1, tyres1, acc1,1000);
    try{
        car.getTank().useFuel(5);
    }
    catch (insufficient_fuel_error& exc) {
        std::cout << exc.what();
    }
    /*car.drive(55);
    car.getTank().loadFuel(25);
    std::cout<<*(dragRace(&car, &car1));*/
    //std::cout << car;
}