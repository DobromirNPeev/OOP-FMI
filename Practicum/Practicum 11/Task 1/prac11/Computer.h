#pragma once
#include "MyString.h"
class Computer
{
	double power;
	MyString videoCardName;
	int powerSupply;
	int RAMMemory;
public:
	virtual void getType() const = 0;
	void setPower(double power) {
		this->power = power;
	}
	void setVideoCardName(const char* name) {
		videoCardName = name;
	}
	void setPowerSupply(int powerSupply) {
		this->powerSupply = powerSupply;
	}
	void setRAMMemory(int RAMMemory) {
		this->RAMMemory = RAMMemory;
	}
	virtual const MyString* canConnect() const = 0;
	//virtual ~Computer();
};

class PC : public Computer {
	const MyString devices[4] = { "mouse", "keyboard", "microfon", "headphones" };
public:
	void getType() const override {
		std::cout << "PC";
	}
	const MyString* canConnect() const override {
		return devices;
	}
};
//MyString PC::devices[4] = {"mouse", "keyboard", "microfon", "headphones"};

class Laptop : public Computer {
	const MyString laptopDevices[3] = { "mouse pad", "keyboard", "monitor" };
public:
	void getType() const override {
		std::cout << "Laptop";
	}
	const MyString* canConnect() const override {
		return laptopDevices;
	}
};
//MyString Laptop::laptopDevices[3] = { "mouse pad", "keyboard", "monitor" };

class GamingConsole : public Computer {
	const MyString consoleDevices[2] = { "joystick", "monitor" };
public:
	void getType() const override {
		std::cout << "Gaming console";
	}
	const MyString* canConnect() const override {
		return consoleDevices;
	}
};
//MyString GamingConsole::consoleDevices[2] = { "joystick", "monitor" };