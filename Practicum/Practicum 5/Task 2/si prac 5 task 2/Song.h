#pragma once
#include "Time.h"
#pragma warning (disable: 4996)

class Song {
	char title[64]="";
	char singer[64]="";
	Time length;
	char text[512]="";
	unsigned playedCount = 0;
public:
	Song() = default;
	const char* getTitle() const;
	const char* getSinger() const;
	const char* getText() const;
	Time getLength() const;
	unsigned getPlayedCount() const;
	void setTitle(const char* title);
	void setSinger(const char* singer);
	void setTime(size_t hours,size_t minutes,size_t seconds);
	void setText(const char* text);
	void setPlayedCount();
};