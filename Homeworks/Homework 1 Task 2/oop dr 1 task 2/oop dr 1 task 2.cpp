#include <iostream>
#include "TextFilesManager.h"

int main()
{
    TextFilesManager fs(3);
    fs.addFile("test.txt",10, 14, 0, 0, 20, 4, 2023, "rwxr--r--");
    fs.editFile("test.txt", "Hello, world!", 14, 10, 0, 20, 4, 2023,'u');
    fs.addInFile("test.txt", "Hello, my friend!", 14, 13, 0, 20, 3, 2023, 'u');
    fs.editFile("test.txt", "Hello", 14, 15, 0, 20, 4, 2023, 'u');
    fs.addFile("attest.txt",89 ,14, 30, 0, 20, 4, 2023, "rwxr--r--");
    fs.deleteFile("attest.txt");
    fs.addFile("attest.txt", 156,14, 35, 0, 20, 4, 2023, "rwxr--r--");
    fs.changeRights("attest.txt", 'u', 'w');
    fs.changeRights("attest.txt", 'u', 'r');
    fs.printFileInfo("attest.txt");
    fs.printFile("test.txt", 'o');
    fs.printFileInfo("test.txt");
    fs.addFile("est.txt", 200, 12, 0, 3, 20, 4, 2023, "rwxr—r—x");
    fs.editFile("attest.txt", "Hello, world! Don't forget to vote", 13, 22, 0, 20, 4, 2023, 'u');
    fs.addFile("ost.txt", 200, 12, 0, 3, 31, 3, 2023, "rwxr—r—x");
    fs.editFile("ost.txt", "Balite debeli", 12, 0, 3, 31, 3, 2022, 'u');
    //fs.print();
    fs.sort(SortOptions::name);
    fs.print();
    std::cout << std::endl;
    fs.sort(SortOptions::size);
    fs.print();
    std::cout << std::endl;
    fs.sort(SortOptions::timeOfCreation);
    fs.print();
    std::cout << std::endl;
    fs.sort(SortOptions::timeOfModification);
    fs.print();
    std::cout << std::endl;
   ///* TextFilesManager fs1;
   // fs1 = fs;
   // fs1.print();*///test.txt
   //     attest.txt
}