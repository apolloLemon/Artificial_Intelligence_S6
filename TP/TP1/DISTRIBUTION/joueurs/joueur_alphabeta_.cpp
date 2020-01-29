#include "joueur_alphabeta_.h"


Joueur_AlphaBeta_::Joueur_AlphaBeta_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_AlphaBeta_::nom_abbrege() const
{
    return 'A';
}

int max (int a, int b) {
	return ((a>b)? a:b) ;
}
int min (int a, int b) {
	return ((a<b)? a:b) ;
}

int minimax(Jeu jeu, bool E) {
	//std::cout << "minimax\n";
	//jeu.print_coups();
	if(jeu.fini())
		if(E)
			return -1;
		else 
			return 1;

	int val;
	if(E){
		val = -999;
		for(int i=0;i<jeu.nb_coups();i++){
			Jeu g(jeu.etat());
			if(!g.coup_licite(i)) continue;
			g.joue(i);
			val = max(val, minimax(g,!E));
		}
		return val;
	} else {
		val = 999;
		for(int i=0;i<jeu.nb_coups();i++){
			Jeu g(jeu.etat());
			if(!g.coup_licite(i)) continue;
			g.joue(i);
			val = min(val, minimax(g,E));
		}
		return val;
	}
}

void Joueur_AlphaBeta_::recherche_coup(Jeu jeu, int &coup)
{
	int val=-999;
	for(int i=0;i<jeu.nb_coups();i++){
		Jeu g(jeu.etat());
		if(!g.coup_licite(i)) continue;
		g.joue(i);
		int mm = minimax(g,false);
		if(mm>val){
			coup=i;
			val=mm;
		}
	}
}
