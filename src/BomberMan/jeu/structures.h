#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct 
{
	int caseX;
	int caseY;
	char *typeCase;
	char *typeJoueur;
	int idBonus;
	int bombe;
} Case;

typedef struct 
{
	char *idJoueur;
	char *typeJoueur;
	int numCarte;
	int firePlus;
	int fireMoins;
	int bombePlus;
	int bombeMoins;
	int nbBombe;
	int idCarte;
} Joueur;

typedef struct 
{
	Case cases;
	int nbJoueur;
	int idCarte;
} Carte;

typedef struct 
{
	Joueur joueur;
	Carte carte;
} Jeu;
	
int creationFichier(Jeu j);

#endif /* _STRUCTURES_H_ */
