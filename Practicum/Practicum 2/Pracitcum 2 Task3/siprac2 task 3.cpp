#include <iostream>
#include <fstream>

struct Color {
    int red=0;
    int green=0;
    int blue=0;
	int size = 0;
};

//12465237=256*256*r+256*g+b
//b = 12465237 % 256
//g = ((12465237 - b) / 256) % 256
//r = (((12465237 - b) / 256 * 2) - g / 256
// 
//Първата функция
bool IsColorValid(int x,int y,int z) {
	return (x >= 0 && x <= 255) && (y >= 0 && y <= 255) && (z >= 0 && z <= 255);
}
unsigned getCharCountFromFile(std::ifstream& ifs, char ch)
{
	size_t currentPosition = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	if (!ifs.is_open())
		return 0;

	unsigned int count = 0;

	while (true)
	{
		char current = ifs.get();
		if (ifs.eof())
			break;

		if (current == ch)
			count++;
	}

	ifs.clear();
	ifs.seekg(currentPosition);
	return count;
}
unsigned numberLen(std::ifstream& readFile) {
	int counter = 0;
	char ch = readFile.get();
	while (ch!='|' && !readFile.eof()) {
		counter++;
		ch = readFile.get();
	}
	readFile.clear();
	return counter;
}
bool readNumber(std::ifstream& readFile,Color& current) {
	int number = 0;
	size_t currentPosition = readFile.tellg();
	int currLen = numberLen(readFile);
	readFile.seekg(currentPosition);
	for (int i = 0; i < currLen; i++)
	{
		(number *= 10) += readFile.get()-'0';
	}
	int x = number % 256;
	int y = ((number - x) / 256) % 256;
	int z = (((number - x) / (256 * 256))) - y / 256;
	readFile.get();
	if (IsColorValid(x,y,z)) {
		current.blue = x;
		current.green = y;
		current.red = z;
		return true;
	}
	else {
		return false;
	}
}
Color* fileToColor(std::ifstream& readFile) {
	int numbers = getCharCountFromFile(readFile, '|');
	int numberCount = numbers + 1;
	int count = 0;
    Color* colors = new Color[numberCount];
	for (size_t i = 0; i < numberCount; i++)
	{
		if (readNumber(readFile, colors[count])) {
			count++;
		}
	}
	colors->size = count;
	for (size_t i = 0; i < colors->size; i++)
	{
		std::cout << colors[i].red << " " << colors[i].green << " " << colors[i].blue<<std::endl;
	}
	return colors;
}
//

//Втората функция
void ColorToFile(std::ofstream& writeFile,const Color* colors) {
	for (size_t i = 0; i < colors->size; i++)
	{
		if (i == colors->size - 1) {
			writeFile << 256 * 256 * colors[i].red + 256 * colors[i].green + colors[i].blue;
		}
		else {
			writeFile << 256 * 256 * colors[i].red + 256 * colors[i].green + colors[i].blue << "|";
		}
	}
}
//

//Третата функция
void writeRed(const Color* colors) {
	std::ofstream red("red.txt");
	if (!red.is_open()) {
		return;
	}
	for (size_t i = 0; i < colors->size; i++)
	{
		if (colors[i].red > 250 && IsColorValid(colors[i].red,colors[i].green,colors[i].blue)) {
			red << colors[i].red << " " << colors[i].green << " " << colors[i].blue << std::endl;
		}
	}
	red.close();
}
//

int main()
{
	Color* Colors;
	std::ifstream readFile("colors.txt");
	if (!readFile.is_open()) {
		return 0;
	}
	Colors = fileToColor(readFile);
	readFile.close();
	std::ofstream writeFile("colors1.txt");
	if (!writeFile.is_open()) {
		return 0;
	}
	ColorToFile(writeFile, Colors);
	writeFile.close();
	writeRed(Colors);
	delete[] Colors;
}
