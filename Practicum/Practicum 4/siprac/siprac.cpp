//Задача 1
#include <iostream>

class Product {
    unsigned barcode;
    unsigned quantity;
    double price;
    bool isBarcodeValid(unsigned barcode) const{
        return barcode >= 0 && barcode <= 255;
    }
public:
    Product(unsigned barcode,unsigned quantity,double price){
        setBarcode(barcode);
        setQuantity(quantity);
        setPrice(price);
    }
    void setBarcode(unsigned barcode) {
        if (isBarcodeValid(barcode)) {
            this->barcode = barcode;
        }
        else {
            this->barcode = 0;
        }
    }
    void setQuantity(unsigned quantity) {
        this->quantity = quantity;
    }
    void setPrice(double price) {
        this->price = price;
    }
    unsigned getBarcode() const{
        return barcode;
    }
    unsigned getQuantity() const{
        return quantity;
    }
    double getPrice() const{
        return price;
    }
};
int main()
{
    Product p(300,25,12.46);
    std::cout << p.getBarcode() << " " << p.getQuantity()<<" " << p.getPrice();
}