#include "TextFilesManager.h"

TextFilesManager::TextFilesManager(unsigned n) {
    files = new File[n];
    maxSizeCount = n;
}
unsigned TextFilesManager::getCount() const {
    return count;
}
void TextFilesManager::addFile(const char* fileName, size_t size,
    unsigned hourOfCreation, unsigned minsOfCreation, unsigned secsofCreation,
    unsigned dayOfCreation, unsigned monthOfCreation, unsigned yearfCreation,
    const char* accesRights) {
    int indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile >= 0) {
        std::cout << "File already exist" << std::endl;
        return;
    }
    if (maxSizeCount == count) {
        std::cout << "Capacity is full" << std::endl;
        return;
    }
    files[count++].setFile(fileName, size, hourOfCreation, minsOfCreation, secsofCreation, dayOfCreation, monthOfCreation, yearfCreation, accesRights);

}
int TextFilesManager::getIndexOfFile(const char* fileName) const {
    for (size_t i = 0; i < count; i++)
    {
        if (!strcmp(files[i].getFileName(), fileName)) {
            return i;
        }
    }
    return -1;
}
void TextFilesManager::editFile(const char* fileName, const char* content,
    unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
    unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight) {
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile].editFile(fileName, content, hourOfModification, minsOfModification, secsOfModification, dayOfModification, monthOfModification, yearOfModification, accesRight);
    }
    

}
void TextFilesManager::addInFile(const char* fileName, const char* content,
    unsigned hourOfModification, unsigned minsOfModification, unsigned secsOfModification,
    unsigned dayOfModification, unsigned monthOfModification, unsigned yearOfModification, char accesRight) {
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile].addInFile(fileName, content, hourOfModification, minsOfModification, secsOfModification, dayOfModification, monthOfModification, yearOfModification, accesRight);
    }
}
void TextFilesManager::deleteFile(const char* fileName) {
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile] = files[count - 1];
        count--;
    }
}
void TextFilesManager::changeRights(const char* fileName, char accessRight, char typeOfRight) {
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile].changeRights(accessRight, typeOfRight);
    }
}
void TextFilesManager::copyFrom(const TextFilesManager& other) {
    files = new File[other.maxSizeCount];
    for (size_t i = 0; i < other.count; i++)
    {
        files[i] = other.files[i];
    }
    maxSizeCount = other.maxSizeCount;
    count = other.count;
}
TextFilesManager::TextFilesManager(const TextFilesManager& other) {
    copyFrom(other);
}
void TextFilesManager::printFile(const char* fileName, char accessRight) const{
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile].printFile(accessRight);
    }
}
void TextFilesManager::printFileInfo(const char* fileName) const{
    size_t indexOfFile = getIndexOfFile(fileName);
    if (indexOfFile == -1) {
        std::cout << "File not found" << std::endl;
    }
    else {
        files[indexOfFile].printFileInfo();
    }
}
bool TextFilesManager::compare(SortOptions desiredSort, const File& lhs, const File& rhs) const {
    switch (desiredSort)
    {
    case SortOptions::name:return strcmp(lhs.getFileName(), rhs.getFileName()) < 0;
        break;
    case SortOptions::timeOfCreation: return lhs.getTimeOfCreation().compare(rhs.getTimeOfCreation());
        break;
    case SortOptions::timeOfModification: return lhs.getTimeOfLastModification().compare(rhs.getTimeOfLastModification());
        break;
    case SortOptions::size: return lhs.getSize() < rhs.getSize();
        break;
    default:
        break;
    }
}
unsigned TextFilesManager::innerPart(size_t i, enum class SortOptions desiredSort,unsigned min) const{
    for (size_t j = i + 1; j < count; j++)
    {
        if (compare(desiredSort, files[j], files[min])) {
            min = j;
        }
    }
    return min;
}
void TextFilesManager::sort(enum class SortOptions desiredSort) const{
    for (size_t i = 0; i < count; i++)
    {
        unsigned min = i;
        min = innerPart(i, desiredSort, min);
        if (i != min) {
            std::swap(files[i], files[min]);
        }
    }
}
void TextFilesManager::print() const{
    for (size_t i = 0; i < count; i++)
    {
        std::cout << files[i].getFileName() << std::endl;
    }
}
TextFilesManager::~TextFilesManager() {
    free();
}
void TextFilesManager::free() {
    delete[] files;
}
TextFilesManager& TextFilesManager::operator=(const TextFilesManager other) {
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
