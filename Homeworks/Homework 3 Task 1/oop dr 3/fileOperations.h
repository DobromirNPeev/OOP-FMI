#pragma once
#include "Set.h"
#include <fstream>
#include "SetCollection.h"
#include "MyString.h"
#include "RegularSet.h"
#include "CriteriaSet.h"
#include "Union.h"
#include "Intersection.h"
#include "DivisibleByNone.h"
#include "DivisibleByExactlyOne.h"


Vector<int> readIntegersFromFile(std::ifstream& ifs);

//https://github.com/GeorgiTerziev02/FMI/blob/main/Object%20Oriented%20Programming/Homework/FMIKindle/FMIKindle/fileOperations.cpp
MyString readStringFromFile(std::ifstream& file);

Set* readSetFile(const char* filenName);