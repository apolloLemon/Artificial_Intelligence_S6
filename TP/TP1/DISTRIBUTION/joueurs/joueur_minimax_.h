#pragma once


#include "joueur.h"


class Joueur_MiniMax_ : public Joueur
{
public:
  Joueur_MiniMax_(std::string nom, bool joueur);
  char nom_abbrege() const override;

  void recherche_coup(Jeu, int & coup) override;
};
