#pragma once
#include <iostream>
#include "Date.h"
#include "Time.h"
#pragma warning (disable: 4996)

const unsigned NAMESIZE = 65;
const unsigned CONTENTSIZE = 513;
const unsigned ACCESSSIZE = 10;

class File {
    struct FileTime {
        Date date;
        Time time;
        FileTime();
        FileTime(unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
            unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification) : date(dayOfModification, monthOfModification, yearOfModification), time(hourOfModification, minsOfModification, secsOfModification) {
        }
        bool compare(const FileTime& other) const;
    };
    char fileName[NAMESIZE];
    char content[CONTENTSIZE];
    size_t size;
    FileTime timeOfCreation;
    FileTime timeOfLastModification;
    char accessRight[ACCESSSIZE];
    void writing(unsigned index, const char* content, unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
        unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, const char* command);
    void changingRights(char typeOfRight, unsigned index);
public:
    File();
    File(const char* fileName, const char* content, unsigned size, unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearOfCreation,
        unsigned hoursOfCreation, unsigned minsOfCreation, unsigned secsOfCreation,
        unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification,
        unsigned hoursOfModification, unsigned minsOfModification, unsigned secsOfModification,
        const char* accessRights);
    void setFile(const char* fileName, size_t size,
        unsigned hoursOfCreation, unsigned minsOfCreation, unsigned secsOfCreation,
        unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearOfCreation,
        const char* accessRights);
    void editFile(const char* fileName, const char* content,
        unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
        unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight);
    void addInFile(const char* fileName, const char* content,
        unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
        unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight);
    void changeRights(char accessRight, char typeOfRight);
    void printFile(char accessRight) const;
    void printFileInfo() const;
    const char* getFileName() const;
    const char* getContent() const;
    const FileTime& getTimeOfCreation() const;
    const FileTime& getTimeOfLastModification() const;
    size_t getSize() const;
};