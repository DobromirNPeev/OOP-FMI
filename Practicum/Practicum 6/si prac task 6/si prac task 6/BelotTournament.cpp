#include "BelotTournament.h"

void BelotTournament::copyFrom(const BelotTournament& other) {
	this->teams = new Team[other.teamsCount + 1];
	for (size_t i = 0; i < other.teamsCount; i++)
	{
		teams[i] = other.teams[i];
	}
	teamsCount = other.teamsCount;
}
void BelotTournament::free() {
	delete[] teams;
	teamsCount = 0;
}

BelotTournament::BelotTournament() {
	teams = nullptr;
	teamsCount = 0;
	charity = 0.0;
}
BelotTournament::BelotTournament(const BelotTournament& other) {
	copyFrom(other);
}
BelotTournament& BelotTournament::operator=(const BelotTournament& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
BelotTournament::~BelotTournament() {
	free();
}
void BelotTournament::remove(unsigned index) {
	this->teams[index] = teams[teamsCount - 1];
	teamsCount--;
}
void BelotTournament::startGame(){
	if (teamsCount % 2 == 1) {
		--teamsCount-=1;
	}
	while (teamsCount != 1) {
		unsigned number1;
		unsigned number2;
		std::cout << "Team to duel" << std::endl;
		std::cin >> number1 >> number2;

		if (number1 > teamsCount && number2<teamsCount) {
			number1 = teamsCount - 1;
		}
		else if (number2 > teamsCount && number1 < teamsCount) {
			number2 = teamsCount - 1;
		}
		else if(number1 > teamsCount && number2 > teamsCount){
			number1 = teamsCount - 1;
			number2 = teamsCount - 2;
		}
		unsigned loserInd = duel(number1, number2);
		remove(loserInd);
	}
	teams[teamsCount-1].players->print();
}

double BelotTournament::getCharity() const {
	return charity;
}
unsigned BelotTournament::getPlayersCount() const {
	return teamsCount;
}
unsigned BelotTournament::duel(unsigned index1, unsigned index2) {
	unsigned firstTeamRoundsWon = 0;
	unsigned secondTeamRoundsWon = 0;
	while (true) {
		unsigned firstTeamPoints;
		unsigned secondTeamPoints;
		std::cout << "First team points:" << std::endl;
		std::cout << "Second team points:" << std::endl;
		std::cin >> firstTeamPoints >> secondTeamPoints;
		teams[index1-1].points += firstTeamPoints;
		teams[index2-1].points += secondTeamPoints;
		if (teams[index1-1].points >= 151) {
			teams[index1-1].points = 0;
			teams[index2-1].points = 0;
			firstTeamRoundsWon++;
		}
		else if (teams[index2-1].points >= 151) {
			teams[index1-1].points = 0;
			teams[index2-1].points = 0;
			secondTeamRoundsWon++;
		}
		if (firstTeamRoundsWon==2 || secondTeamRoundsWon==2) {
			teams[index1-1].points = 0;
			teams[index2-1].points = 0;
			break;
		}
	}
	//знам, че е лоша абстракция!!!
	if (firstTeamRoundsWon != 2) {
		charity += 0.02 * teams[index1 - 1].players[0].getSalary();
		charity += 0.02 * teams[index1 - 1].players[1].getSalary();
		teams[index2 - 1].players[0].setSalary((teams[index1 - 1].players[0].getSalary() * 0.01) + teams[index2 - 1].players[0].getSalary());
		teams[index2 - 1].players[0].setSalary((teams[index1 - 1].players[1].getSalary() * 0.01) + teams[index2 - 12].players[0].getSalary());
		teams[index2 - 1].players[1].setSalary((teams[index1 - 1].players[0].getSalary() * 0.01) + teams[index2 - 1].players[1].getSalary());
		teams[index2 - 1].players[1].setSalary((teams[index1 - 1].players[1].getSalary() * 0.01) + teams[index2 - 1].players[1].getSalary());
		return index1-1;
	}
	else {
		charity += 0.02 * teams[index2 - 1].players[0].getSalary();
		charity += 0.02 * teams[index2 - 1].players[1].getSalary();
		teams[index1 - 1].players[0].setSalary((teams[index2 - 1].players[0].getSalary() * 0.01)+ teams[index1 - 1].players[0].getSalary());
		teams[index1 - 1].players[0].setSalary((teams[index2 - 1].players[1].getSalary() * 0.01)+ teams[index1 - 1].players[0].getSalary());
		teams[index1 - 1].players[1].setSalary((teams[index2 - 1].players[0].getSalary() * 0.01)+ teams[index1 - 1].players[1].getSalary());
		teams[index1 - 1].players[1].setSalary((teams[index2 - 1].players[1].getSalary() * 0.01)+ teams[index1 - 1].players[1].getSalary());
		return index2-1;
	}
}
BelotTournament::BelotTournament(unsigned numberOfTeams) {
	if (numberOfTeams < 2) {
		return;
	}
	teams = new Team[numberOfTeams];
	teamsCount = 0;
	charity = 0.0;

}
void BelotTournament::addTeam(const char* firstPlayerName, const char* secondPlayerName, const char* firstPlayerPosition, const char* secondPlayerPosition,unsigned firstPlayerSalary,unsigned secondPlayerSalary) {
	SoftwareEngineer firstPlayer(firstPlayerName, firstPlayerPosition,firstPlayerSalary);
	SoftwareEngineer secondPlayer(secondPlayerName, secondPlayerPosition,secondPlayerSalary);
	teams[teamsCount].players[0] = firstPlayer;
	teams[teamsCount].players[1] = secondPlayer;
	teamsCount++;
}