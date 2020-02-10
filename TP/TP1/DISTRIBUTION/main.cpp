
#include <iostream>
#include <mutex>

#include "arbitre.h"
//enum class player {PVS_, A_ , BRUTAL_ , RAND, MM_ } ;
using namespace std;

int main()
{
    //initialise la graine du générateur aléatoire
    std::srand(std::time(nullptr));

    // création de l'Arbitre (graine , joueur 1, joueur 2 , nombre de parties)
    Arbitre a (2223, player::BRUTAL_, player::PVS_,100);
    // commence le challenge
    a.challenge();
    return 0;
}
