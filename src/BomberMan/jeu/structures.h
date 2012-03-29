#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct 
{
  int cases[50][50];
  int idCarte;
  char typeCase[25];
  char typeJoueur[25];
  int idBonus;
  int bombe;
} Case;

typedef struct 
{
  Joueur joueur;
  Case caseJeu;
} Jeu;

typedef struct 
{
	char idJoueur[25];
	char typeJoueur[25];
	int numCarte;
	int firePlus;
	int fireMoins;
	int bombPlus;
	int bombMoins;
	int nbBomb;
	int idCarte;
} Joueur;
	
	
void initJeu( Jeu* j );
void initCarte( Carte* c );

#endif /* _STRUCTURES_H_ */
