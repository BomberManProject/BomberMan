#include <stdio.h>
//#include "BomberMan/jeu/structures.h"
#include "structures.h"
#include "structures.c"
int main( int argc, char *argv[] )
{
	Jeu j;
	int result;
	int i =  0; 
	while (i<5) {
		j.joueur.idJoueur=malloc(sizeof (char)*25);
		j.joueur.idJoueur="Toto";
		j.joueur.typeJoueur=malloc(sizeof (char)*25);
		j.joueur.typeJoueur="toto.jpg";
		j.joueur.numCarte=1;
		j.joueur.firePlus=0;
		j.joueur.fireMoins=0;
		j.joueur.bombePlus=0;
		j.joueur.bombeMoins=0;
		j.joueur.nbBombe=5;
		j.joueur.idCarte=1;
		j.carte.cases.caseX=0;
		j.carte.cases.caseY=0;
		j.carte.cases.typeCase=malloc(sizeof (char)*25);
		j.carte.cases.typeCase="mur.jpg";
		j.carte.cases.typeJoueur=malloc(sizeof (char)*25);
		j.carte.cases.typeJoueur="null";
		j.carte.cases.idBonus=0;
		j.carte.cases.bombe=0;
		j.carte.nbJoueur=1;
		j.carte.idCarte=1;	
		result = creationFichier( j );
		if (result)
		{
			printf("OK\n");
		}
		else
		{
			printf("PB\n");
		}
		i++;
	}
	return 0;
}
