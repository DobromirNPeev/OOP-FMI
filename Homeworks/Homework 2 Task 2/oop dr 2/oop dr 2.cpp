#include <iostream>
#include "StringCreaterPieceByPiece.h"

int main()
{
	//StringPiece strpiece("Domir");
 //   std::cout << *strpiece.begin<<std::endl;
 //   std::cout << *(strpiece.end-1)<<std::endl;
 //   //strpiece<<"kr";

 //   //std::cout << *(strpiece.begin) << std::endl;;
 //   //std::cout << *(strpiece.end-1) << std::endl;;

 //   //strpiece<<10;
 //   //std::cout << *(strpiece.begin) << std::endl;;
 //   //std::cout << *(strpiece.end-1) << std::endl;;


 //   strpiece   <<  "kr";


 //   std::cout << *(strpiece.begin) << std::endl;;
 //   std::cout << *(strpiece.end - 1) << std::endl;;
 //  
 //   10>>strpiece;
 //   //strpiece.removeFirstKsymbols(10);
 //   //strpiece.removeLastKsymbols(12);
 //   std::cout << *(strpiece.begin) << std::endl;;
 //   std::cout << *(strpiece.end - 1) << std::endl;;
 //   std::cout << strpiece.getValue().piece;


	//strpiece.removeFirstKsymbols(1);
	//strpiece.removeLastKsymbols(3);
	//strpiece.changeSymbol(15, 'u');
	//std::cout << strpiece.getValue();
    //StringPiece pi("iuio");
    //"zub" >> pi;
    //std::cout<<pi.getValue();
    //pi.changeSymbol(6, 'u');
   //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" >>pi;
    StringCreaterPieceByPiece sc(2);

    sc.addPiece("test");
    sc.addPiece();
    sc.addPiece("football");

    sc[1] << " friends ";
    " Hello " >> sc[1] ;
    10 >> sc[2];

    std::cout << sc.getStringSize()<<std::endl;
    MyString result1 = sc.getString(); // “test Hello friends 10football”
    std::cout << result1 << std::endl;

    sc.swap(1, 2);
    MyString result2 = sc.getString(); // “test10football Hello friends”
    std::cout << result2.c_str() << std::endl;

    sc.deleteByIndex(1);
    MyString result3 = sc.getString(); // “test10                     Hello friends”
    std::cout << result3.c_str() << std::endl;
    StringPiece sr("Medi");
    "Gogov" >> sr;
    sr << "Jivei";
    //sr.removeFirstKsymbols(6);

    std::cout << sr.getValue()<<std::endl;
    sr.setValue("Sabi");
    std::cout << sr.getValue();
}
