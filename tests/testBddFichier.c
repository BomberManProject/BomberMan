#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/server/fonctionsBdd.h"

int main( void )
{
	int i, j, k;
	Jeu jeuTest, jeuTest2;
	int result, result2;
	connexion_Bdd( "192.168.137.203", "joueur", "passwordjoueur", "bddprojet" );
	//connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
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
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("typeCase[%d][%d]:%s\n", i,j,jeuTest2.carte.cases[i][j].typeCase);
			printf("idBonus:%d\n", jeuTest2.carte.cases[i][j].idBonus);
			printf("bombe:%d\n", jeuTest2.carte.cases[i][j].bombe);
			printf("\n");
		}
	}
	
	jeuTest2 = fichierStructJoueur( jeuTest2 );
	
	for( k=1;k<5;k++ )
	{
	printf("idJoueur:%d\n", jeuTest2.joueur[k].idJoueur);
	printf("pseudo:%s\n", jeuTest2.joueur[k].pseudo);
	printf("typeJoueur:%s\n", jeuTest2.joueur[k].typeJoueur);
	printf("firePlus:%d\n", jeuTest2.joueur[k].firePlus);
	printf("fireMoins:%d\n", jeuTest2.joueur[k].fireMoins);
	printf("bombePlus:%d\n", jeuTest2.joueur[k].bombePlus);
	printf("bombeMoins:%d\n", jeuTest2.joueur[k].bombeMoins);
	printf("nbBombe:%d\n", jeuTest2.joueur[k].nbBombe);
	printf("idCarte:%d\n", jeuTest2.joueur[k].idCarte);
	printf("\n");
}	
	return 0;
}
	
