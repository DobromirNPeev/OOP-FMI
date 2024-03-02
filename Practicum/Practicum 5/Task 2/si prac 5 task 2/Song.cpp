#include "Song.h"

void Song::setPlayedCount() {
	playedCount++;
}
Time Song::getLength() const {
	return length;
}

const char* Song::getTitle() const {
	return title;
}
const char* Song::getSinger() const {
	return singer;
}
const char* Song::getText() const {
	return text;
}
unsigned Song::getPlayedCount() const {
	return playedCount;
}

void Song::setTitle(const char* title) {
	strcpy(this->title, title);
}

void Song::setSinger(const char* singer) {
	strcpy(this->singer, singer);
}
void Song::setText(const char* text) {
	strcpy(this->text, text);
}
void Song::setTime(size_t hours, size_t minutes, size_t seconds) {
	Time length(hours, minutes, seconds);
	this->length = length;
}