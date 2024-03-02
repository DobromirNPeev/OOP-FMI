#pragma once
#include "Song.h"


class Playlist {
	char* name=nullptr;
	mutable Song songs[120];
	size_t songsCounter = 0;
	Time timeOfPLaylist;
	void copyFrom(const Playlist& other);
	void free();
	void playSong(Song& current) const;
	void sortByPlaycount() const;
public:
	Playlist() = default;
	Playlist(const char* name);
	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);
	~Playlist();
	void playSongs() const;
	void printSongs() const;
	void printSongs(unsigned n) const;
	void printLength() const;
	void addSong(const char* title,	const char* singer,	size_t hours,size_t minutes,size_t seconds,const char* text);
	void removeSong(const char* title);
}; 