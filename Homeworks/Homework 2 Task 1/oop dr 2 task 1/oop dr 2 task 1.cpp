#include <iostream>
#include "MyString.h"

int main()
{
        MyString str("Cody");
        MyString str1("Miloshe");
        MyString str2(str);
        MyString str3("GeorgiDjanavarov");
        MyString str4(str);
        str += str1;
        MyString str5 = str + str1;
        //str3 = str1;
        std::cout << str3.substr(1,9);
        //std::cout<<str5.substr(12, 5);
        //std::cin >> str3;
}