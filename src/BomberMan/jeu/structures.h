#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>

extern MYSQL mysql;

typedef struct {
	char *typeCase;
	char *typeJoueur;
	int idBonus;
	int bombe;
} Case;

typedef struct {
  Case cases[100][100];
  
  
} Carte;

// a modifier idjoueur == auto increment
// et rajouter champ pseudo dans Bdd

typedef struct {
	int idJoueur;
	char *pseudo;
	char *typeJoueur;
	int firePlus;
	int fireMoins;
	int bombePlus;
	int bombeMoins;
	int nbBombe;
	int idCarte;
} Joueur;




typedef struct {
  Joueur joueurs[10];
  Carte carte;
} Jeu;



Jeu initJeu(void);
Jeu initJoueur(Jeu* j);
//void initCarte( Carte* c );
Jeu initCarte(void);

#endif /* _STRUCTURES_H_ */

