#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>

extern MYSQL mysql;

typedef struct 
{
	char typeCase[50];
	char typeJoueur[50];
	int idBonus;
	int bombe;
} Case;

typedef struct 
{
  Case cases[100][100];
  int idCarte;
  int nbJoueur;  
} Carte;

typedef struct 
{
	int idJoueur;
	char pseudo[50];
	char typeJoueur[50];
	int firePlus;
	int fireMoins;
	int bombePlus;
	int bombeMoins;
	int nbBombe;
	int idCarte;
} Joueur;

typedef struct 
{
  Joueur joueur[10];
  Carte carte;
} Jeu;

int creationJoueur( Jeu jeu, int numJoueur );
int creationListeJoueur( Jeu jeu );
int creationMap( Jeu jeu );
Jeu fichierStructJoueur( Jeu jeu );
Jeu fichierStructMap( Jeu jeu );

Jeu initJeu( void );
Jeu initJoueur( Jeu j );
Jeu initCarte( Jeu j );
Jeu initMap( Jeu j );

#endif /* _STRUCTURES_H_ */

