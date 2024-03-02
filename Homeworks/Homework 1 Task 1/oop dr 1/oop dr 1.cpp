#include <iostream>
#include "Table.h"
#pragma warning (disable:4996)

int main()
{
    char command[COMMANDMAXSIZE];
    std::cout << INPUTFILENAME;
    std::cin.getline(command, COMMANDMAXSIZE);
    std::ifstream readTable(command);
    if (!readTable.is_open()) {
        std::cout << ERROR << std::endl;
        return 0;
    }
    Table table(readTable);
    if (readTable.fail() && !readTable.eof()) {
        std::cout << ERROR;
        readTable.close();
        return 0;
    }
    std::cout << "Table loaded successfully" << std::endl;
    readTable.close();
    while (true) {

        std::cout << std::endl;
        std::cout << COMMANDOPTIONS << std::endl;
        std::cout << "- \'" << PRINT << "\' - print the table" << std::endl;
        std::cout << "- \'" << ADDROW << "\' - add a new row" << std::endl;
        std::cout << "- \'"<< CHANGECOLUMNNAME <<"\' - change the name of a column of yout choice" << std::endl;
        std::cout << "- \'"<< CHANGEROWBYROWNUMBER <<"\' - change a row by certain row number in a certain column" << std::endl;
        std::cout << "- \'"<<CHANGEROWNAMEBYCOLUMNNAME<<"\' - change a row by certain row name in a certain column (it will change only the first matching row name)" << std::endl;
        std::cout << "- \'"<<SELECT<<"\' - print the table by a certain row name in a certain column" << std::endl;
        std::cout << "- \'"<<SAVE<<"\' - save the table in the same file or in a new" << std::endl;
        std::cout << std::endl;
        std::cout << ">";
        std::cin >> command;
        if (!strcmp(command, PRINT)) {
            table.print();
        }
        else if (!strcmp(command, CHANGECOLUMNNAME)) {
            char columnName[MAXSYMBOLS];
            char newColumnName[MAXSYMBOLS];
            std::cout << INPUTCOLUMNNAME<<std::endl;
            std::cin.ignore();
            std::cin.getline(columnName,MAXSYMBOLS);
            std::cout << "New "<<INPUTCOLUMNNAME<<std::endl;
            std::cin.getline(newColumnName, MAXSYMBOLS);
            table.changeColumnName(columnName, newColumnName);
        }
        else if (!strcmp(command, ADDROW)) {
            table.addRow();
        }
        else if (!strcmp(command,CHANGEROWBYROWNUMBER)) {
            unsigned rowNumber;
            char columnName[MAXSYMBOLS];
            char newRowName[MAXSYMBOLS];
            std::cin.ignore();
            std::cout << INPUTCOLUMNNAME << std::endl;
            std::cin.getline(columnName, MAXSYMBOLS);
            std::cout << "Row number: "<<std::endl;
            std::cin >> rowNumber;
            std::cin.ignore();
            std::cout << INPUTNEWROWNAME <<std::endl;
            std::cin.getline(newRowName, MAXSYMBOLS);
            table.changeRowByRowNumber(rowNumber, columnName, newRowName);
        }
        else if (!strcmp(command, CHANGEROWNAMEBYCOLUMNNAME)) {
            char columnName[MAXSYMBOLS];
            char rowName[MAXSYMBOLS];
            char newRowName[MAXSYMBOLS];
            std::cin.ignore();
            std::cout << INPUTCOLUMNNAME << std::endl;
            std::cin.getline(columnName,MAXSYMBOLS);
            std::cout << INPUTROWNAME << std::endl;
            std::cin.getline(rowName, MAXSYMBOLS);
            std::cout << INPUTNEWROWNAME << std::endl;
            std::cin.getline(newRowName, MAXSYMBOLS);
            table.changeRowNameByColumn(columnName, rowName, newRowName);
        }
        else if (!strcmp(command, SELECT)) {
            char columnName[MAXSYMBOLS];
            char rowName[MAXSYMBOLS];
            std::cin.ignore();
            std::cout << INPUTCOLUMNNAME << std::endl;
            std::cin.getline(columnName, MAXSYMBOLS);
            std::cout << INPUTROWNAME << std::endl;
            std::cin.getline(rowName, MAXSYMBOLS);
            table.select(columnName, rowName);
        }
        else if (!strcmp(command, SAVE)) {
            char fileName[MAXSYMBOLS];
            std::cout << INPUTFILENAME << std::endl;
            std::cin >> fileName;
            std::ofstream ofs(fileName);
            if (!ofs.is_open()) {
                std::cout << ERROR<<std::endl;
            }
            table.save(ofs);
            ofs.close();
            break;
        }
        else {
            std::cout << "Invalid command"<<std::endl;
        }
    }
}