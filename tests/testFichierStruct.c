#include <stdio.h>
#include <string.h>
#include "../src/BomberMan/jeu/structures.h"

int main( void )
{
	Jeu j;
	
	j = fichierStructMap( j );
	
	printf("idCarte:%d\n", j.carte.idCarte);
	printf("nbJoueur:%d\n", j.carte.nbJoueur);
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
	printf("\n\n");
	
	j = fichierStructJoueur( j );
	
	printf("idJoueur:%d\n", j.joueur[1].idJoueur);
	printf("pseudo:%s\n", j.joueur[1].pseudo);
	printf("typeJoueur:%s\n", j.joueur[1].typeJoueur);
	printf("firePlus:%d\n", j.joueur[1].firePlus);
	printf("fireMoins:%d\n", j.joueur[1].fireMoins);
	printf("bombePlus:%d\n", j.joueur[1].bombePlus);
	printf("bombeMoins:%d\n", j.joueur[1].bombeMoins);
	printf("nbBombe:%d\n", j.joueur[1].nbBombe);
	printf("idCarte:%d\n", j.joueur[1].idCarte);
	printf("\n");
	printf("idJoueur:%d\n", j.joueur[2].idJoueur);
	printf("pseudo:%s\n", j.joueur[2].pseudo);
	printf("typeJoueur:%s\n", j.joueur[2].typeJoueur);
	printf("firePlus:%d\n", j.joueur[2].firePlus);
	printf("fireMoins:%d\n", j.joueur[2].fireMoins);
	printf("bombePlus:%d\n", j.joueur[2].bombePlus);
	printf("bombeMoins:%d\n", j.joueur[2].bombeMoins);
	printf("nbBombe:%d\n", j.joueur[2].nbBombe);
	printf("idCarte:%d\n", j.joueur[2].idCarte);
	
	//system("rm testFichierStruct");
	return 0;
}

