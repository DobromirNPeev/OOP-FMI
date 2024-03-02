#include <iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#pragma warning(disable: 4996)

const unsigned SIZE = 20;
struct User {
    char name[SIZE+1]="";
    char password[SIZE+1]="";
    unsigned age=0;
    char number[SIZE/2+1]="";
	int size = 0;
};
//Първата функция
int getFileSize(std::ifstream& file)
{
	int currentPos = file.tellg();
	file.seekg(0, std::ios::end);
	int fileSize = file.tellg();
	file.seekg(currentPos);
	return fileSize;
}

User* readUser(std::ifstream& readStream) {
	int filesSize = getFileSize(readStream);
	int userSize = filesSize / sizeof(User);
	User* users = new User[userSize];
	readStream.read((char*)users,filesSize);
	users->size = userSize;
	return users;
}

//Втората функция
bool isNumber(char ch) {
	return ch >= '0' && ch <= '9';
}
bool isCap(char ch) {
	return ch >= 'A' && ch <= 'Z';
}
bool passwordValidation(const char* str) {
	size_t len = strlen(str);
	int numberCount = 0;
	int CapCount = 0;
	if (len < 6) {
		return false;
	}
	for (size_t i = 0; i <len ; i++)
	{
		if (isCap(str[i])) {
			CapCount++;
		}
		if (isNumber(str[i])) {
			numberCount++;
		}
	}
	if (numberCount < 1 || CapCount < 1) {
		return false;
	}
	return true;
}
bool AlreadyIn(const User* users, const char* name) {
	for (size_t i = 0; i < users->size; i++)
	{
		if (!strcmp(name,users->name)) {
			return true;
		}
	}
	return false;
}
void writeUser(std::ofstream& writeStream,const User* users) {
	int n;
	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		User current;
		char name[SIZE+1];
		std::cin >> name;
		if (AlreadyIn(users,name)) {
			std::cout << "Invalid input";
			continue;
		}
		strcpy(current.name, name);
		char password[SIZE+1];
		std::cin >> password;
		if (!passwordValidation(password)) {
			std::cout << "Invalid input";
			continue;
		}
		strcpy(current.password, password);
		int age;
		std::cin >> age;
		current.age = age;
		char phoneNumber[SIZE / 2 + 1];
		std::cin >> phoneNumber;
		if (strlen(phoneNumber) < 10) {
			std::cout << "Invalid input";
			continue;
		}
		strcpy(current.number, phoneNumber);
		writeStream.write((const char*)&current, sizeof(User));
	}
}
//

//Третата функция
bool login(const char* name,const char* password,const User* users) {
	for (size_t i = 0; i < users->size; i++)
	{
		if (!strcmp(name, users[i].name) && !strcmp(password, users[i].password)) {
			return true;
		}
	}
	return false;
}
//

//Четвъртата фунция
void getOver18(const char* fileName,const User* users) {
	std::ofstream writeFile(fileName, std::ios::out | std::ios::binary);
	for (size_t i = 0; i < users->size; i++)
	{
		if (users[i].age > 18) {
			writeFile.write((const char*)&users[i], sizeof(User));
		}
	}
}
//

//Бонус функции
void getOverCertainAge(const User* users,int age) {
	for (size_t i = 0; i < users->size; i++)
	{
		if (users[i].age > age) {
			std::cout << users[i].name << ", " << users[i].password << ", " << users[i].age << ", " << users[i].number << std::endl;
		}
	}
}
void printUsers(const User* users) {
	for (size_t i = 0; i < users->size; i++)
	{
		std::cout << users[i].name << ", " << users[i].password << ", " << users[i].age << ", " << users[i].number << std::endl;
	}
}
//

int main()
{
	//Бонус
	std::ifstream readFile("users.dat", std::ios::in | std::ios::binary);
	if (!readFile.is_open()) {
		return -1;
	}
	User* users = readUser(readFile);
	readFile.close();
	while (true) {
		char command;
		std::cin >> command;
		if (command == 'i') {
			printUsers(users);
		}
		else if (command == 's') {
			char name[SIZE + 1];
			std::cin >> name;
			if (AlreadyIn(users, name)) {
				std::cout << "He/she exists"<<std::endl;
			}
			else {
				std::cout << "He/she doesn't exists" << std::endl;
			}
		}
		else if (command == 'f') {
			int age;
			std::cin >> age;
			getOverCertainAge(users, age);
		}
		else if (command == 'l') {
			char name[SIZE + 1];
			char password[SIZE + 1];
			std::cin >> name>>password;
			if (login(name, password, users)) {
				std::cout << "Logged in successfully" << std::endl;
			}
			else {
				std::cout << "Unsuccessfull log in" << std::endl;
			}
		}
		else if (command == 'q') {
			std::cout << "Exiting..";
			break;
		}
	}
	delete[] users;
	//getOver18("usersOver18.dat", users);
	//std::ofstream writeFile("users.dat", std::ios::out | std::ios::binary);
	//if (!writeFile.is_open()) {
	//	return -1;
	//}
	//writeUser(writeFile,users);
	//writeFile.close();
}
//