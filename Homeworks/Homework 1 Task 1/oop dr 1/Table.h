#pragma once
#include <iostream>
#include <fstream>
#include "Contsants.h"
#pragma warning (disable:4996)

struct Row {
    char row[MAXSYMBOLS] = "";
};
struct Column {
    size_t sizeOfRow = 0;
    Row rows[MAXROWS];
    bool leftAlignment = false;
    bool rightAlignment = false;
    bool centerAlignment = false;
};
class Table {
    Column columns[MAXCOLUMNS];
    size_t sizeOfColumn = 0;
    int getLongestRow() const;
    void setColumns(std::ifstream& readTable);
    void setColumn(char* input);
    void setRows(std::ifstream& readTable);
    void printSelected(const char* keyWord, size_t sizeOfRow, size_t indexOfColumn) const;
    void inputCharacter(std::ostream& ofs, unsigned leftOverSpace, char ch, unsigned dotsCount) const;
    void writeRow(std::ostream& ofs,unsigned i) const;
    void writeRowSelected(unsigned i,bool& match,const bool* itHasKeyword) const;
    bool checkIfInTableByRows(const char* str, size_t i) const;
    void alignment(const char* str, bool& leftAlignment, bool& rightAlignment, bool& centerAlignment) const;
    bool tableValidation() const;
    bool checkIfInTable(const char* str) const;
    bool checkIfValidRowNumber(unsigned number, const char* columnName) const;
    bool findFirstMatch(const char* rowName, char* newRowName, size_t i);

public:
    Table(std::ifstream& readTable);
    void print() const;
    void addRow();
    void changeColumnName(const char* currentName, const char* newName);
    void changeRowByRowNumber(unsigned rowNum, const char* columnName, char* newRowName);
    void changeRowNameByColumn(const char* columnName, const char* rowName,char* newRowName);
    void select(const char* columnName, const char* rowName) const;
    void save(std::ofstream& ofs) const;
};
