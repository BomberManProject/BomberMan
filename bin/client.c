#include <stdio.h>
#include <string.h>
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/jeu/structures.c"

int main( int argc, char *argv[] )
{
	Jeu j;
	int result, result2;
	 
	j.joueur[0].idJoueur=malloc(sizeof (char)*25);
	j.joueur[0].idJoueur="Toto";
	j.joueur[0].typeJoueur=malloc(sizeof (char)*25);
	j.joueur[0].typeJoueur="toto.jpg";
	j.joueur[0].firePlus=0;
	j.joueur[0].fireMoins=0;
	j.joueur[0].bombePlus=0;
	j.joueur[0].bombeMoins=0;
	j.joueur[0].nbBombe=5;
	j.joueur[0].idCarte=1;
	
	j.joueur[1].idJoueur=malloc(sizeof (char)*25);
	j.joueur[1].idJoueur="Titi";
	j.joueur[1].typeJoueur=malloc(sizeof (char)*25);
	j.joueur[1].typeJoueur="titi.jpg";
	j.joueur[1].firePlus=1;
	j.joueur[1].fireMoins=0;
	j.joueur[1].bombePlus=1;
	j.joueur[1].bombeMoins=0;
	j.joueur[1].nbBombe=7;
	j.joueur[1].idCarte=1;
	
	j.carte.nbJoueur=2; 
	j.carte.idCarte=1;
	
	j.carte.cases[0][0].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[0][0].typeCase="mur.jpg";
	j.carte.cases[0][0].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[0][0].typeJoueur="null";
	j.carte.cases[0][0].idBonus=0;
	j.carte.cases[0][0].bombe=0;
	
	j.carte.cases[0][1].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[0][1].typeCase="joueur.jpg";
	j.carte.cases[0][1].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[0][1].typeJoueur=j.joueur[0].typeJoueur;
	j.carte.cases[0][1].idBonus=1;
	j.carte.cases[0][1].bombe=0;
	
	j.carte.cases[1][0].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[1][0].typeCase="joueur.jpg";
	j.carte.cases[1][0].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[1][0].typeJoueur=j.joueur[1].typeJoueur;
	j.carte.cases[1][0].idBonus=0;
	j.carte.cases[1][0].bombe=1;
	
	j.carte.cases[1][1].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[1][1].typeCase="mur.jpg";
	j.carte.cases[1][1].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[1][1].typeJoueur="null";
	j.carte.cases[1][1].idBonus=0;
	j.carte.cases[1][1].bombe=0;
	
	result = creationListeJoueur( j );
	result2 = creationMap( j );
	if (result)
	{
		printf("OK\n");
	}
	else
	{
		printf("PB\n");
	}
	if (result2)
	{
		printf("OK\n");
	}
	else
	{
		printf("PB\n");
	}
	return 0;
}
