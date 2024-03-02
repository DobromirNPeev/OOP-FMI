#include <iostream>
#include<fstream>

void writeTofile(const char* filename)
{
    int n, m;
    std::cin >> n >> m;
    std::ofstream res(filename);
    res << n + m << " " << n - m << std::endl;
    res.close();
}
void readFromFile(const char* filename) {
    std::ifstream readRes(filename);
    if (!readRes.is_open()) {
        return;
    }
    int n, m,sum=0,diff=0;
    readRes >> sum >> diff;
    n = (sum - diff) / 2;
    m = sum - n;
    std::cout << m << " " << n;
    readRes.close();
}


int main()
{
    
}