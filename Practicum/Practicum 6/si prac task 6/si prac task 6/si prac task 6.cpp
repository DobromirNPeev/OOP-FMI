#include <iostream>
#include "BelotTournament.h"

int main()
{
    unsigned numberOfPlayers;
    std::cin >> numberOfPlayers;
    BelotTournament belot(numberOfPlayers);
    belot.addTeam("Dimo Aleksiev", "Ralits Paskaleva", "Junior", "senior",144,848);
    belot.addTeam("Dino Aleksiev", "Ralitsa Paskaleva", "Junior1", "Senior",489,9889);
    belot.addTeam("Diko Aleksiev", "Ralitse Paskaleva", "Junior3", "Senor",678,7798);
    belot.addTeam("Dipo Aleksiev", "Ralitsq Paskaleva", "Junior2", "Senior8",7466,77);
    std::cout << belot.getCharity();
}