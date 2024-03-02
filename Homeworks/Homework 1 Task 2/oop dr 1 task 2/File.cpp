#include "Fileh.h"

File::File() : File("", "", 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, "---------") {};

File::FileTime::FileTime() : FileTime(0, 0, 0, 1, 1, 1) {};

bool File::FileTime::compare(const FileTime& other) const {
    if (this->date.compare(other.date) < 0) {
        return true;
    }
    else if (this->date.compare(other.date) == 0) {
        if (this->time.compare(other.time) < 0) {
            return true;;
        }
    }
    return false;
}


void File::setFile(const char* fileName, size_t size,
    unsigned hoursOfCreation, unsigned minsOfCreation, unsigned secsOfCreation,
    unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearOfCreation,
    const char* accesRights) {
    strcpy(this->fileName, fileName);
    this->size = size;
    FileTime timeOfCreationNew(hoursOfCreation, minsOfCreation, secsOfCreation,
        dayOfCreation, monthOfCreation, yearOfCreation);
    this->timeOfCreation = timeOfCreationNew;
    this->timeOfLastModification = timeOfCreationNew;
    strcpy(this->accessRight, accesRights);
}

void File::writing(unsigned index, const char* content, unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
                            unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification,const char* command) {
        if (this->accessRight[index] == 'w') {
            FileTime timeOfModificationNew(hourOfModification,minsOfModification,secsOfModification,
                dayOfModification,monthOfModification,yearOfModification);
            this->timeOfLastModification = timeOfModificationNew;
            if (!strcmp(command, "write")) {
                strcpy(this->content, content);
            }
            else if(!strcmp(command, "concat")){
                strcat(this->content, content);
            }
        }
}

void File::editFile(const char* fileName, const char* content,
    unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
    unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight)
{
    if (accesRight == 'u') {
        writing(1, content,
            hourOfModification,minsOfModification,secsOfModification,
            dayOfModification, monthOfModification, yearOfModification,"write");
    }
    else if (accesRight == 'g') {
        writing(4, content,
            hourOfModification, minsOfModification, secsOfModification,
            dayOfModification, monthOfModification, yearOfModification, "write");
    }
    else if (accesRight == 'o') {
        writing(7, content,
            hourOfModification, minsOfModification, secsOfModification,
            dayOfModification, monthOfModification, yearOfModification, "write");
    }
}
const char* File::getContent() const {
    return content;
}
void File::addInFile(const char* fileName, const char* content,
    unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
    unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight) {
    if (strlen(this->content)+strlen(content)>CONTENTSIZE) {
        std::cout << "Limit of content reached" << std::endl;
        return;
    }
    if (accesRight == 'u') {
        writing(1, content,
            hourOfModification, minsOfModification, secsOfModification,
            dayOfModification, monthOfModification, yearOfModification, "concat");
    }
    else if (accesRight == 'g') {
        writing(4, content,
            hourOfModification, minsOfModification, secsOfModification,
            dayOfModification, monthOfModification, yearOfModification, "concat");
    }
    else if (accesRight == 'o') {
        writing(7, content,
            hourOfModification, minsOfModification, secsOfModification,
            dayOfModification, monthOfModification, yearOfModification, "concat");
    }
}
const char* File::getFileName() const {
    return fileName;
}
void File::changingRights(char typeOfRight,unsigned index) {
    if (this->accessRight[index] == 'r' && typeOfRight == 'r') {
        this->accessRight[index] = '-';
    }
    else if (this->accessRight[index] != 'r' && typeOfRight == 'r') {
        this->accessRight[index] = 'r';
    }
    if (this->accessRight[index+1] == 'w' && typeOfRight == 'w') {
        this->accessRight[index+1] = '-';
    }
    else if (this->accessRight[index+1] != 'w' && typeOfRight == 'w') {
        this->accessRight[index+1] = 'w';
    }
    if (this->accessRight[index+2] == 'x' && typeOfRight == 'x') {
        this->accessRight[index + 2] = '-';
    }
    else if (this->accessRight[index + 2] != 'x' && typeOfRight == 'x') {
        this->accessRight[index + 2] = 'x';
    }
}
void File::changeRights(char accessRight, char typeOfRight) {
    if (accessRight == 'u') {
        changingRights(typeOfRight, 0);
    }
    else if (accessRight == 'g') {
        changingRights(typeOfRight, 3);
    }
    else if (accessRight == 'o') {
        changingRights(typeOfRight, 6);
    }
}
void File::printFile(char accessRight) const{
    if (accessRight == 'u') {
        if (this->accessRight[0] == 'r') {
            std::cout << content << std::endl;
        }
    }
    else if (accessRight == 'g') {
        if (this->accessRight[3] == 'r') {
            std::cout << content << std::endl;
        }
    }
    else if (accessRight == 'o') {
        if (this->accessRight[6] == 'r') {
            std::cout << content << std::endl;
        }
    }
}

void File::printFileInfo() const{
    std::cout << "Name: " << fileName << std::endl;
    std::cout << "Size: " << size << std::endl;
    std::cout << "Created on: "; timeOfCreation.date.print();
    std::cout << "Last modified on: "; timeOfCreation.time.print(false); std::cout << std::endl;
    std::cout << "Rights: " << accessRight << std::endl;
}
const File::FileTime& File::getTimeOfCreation() const{
    return timeOfCreation;
}
File::File(const char* fileName, const char* content, unsigned size, unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearOfCreation, unsigned hoursOfCreation, unsigned minsOfCreation, unsigned secsOfCreation, unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, unsigned hoursOfModification, unsigned minsOfModification, unsigned secsOfModification, const char* accessRights)
{
    setFile(fileName, size,
        hoursOfCreation, minsOfCreation,secsOfCreation,
        dayOfCreation, monthOfCreation,yearOfCreation,
        accessRights);
}
const File::FileTime& File::getTimeOfLastModification() const{
    return timeOfLastModification;
}
size_t File::getSize() const{
    return size;
}