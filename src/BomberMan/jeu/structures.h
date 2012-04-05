#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_
//#include <mysql/mysql.h>
//#include <mysql/mysql_embed.h>

//extern MYSQL mysql;

typedef struct 
{
	char *typeCase;
	char *typeJoueur;
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
	char *idJoueur;
	char *typeJoueur;
	int firePlus;
	int fireMoins;
	int bombePlus;
	int bombeMoins;
	int nbBombe;
	int idCarte;
} Joueur;

typedef struct 
{
  Joueur joueur[ 10 ];
  Carte carte;
} Jeu;

void initJeu( Jeu* j );
//void initCarte( Carte* c );
void initCarte(void);
int creationJoueur( Jeu jeu, int numJoueur );
int creationListeJoueur( Jeu jeu );
int creationMap( Jeu jeu );

#endif /* _STRUCTURES_H_ */

