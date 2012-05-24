#include <stdio.h>
#include <string.h>
#include "../src/BomberMan/jeu/structures.h"

int main( void )
{
	Jeu j;
	int result, result2;
	 
	j.joueur[1].idJoueur=4;
	strcpy(j.joueur[1].pseudo, "Toto");
	strcpy(j.joueur[1].typeJoueur, "toto.jpg");
	j.joueur[1].firePlus=0;
	j.joueur[1].fireMoins=0;
	j.joueur[1].bombePlus=0;
	j.joueur[1].bombeMoins=0;
	j.joueur[1].nbBombe=2;
	j.joueur[1].idCarte=1;
	
	j.joueur[2].idJoueur=7;
	strcpy(j.joueur[2].pseudo, "Titi");
	strcpy(j.joueur[2].typeJoueur, "titi.jpg");
	j.joueur[2].firePlus=1;
	j.joueur[2].fireMoins=0;
	j.joueur[2].bombePlus=1;
	j.joueur[2].bombeMoins=0;
	j.joueur[2].nbBombe=7;
	j.joueur[2].idCarte=1;
	
	j.carte.nbJoueur=2; 
	j.carte.idCarte=1;
	
	strcpy(j.carte.cases[0][0].typeCase, "mur.jpg");
	j.carte.cases[0][0].idBonus=0;
	j.carte.cases[0][0].bombe=0;
	
	strcpy(j.carte.cases[0][1].typeCase, "mario.png");
	j.carte.cases[0][1].idBonus=1;
	j.carte.cases[0][1].bombe=0;
	
	strcpy(j.carte.cases[1][0].typeCase, "luigi.png");
	j.carte.cases[1][0].idBonus=0;
	j.carte.cases[1][0].bombe=1;
	
	strcpy(j.carte.cases[1][1].typeCase, "couloir.png");
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
	//system("rm testStructFichier");
	return 0;
}

