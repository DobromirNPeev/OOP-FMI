#include "Playlist.h"

void Playlist::copyFrom(const Playlist& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	for (size_t i = 0; i < other.songsCounter; i++)
	{
		songs[i] = other.songs[i];
	}
	songsCounter = songsCounter;
	timeOfPLaylist = other.timeOfPLaylist;
}
void Playlist::free() {
	delete[] name;
}
Playlist::Playlist(const char* name) {
	if (name == nullptr) {
		return;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Playlist::Playlist(const Playlist& other) {
	copyFrom(other);
}
Playlist& Playlist::operator=(const Playlist& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Playlist::~Playlist() {
	free();
}

void Playlist::playSongs() const{
	for (size_t i = 0; i < songsCounter; i++)
	{
		playSong(songs[i]);
	}
}
void Playlist::playSong(Song& current) const {
	std::cout << "Title:" << current.getTitle() << std::endl;
	std::cout << "Singer:" << current.getSinger() << std::endl;
	std::cout << "Text:" << current.getText() << std::endl;
	std::cout << std::endl;
	current.setPlayedCount();
}

void Playlist::printSongs() const{
	for (size_t i = 0; i < songsCounter; i++)
	{
		std::cout << "<" << songs[i].getText() << "> - <" << songs[i].getSinger() << ">"<<std::endl;
	}
}
void mySwap(Song& a, Song& b) {
	Song temp = a;
	a = b;
	b = temp;
}
void Playlist::sortByPlaycount() const{
	for (size_t i = 0; i < songsCounter; i++)
	{
		unsigned min = i;
		for (size_t j = i+1; j < songsCounter; j++)
		{
			if (songs[j].getPlayedCount() < songs[min].getPlayedCount()) {
				min = j;
			}
		}
		if (min != i) {
			mySwap(songs[i], songs[min]);
		}
	}
}

void Playlist::printSongs(unsigned n) const {
	if (n > songsCounter) {
		return;
	}
	sortByPlaycount();
	for (size_t i = 0; i < n; i++)
	{
		playSong(songs[i]);
	}
}
void Playlist::printLength() const{
	timeOfPLaylist.print(false);
	std::cout<<std::endl;
}
void Playlist::addSong(const char* title, const char* singer, size_t hours, size_t minutes, size_t seconds, const char* text) {
	songs[songsCounter].setTitle(title);
	songs[songsCounter].setSinger(singer);
	songs[songsCounter].setTime(hours,minutes,seconds);
	timeOfPLaylist += songs[songsCounter].getLength();
	songs[songsCounter].setText(text);
	songsCounter++;
}
void Playlist::removeSong(const char* title) {
	for (size_t i = 0; i <songsCounter; i++)
	{
		if (!strcmp(songs[i].getTitle(), title)) {
			mySwap(songs[i], songs[songsCounter - 1]);
				songsCounter--;
		}
	}
}