#include <iostream>
#include <fstream>

struct Pair {
    unsigned int x;
    unsigned int y;
};
struct Relation {
    Pair relations[25];
    size_t size;
};

//Първата функция
void readRelation(const char* fileName) {
    std::ifstream rels(fileName);
    while (1) {
        int first, second;
        rels >> first >> second;
        if (rels.eof()) {
            break;
        }
        std::cout << first << " " << second << std::endl;
    }
}
//

//Втората функция
void addPair(Relation& relation,int index) {
    int x, y;
    std::cin >> x >> y;
    relation.relations[index].x = x;
    relation.relations[index].y = y;
}
//

//Третата функция
void writeRelation(const char* fileName,size_t size,const Relation& relation) {
    std::ofstream writeRel(fileName);
    for (size_t i = 0; i < size; i++)
    {
        writeRel << relation.relations[i].x << " " << relation.relations[i].y << std::endl;;
    }
}
//

int main()
{
    int count = 0;
    Relation relation;
    while (count < 3) {
        addPair(relation, count);
        count++;
    }
    writeRelation("relations.txt", count, relation);
    readRelation("relations.txt");
}