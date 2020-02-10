#pragma once


#include "joueur.h"
#include <stack>
#include <vector>

typedef std::stack<int> movelist;

class Joueur_PVS_ : public Joueur
{
public:
  Joueur_PVS_(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup) override;

private:
	movelist pv;
};
