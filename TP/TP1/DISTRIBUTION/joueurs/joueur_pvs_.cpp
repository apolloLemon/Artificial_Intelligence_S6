#include "joueur_pvs_.h"

Joueur_PVS_::Joueur_PVS_(std::string nom, bool joueur)
    :Joueur(nom,joueur)
{}



char Joueur_PVS_::nom_abbrege() const
{
    return 'P';
}

typedef std::pair<int,movelist> pvs_return;
pvs_return PVS(Jeu jeu, bool E, int a, int b, movelist lpv) {
	if(jeu.fini())
		if(E) return std::make_pair(-1,std::stack<int>());
		else  return std::make_pair(1,std::stack<int>());
		
	int val;
	movelist mov;
	if(E){
		val = -999;

		if(!lpv.empty()){
			Jeu g(jeu.etat()); movelist l = lpv;

			int m =l.top();
			l.pop();
			g.joue(m);
			pvs_return abr = PVS(g,!E,a,b,l);
			if(abr.first>val){
				val = abr.first;
				mov = abr.second;
				mov.push(m);
			}
		}

		for(int i=0;i<jeu.nb_coups();i++){
			Jeu g(jeu.etat()); movelist l = lpv;
			g.joue(i);
			pvs_return abr = PVS(g,!E,a,b,l.pop());
			if(abr.first>val){
				val = abr.first;
				mov = abr.second;
				mov.push(i);
			}
			a = std::max(a,val);
			if(a>=b) break; 
		}
		return std::make_pair(val,mov);
	} else {
		val = 999;

		if(!lpv.empty()){
			Jeu g(jeu.etat()); movelist l = lpv;
			int m = l.top();
			l.pop();
			g.joue(m);
			pvs_return abr = PVS(g,!E,a,b,l);
			if(abr.first<val){
				val = abr.first;
				mov = abr.second;
				mov.push(m);
			}
		}

		for(int i=0;i<jeu.nb_coups();i++){
			Jeu g(jeu.etat()); movelist l = lpv;
			g.joue(i);
			pvs_return abr = PVS(g,!E,a,b,lpv.pop());
			if(abr.first<val){
				val = abr.first;
				mov = abr.second;
				mov.push(i);
			}
			b = std::min(b,val);
			if(b<=a) break;
		}
		return std::make_pair(val,mov);
	}
}

void Joueur_PVS_::recherche_coup(Jeu jeu, int &coup)
{
	/*
	int val=-999;
	for(int i=0;i<jeu.nb_coups();i++){
		Jeu g(jeu.etat());
		//if(!g.coup_licite(i)) continue;
		g.joue(i);
		int mm = alphabeta(g,false,-999,999);
		if(mm>val){
			coup=i;
			val=mm;
		}
	}
	*/
	pvs_return pvs = PVS(jeu, true,-999,999,pv); 
	pv = pvs.second; //private class attribute
	coup = pv.top();
}
