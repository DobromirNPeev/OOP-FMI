#pragma once
#include "SoftwareEngineer.h"

struct Team{
	SoftwareEngineer players[2];
	unsigned points = 0;
};

class BelotTournament
{
	Team* teams;
	unsigned teamsCount;
	double charity;
	void copyFrom(const BelotTournament& other);
	void free();
public:
	//The Big Four
	BelotTournament();
	BelotTournament(const BelotTournament& other);
	BelotTournament& operator=(const BelotTournament& other);
	~BelotTournament();
	//
	BelotTournament(unsigned numberOfTeams);
	void addTeam(const char* firstPlayerName, const char* secondPlayerName, const char* firstPlayerPosition, const char* secondPlayerPosition, unsigned firstPlayerSalary, unsigned secondPlayerSalary);
	void startGame();
	unsigned getPlayersCount() const;
	unsigned duel(unsigned index1, unsigned index2);
	void remove(unsigned index);
	double getCharity() const;
};

