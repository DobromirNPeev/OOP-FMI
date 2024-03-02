#include "Table.h"

bool isFull = false;

Table::Table(std::ifstream& readTable) {
    setColumns(readTable);
    if (isFull) {
        isFull = false;
        sizeOfColumn = MAXCOLUMNS;
    }
    setRows(readTable);
}

namespace {

    bool isALetter(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }

    bool isAWord(const char* str) {
        if (*str == '\0' || str == nullptr) {
            return false;
        }
        while (*str) {
            if (*str != '\'' && !isALetter(*str) && *str != ' ') {
                return false;
            }
            str++;
        }
        return true;
    }
}
namespace {

    void centerAlignemnt(char* str) {
        if (str == nullptr) {
            return;
        }
        char strCopy[MAXSYMBOLS] = "";
        strcpy(strCopy, str);
        size_t len = strlen(str);
        unsigned count = 0;
        unsigned inputSpaces = (MAXSYMBOLS - 2 - len) / 2;;
        for (size_t i = 0; i < inputSpaces; i++)
        {
            str[i] = ' ';
        }
        for (size_t i = inputSpaces; i < len + inputSpaces; i++)
        {
            str[i] = strCopy[count++];
        }
        str[inputSpaces + count] = '\0';
    }

    void rightAlignemnt(char* str) {
        if (str == nullptr) {
            return;
        }
        char strCopy[MAXSYMBOLS] = "";
        strcpy(strCopy, str);
        unsigned count = 0;
        size_t len = strlen(str);
        unsigned inputSpaces = MAXSYMBOLS - len - 3;
        for (size_t i = 0; i < MAXSYMBOLS - len; i++)
        {
            str[i] = ' ';
        }
        for (size_t i = inputSpaces; i < len + inputSpaces; i++)
        {
            str[i] = strCopy[count++];
        }
        str[inputSpaces + count] = '\0';
    }
    void getWord(const char* str,size_t& i,char* newStr,unsigned& count) {
        while (isALetter(str[i]) || str[i] == '\'') {
            newStr[count++] = str[i++];
        }
    }
    void removeSpace(char* str) {
        if (str == nullptr) {
            return;
        }
        size_t rowLen = strlen(str);
        char newStr[MAXSYMBOLS];
        unsigned count = 0;
        for (size_t i = 0; i < rowLen; i++)
        {
            if (isALetter(str[i])) {
                getWord(str, i, newStr, count);
                newStr[count++] = ' ';
            }
        }
        newStr[count - 1] = '\0';
        strcpy(str, newStr);
    }
}

void Table::alignment(const char* str, bool& leftAlignment, bool& rightAlignment, bool& centerAlignment) const {

    while (*str) {
        if (*str == ':' && (*(str + 1) != ' ' && *(str + 1) != '\0')) {
            leftAlignment = true;
        }
        else if (*str == ':' && (*(str + 1) == ' ' || *(str + 1) == '\0')) {
            rightAlignment = true;
        }
        if (leftAlignment && rightAlignment)
        {
            centerAlignment = true;
            return;
        }
        str++;
    }
}

bool Table::tableValidation() const {
    int longestRow = getLongestRow();
    if (sizeOfColumn >= MAXCOLUMNS || longestRow+1 > MAXROWS) {
        return false;
    }
    return true;
}

int Table::getLongestRow() const {
    unsigned max = 0;
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        if (columns[i].sizeOfRow > max) {
            max = columns[i].sizeOfRow;
        }
    }
    return max;
}

void Table::setColumns(std::ifstream& readTable) {
    char currentColumn[MAXSYMBOLS];
    char character = readTable.get();
    while (true) {
        bool leftAlignment = false;
        bool rightAlignment = false;
        bool centerAlignment = false;
        readTable.getline(currentColumn, MAXSYMBOLS, character);
        if (readTable.eof() || readTable.fail()) {
            break;
        }
        if (isAWord(currentColumn)) {
            removeSpace(currentColumn);
            setColumn(currentColumn);
            if (isFull) {
                return;
            }
        }
        else {
            alignment(currentColumn, leftAlignment, rightAlignment, centerAlignment);
            if (centerAlignment)
            {
                columns[sizeOfColumn++].centerAlignment = true;
            }
            else if (rightAlignment) {
                columns[sizeOfColumn++].rightAlignment = true;
            }
            else {
                columns[sizeOfColumn++].leftAlignment = true;
            }
        }
        char ch = readTable.peek();
        if (ch == '\n') {
            readTable.get();
            break;
        }
    }
}
void Table::setColumn(char* input) {
    if (input == nullptr) {
        std::cout << ERROR << std::endl;
        return;
    }
    if (columns[sizeOfColumn].centerAlignment) {
        centerAlignemnt(input);
    }
    else if (columns[sizeOfColumn].rightAlignment) {
        rightAlignemnt(input);
    }
    strcpy(columns[sizeOfColumn].rows[columns[sizeOfColumn].sizeOfRow].row, input);
    columns[sizeOfColumn++].rows[columns[sizeOfColumn].sizeOfRow++].row;
}

void Table::setRows(std::ifstream& readTable) {
    size_t tempSizeOfColumn = sizeOfColumn;
    while (true) {
        sizeOfColumn = 0;
        if (readTable.eof() || readTable.fail()) {
            break;
        }
        setColumns(readTable);
        if (isFull) {
            for (size_t i = 0; i < sizeOfColumn; i++)
            {
                columns[i].sizeOfRow = MAXROWS;
            }
            break;
        }
        if (!tableValidation()) {
            isFull = true;
            return;
        }
    }
    sizeOfColumn = tempSizeOfColumn;
}

void Table::printSelected(const char* keyWord, size_t sizeOfRow, size_t indexOfColumn) const {
    writeRow(std::cout,0);
    std::cout << " |";
    std::cout << std::endl;
    unsigned dotsCount = 0;
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        std::cout << "| ";
        inputCharacter(std::cout,MAXSYMBOLS-1, '-', 0);
        if (j != sizeOfColumn - 1) {
            std::cout << " ";
        }

    }
    std::cout << " |";
    std::cout << std::endl;
    int longetsRow = sizeOfRow;
    bool* itHasKeyWord = new bool[longetsRow] {0};
    for (size_t i = 1; i < longetsRow; i++)
    {
        char notAligned[MAXSYMBOLS];
        strcpy(notAligned, columns[indexOfColumn].rows[i].row);
        removeSpace(notAligned);
        if (!strcmp(notAligned, keyWord)) {
            itHasKeyWord[i] = true;
        }
    }
    bool match = false;
    for (size_t i = 1; i < longetsRow; i++)
    {
        writeRowSelected(i, match, itHasKeyWord);
        if (match) {
            std::cout << " |";
            std::cout << std::endl;
            match = false;
        }
    }
    delete[] itHasKeyWord;
}

void Table::inputCharacter(std::ostream& ofs, unsigned leftOverSpace, char ch,unsigned dotsCount) const {
    for (size_t i = 0; i < leftOverSpace-dotsCount- 2; i++)
    {
        ofs << ch;
    }
}

void Table::writeRow(std::ostream& ofs, unsigned i) const {
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        ofs << "| " << columns[j].rows[i].row;
        unsigned leftOverSpace = MAXSYMBOLS - strlen(columns[j].rows[i].row)-1;
        if (leftOverSpace >=1) {
            inputCharacter(ofs,leftOverSpace, ' ', 0);
        }
        if (j != sizeOfColumn - 1) {
            ofs << " ";
        }
    }
}

void Table::writeRowSelected(unsigned i, bool& match, const bool* itHasKeyWord) const {
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        if (itHasKeyWord[i]) {
            std::cout << "| " << columns[j].rows[i].row;
            size_t leftOverSpace = MAXSYMBOLS - strlen(columns[j].rows[i].row)-1;
            if (leftOverSpace >= 1 ) {
                inputCharacter(std::cout,leftOverSpace, ' ',0);
            }
            if (j != sizeOfColumn - 1) {
                std::cout << " ";
            }
            match = true;
        }
    }
}

bool Table::checkIfInTableByRows(const char* str, size_t i) const {
    for (size_t j = 0; j < columns[i].sizeOfRow; j++)
    {
        char notAligned[MAXSYMBOLS];
        strcpy(notAligned, columns[i].rows[j].row);
        removeSpace(notAligned);
        if (!strcmp(notAligned, str)) {
            return true;
        }
    }
    return false;
}

void Table::print() const {
    writeRow(std::cout,0);
    std::cout << " |";
    std::cout << std::endl;
    unsigned dotsCount = 0;
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        std::cout << "| ";
        inputCharacter(std::cout,MAXSYMBOLS-1, '-', 0);
        if (j != sizeOfColumn - 1) {
            std::cout << " ";
        }
    }
    std::cout << " |";
    std::cout << std::endl;
    int longetsRow = getLongestRow();
    for (size_t i = 1; i < longetsRow; i++)
    {
        writeRow(std::cout,i);
        std::cout << " |";
        std::cout << std::endl;
    }
}

void Table::addRow() {
    std::cin.ignore();
    int longest = getLongestRow();
    if (longest>=MAXROWS) {
        std::cout << "Limit of rows reached" << std::endl;
        return;
    }
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        Row current;
        std::cout << INPUTROWNAME;
        std::cin.getline(current.row, MAXSYMBOLS);
        if (columns[i].rightAlignment) {
            rightAlignemnt(current.row);
        }
        else if (columns[i].centerAlignment) {
            centerAlignemnt(current.row);
        }
        strcpy(columns[i].rows[columns[i].sizeOfRow++].row, current.row);
    }
}


void Table::changeColumnName(const char* currentName, const char* newName) {
    if (currentName == nullptr || newName==nullptr) {
        std::cout << ERROR << std::endl;
        return;
    }
    if (!checkIfInTable(currentName)) {
        std::cout << NOTFOUND << std::endl;
        return;
    }
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        if (!strcmp(columns[i].rows[0].row, currentName)) {
            strcpy(columns[i].rows[0].row, newName);
            return;
        }
    }
}

void Table::changeRowByRowNumber(unsigned rowNum, const char* columnName,char* newRowName) {
    if (columnName == nullptr || newRowName==nullptr) {
        std::cout << ERROR << std::endl;
        return;
    }
    if (!checkIfInTable(columnName) || !checkIfValidRowNumber(rowNum,columnName)) {
        std::cout << NOTFOUND << std::endl;
        return;
    }
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        if (!strcmp(columns[i].rows[0].row, columnName)) {
            if (columns[i].rightAlignment) {
                rightAlignemnt(newRowName);
            }
            else if (columns[i].centerAlignment) {
                centerAlignemnt(newRowName);
            }
            strcpy(columns[i].rows[rowNum].row, newRowName);
        }
    }
}

bool Table::findFirstMatch(const char* rowName,char* newRowName,size_t i) {
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        char notAligned[MAXSYMBOLS];
        strcpy(notAligned, columns[j].rows[i].row);
        removeSpace(notAligned);
        if (!strcmp(notAligned, rowName)) {
            if (columns[j].rightAlignment) {
                rightAlignemnt(newRowName);
            }
            else if (columns[j].centerAlignment) {
                centerAlignemnt(newRowName);
            }
            strcpy(columns[j].rows[i].row, newRowName);
            return true;
        }
    }
    return false;
}

void Table::changeRowNameByColumn(const char* columnName, const char* rowName, char* newRowName) {
    if (columnName == nullptr || newRowName == nullptr || rowName==nullptr) {
        std::cout << ERROR << std::endl;
        return;
    }
    if (!checkIfInTable(columnName) || !checkIfInTable(rowName)) {
        std::cout << NOTFOUND << std::endl;
        return;
    }
    int longetsRow = getLongestRow();
    for (size_t i =1; i < longetsRow; i++)
    {
        if (findFirstMatch(rowName, newRowName, i)) {
            return;
        }
    }
}

void Table::select(const char* columnName, const char* rowName) const{
    if (columnName == nullptr || rowName == nullptr) {
        std::cout << "Error" << std::endl;
        return;
    }
    if (!checkIfInTable(columnName) || !checkIfInTable(rowName)) {
        std::cout << "Not in table" << std::endl;
        return;
    }
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        if (!strcmp(columns[i].rows[0].row, columnName)) {
            printSelected(rowName, columns[i].sizeOfRow, i);
        }
    }
}

void Table::save(std::ofstream& ofs) const {
    writeRow(ofs,0);
    ofs << " |";
    ofs << std::endl;
    unsigned dotsCount = 0;
    for (size_t j = 0; j < sizeOfColumn; j++)
    {
        ofs << "| ";
        if (columns[j].leftAlignment) {
            ofs << ":";
            dotsCount = 1;
        }
        else if (columns[j].centerAlignment) {
            ofs << ":";
            dotsCount = 2;
        }
        else if (columns[j].rightAlignment) {
            dotsCount = 1;
        }
        inputCharacter(ofs,MAXSYMBOLS-1, '-', dotsCount);
        if (columns[j].rightAlignment || columns[j].centerAlignment) {
            ofs << ":";
        }
        if (j != sizeOfColumn - 1) {
            ofs << " ";
        }
    }
    ofs << " |";
    ofs << std::endl;
    int longetsRow = getLongestRow();
    for (size_t i = 1; i < longetsRow; i++)
    {
        writeRow(ofs,i);
        ofs << " |";
        ofs << std::endl;
    }
    ofs.flush();
}

bool Table::checkIfInTable(const char* str) const {
    for (size_t i = 0; i < sizeOfColumn; i++)
    {

        if (checkIfInTableByRows(str, i)) {
            return true;
        }
    }
    return false;
}

bool Table::checkIfValidRowNumber(unsigned number,const char* columnName) const {
    if (number < 1) {
        return false;
    }
    for (size_t i = 0; i < sizeOfColumn; i++)
    {
        if (!strcmp(columns[i].rows[0].row, columnName)) {
            if (number > columns[i].sizeOfRow-1) {
                return false;
            }
            break;
        }
    }
    return true;
}