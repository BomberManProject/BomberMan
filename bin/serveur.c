#include <stdio.h>
#include <string.h>
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/jeu/structures.c"

int main( int argc, char *argv[] )
{
	Jeu j;
	
	
	/*j.joueur[0].idJoueur=malloc(sizeof (char)*25);
	j.joueur[0].idJoueur=NULL;
	j.joueur[0].typeJoueur=malloc(sizeof (char)*25);
	j.joueur[0].typeJoueur=NULL;
		
	j.joueur[1].idJoueur=malloc(sizeof (char)*25);
	j.joueur[1].idJoueur=NULL;
	j.joueur[1].typeJoueur=malloc(sizeof (char)*25);
	j.joueur[1].typeJoueur=NULL;
	*/
	/*j.carte.cases[0][0].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[0][0].typeCase=NULL;
	j.carte.cases[0][0].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[0][0].typeJoueur=NULL;
		
	j.carte.cases[0][1].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[0][1].typeCase=NULL;
	j.carte.cases[0][1].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[0][1].typeJoueur=NULL;
	
	j.carte.cases[1][0].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[1][0].typeCase=NULL;
	j.carte.cases[1][0].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[1][0].typeJoueur=NULL;
	
	j.carte.cases[1][1].typeCase=malloc(sizeof (char)*25);
	j.carte.cases[1][1].typeCase=NULL;
	j.carte.cases[1][1].typeJoueur=malloc(sizeof (char)*25);
	j.carte.cases[1][1].typeJoueur=NULL;
	*/
	j = fichierStructMap( );
	
	/*printf("idJoueur:%s\n", j.joueur[0].idJoueur);
		printf("typeJoueur:%s\n", j.joueur[0].typeJoueur);
		printf("firePlus:%d\n", j.joueur[0].firePlus);
		printf("fireMoins:%d\n", j.joueur[0].fireMoins);
		printf("bombePlus:%d\n", j.joueur[0].bombePlus);
		printf("bombeMoins:%d\n", j.joueur[0].bombeMoins);
		printf("nbBombe:%d\n", j.joueur[0].nbBombe);
		printf("idCarte:%d\n", j.joueur[0].idCarte);
		printf("\n\n");
		printf("idJoueur:%s\n", j.joueur[1].idJoueur);
		printf("typeJoueur:%s\n", j.joueur[1].typeJoueur);
		printf("firePlus:%d\n", j.joueur[1].firePlus);
		printf("fireMoins:%d\n", j.joueur[1].fireMoins);
		printf("bombePlus:%d\n", j.joueur[1].bombePlus);
		printf("bombeMoins:%d\n", j.joueur[1].bombeMoins);
		printf("nbBombe:%d\n", j.joueur[1].nbBombe);
		printf("idCarte:%d\n", j.joueur[1].idCarte);
		*/
		
		printf("nbJoueur:%d\n", j.carte.nbJoueur);
		printf("idCarte:%d\n", j.carte.idCarte);
		printf("\n");
		printf("typeCase:%s\n", j.carte.cases[0][0].typeCase);
		printf("typeJoueur:%s\n", j.carte.cases[0][0].typeJoueur);
		printf("idBonus:%d\n", j.carte.cases[0][0].idBonus);
		printf("bombe:%d\n", j.carte.cases[0][0].bombe);
		printf("\n");
		printf("typeCase:%s\n", j.carte.cases[0][1].typeCase);
		printf("typeJoueur:%s\n", j.carte.cases[0][1].typeJoueur);
		printf("idBonus:%d\n", j.carte.cases[0][1].idBonus);
		printf("bombe:%d\n", j.carte.cases[0][1].bombe);
		printf("\n");
		printf("typeCase:%s\n", j.carte.cases[1][0].typeCase);
		printf("typeJoueur:%s\n", j.carte.cases[1][0].typeJoueur);
		printf("idBonus:%d\n", j.carte.cases[1][0].idBonus);
		printf("bombe:%d\n", j.carte.cases[1][0].bombe);
		printf("\n");
		printf("typeCase:%s\n", j.carte.cases[1][1].typeCase);
		printf("typeJoueur:%s\n", j.carte.cases[1][1].typeJoueur);
		printf("idBonus:%d\n", j.carte.cases[1][1].idBonus);
		printf("bombe:%d\n", j.carte.cases[1][1].bombe);
	
	
	return 0;
}
