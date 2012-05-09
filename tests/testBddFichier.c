#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/server/fonctionsBdd.h"

int main( void )
{
	Jeu jeuTest, jeuTest2;
	int result, result2;
	//connexion_Bdd( "192.168.137.203", "joueur", "passwordjoueur", "bddprojet" );
	connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
	jeuTest = initJeu( );
	result = creationListeJoueur( jeuTest );
	result2 = creationMap( jeuTest );
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
	
	jeuTest2 = fichierStructMap( jeuTest2 );
	
	printf("idCarte:%d\n", jeuTest2.carte.idCarte);
	printf("nbJoueur:%d\n", jeuTest2.carte.nbJoueur);
	printf("\n");
	printf("typeCase:%s\n", jeuTest2.carte.cases[0][0].typeCase);
	printf("typeJoueur:%s\n", jeuTest2.carte.cases[0][0].typeJoueur);
	printf("idBonus:%d\n", jeuTest2.carte.cases[0][0].idBonus);
	printf("bombe:%d\n", jeuTest2.carte.cases[0][0].bombe);
	printf("\n");
	printf("typeCase:%s\n", jeuTest2.carte.cases[0][1].typeCase);
	printf("typeJoueur:%s\n", jeuTest2.carte.cases[0][1].typeJoueur);
	printf("idBonus:%d\n", jeuTest2.carte.cases[0][1].idBonus);
	printf("bombe:%d\n", jeuTest2.carte.cases[0][1].bombe);
	printf("\n");
	printf("typeCase:%s\n", jeuTest2.carte.cases[1][0].typeCase);
	printf("typeJoueur:%s\n", jeuTest2.carte.cases[1][0].typeJoueur);
	printf("idBonus:%d\n", jeuTest2.carte.cases[1][0].idBonus);
	printf("bombe:%d\n", jeuTest2.carte.cases[1][0].bombe);
	printf("\n");
	printf("typeCase:%s\n", jeuTest2.carte.cases[1][1].typeCase);
	printf("typeJoueur:%s\n", jeuTest2.carte.cases[1][1].typeJoueur);
	printf("idBonus:%d\n", jeuTest2.carte.cases[1][1].idBonus);
	printf("bombe:%d\n", jeuTest2.carte.cases[1][1].bombe);
	printf("\n\n");
	
	jeuTest2 = fichierStructJoueur( jeuTest2 );
	
	printf("idJoueur:%d\n", jeuTest2.joueur[1].idJoueur);
	printf("pseudo:%s\n", jeuTest2.joueur[1].pseudo);
	printf("typeJoueur:%s\n", jeuTest2.joueur[1].typeJoueur);
	printf("firePlus:%d\n", jeuTest2.joueur[1].firePlus);
	printf("fireMoins:%d\n", jeuTest2.joueur[1].fireMoins);
	printf("bombePlus:%d\n", jeuTest2.joueur[1].bombePlus);
	printf("bombeMoins:%d\n", jeuTest2.joueur[1].bombeMoins);
	printf("nbBombe:%d\n", jeuTest2.joueur[1].nbBombe);
	printf("idCarte:%d\n", jeuTest2.joueur[1].idCarte);
	printf("\n");
	printf("idJoueur:%d\n", jeuTest2.joueur[2].idJoueur);
	printf("pseudo:%s\n", jeuTest2.joueur[2].pseudo);
	printf("typeJoueur:%s\n", jeuTest2.joueur[2].typeJoueur);
	printf("firePlus:%d\n", jeuTest2.joueur[2].firePlus);
	printf("fireMoins:%d\n", jeuTest2.joueur[2].fireMoins);
	printf("bombePlus:%d\n", jeuTest2.joueur[2].bombePlus);
	printf("bombeMoins:%d\n", jeuTest2.joueur[2].bombeMoins);
	printf("nbBombe:%d\n", jeuTest2.joueur[2].nbBombe);
	printf("idCarte:%d\n", jeuTest2.joueur[2].idCarte);
	
	return 0;
}
	
