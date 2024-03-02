#include "fileOperations.h"

Vector<int> readIntegersFromFile(std::ifstream& ifs) {
    Vector<int> curr;
    size_t size = 0;
    ifs.read((char*)&size, sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        int number = 0;
        ifs.read((char*)&number, sizeof(number));
        curr.pushBack(number);
    }
    return curr;
}

MyString readStringFromFile(std::ifstream& file) {
    int stringLength;
    file.read((char*)&stringLength, sizeof(int));
    char* str = new char[stringLength + 1];
    file.read(str, stringLength);
    str[stringLength] = '\0';

    return str;
}

Set* readSetFile(const char* filenName) {
    std::ifstream ifs(filenName, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) {
        throw std::logic_error("Couldn't open");
    }
    unsigned short n = 0;
    ifs.read((char*)&n, sizeof(short));
    if (n > 32) {
        ifs.close();
        throw std::invalid_argument("N larger than 32");
    }
    unsigned short t = 0;
    ifs.read((char*)&t, sizeof(short));
    if (t == 0) {
        return new RegularSet(readIntegersFromFile(ifs));
    }
    else if (t == 1) {

        Vector<int> numbers = readIntegersFromFile(ifs);
        Set* set = new CriteriaSet(DivisableByNone(numbers));
        ifs.close();
        return set;
    }
    else if (t == 2) {
        Vector<int> numbers = readIntegersFromFile(ifs);
        Set* set = new CriteriaSet(DivisibleByExactlyOne(numbers));
        ifs.close();
        return set;
    }
    else if (t == 3) {
        SetCollection sets;
        for (size_t i = 0; i < n; i++)
        {
            Set* curr = readSetFile(readStringFromFile(ifs).c_str());
            sets.addSet(*curr);
            delete curr;
        }
        ifs.close();
        return new Union(sets);
    }
    else if (t == 4) {
        SetCollection sets;
        for (size_t i = 0; i < n; i++)
        {
            Set* curr = readSetFile(readStringFromFile(ifs).c_str());
            sets.addSet(*curr);
            delete curr;
        }
        ifs.close();
        return new Intersection(sets);
    }
    else {
        ifs.close();
        throw std::invalid_argument("Invalid T");
    }
}