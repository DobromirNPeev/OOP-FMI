#pragma once
#include <iostream>
#include "Fileh.h"

enum class SortOptions {
    name, timeOfCreation, timeOfModification, size
};

class TextFilesManager {
    File* files;
    unsigned count = 0;
    unsigned maxSizeCount = 0;
    unsigned getCount() const;
    int getIndexOfFile(const char* fileName) const;
    void copyFrom(const TextFilesManager& other);
    void free();
    bool compare(SortOptions desiredSort, const File& lhs, const File& rhs) const;
    unsigned innerPart(size_t i, enum class SortOptions desiredSort, unsigned min) const;
public:
    TextFilesManager(unsigned n);
    //The Big Four
    TextFilesManager() = default;
    TextFilesManager(const TextFilesManager& other);
    TextFilesManager& operator=(const TextFilesManager other);
    ~TextFilesManager();
    //
        void addFile(const char* fileName, size_t size,
            unsigned hourOfCreation, unsigned minsOfCreation, unsigned secsofCreation,
            unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearfCreation,
            const char* accesRights);
        void editFile(const char* fileName, const char* content,
            unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
            unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight);
        void addInFile(const char* fileName, const char* content,
            unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
            unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight);
        void deleteFile(const char* fileName);
        void changeRights(const char* fileName, char accessRight, char typeOfRight);
        void printFile(const char* fileName, char accessRight) const;
        void printFileInfo(const char* fileName) const;
        void sort(enum class SortOptions desiredSort) const;
        void print() const;
};