#include <iostream>
#include "Matrix.h"

int main()
{
    Matrix mtr(3, 4);
	mtr[0][0]=1;
	mtr[0][1]=5;
	mtr[0][2]=3;
	mtr[0][3]=6;
	mtr[1][0]=0;
	mtr[1][1]=9;
	mtr[1][2]=7;
	mtr[1][3]=6;
	mtr[2][0]=7;
	mtr[2][1]=-6;
	mtr[2][2]=2;
	mtr[2][3]=5;
	std::cout << mtr;
	std::cout << std::endl;
	Matrix mtr1(4, 3);
	mtr1[0][0] = 2;
	mtr1[0][1] = 9;
	mtr1[0][2] = 10;
	mtr1[1][0] = -3;
	mtr1[1][1] = -8;
	mtr1[1][2] = 11;
	mtr1[2][0] = -7;
	mtr1[2][1] = 3;
	mtr1[2][2] = 2;
	mtr1[3][0] = 6;
	mtr1[3][1] = 4;
	mtr1[3][2] = 1;
	std::cout << mtr1;
	std::cout << std::endl;
	Matrix mtr2(mtr);
	mtr *= mtr1;
	std::cout << mtr;
	mtr = mtr2;
	mtr += mtr2;
	std::cout << mtr;
	mtr = mtr2;
	mtr -= mtr2;
	std::cout << mtr;
	mtr = mtr2;
	mtr *= 4;
	std::cout << mtr;
	mtr = mtr2;
	//mtr == mtr1;
	bool even=mtr != mtr2;
	std::cout << even;


}

