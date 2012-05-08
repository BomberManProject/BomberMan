#include <stdio.h>
#include <mysql.h>
#include <mysql_embed.h>
#include "BomberMan/server/fonctionsBdd.h" // Penser a changer le chemin du fichier
#include "structures.h"


/*void initJeu( Jeu* j )
{
  initCarte( &(j->carte) );
}

void initCarte( Carte* c )
{
  int x, y;
  for ( x = 0; x < 100; ++x )
    for ( y = 0; y < 100; ++y )
      c->cases[ x ][ y ] = 0;
}*/

    
Jeu initCarte(void)
{
	Jeu j;
	int x,y;
	//Requête qui sélectionne tout dans ma table scores
	mysql_query(&mysql, "SELECT * FROM cases");

	//Déclaration des pointeurs de structure
	MYSQL_RES *result = NULL;
	MYSQL_ROW *row = NULL;

	unsigned int i = 0;
	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result(&mysql);

	//On récupère le nombre de champs
	num_champs = mysql_num_fields(result);
	//printf("plop\n");
	//Tant qu'il y a encore un résultat ...
	while ((row = mysql_fetch_row(result)))
	{
		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long *lengths;

		//On stocke cette taille dans le pointeur
		lengths = mysql_fetch_lengths(result);
		//printf("%s \n",row[2]);
		
		//printf("\n");
		//printf("%s %s\n",row[1],row[2]);
		x = atoi(row[1]);
		y = atoi(row[2]);
		j.carte.cases[x][y].typeCase=malloc(sizeof(char)*50);
		strcpy(j.carte.cases[x][y].typeCase,(char *)row[3]);
		
		
		j.carte.cases[x][y].typeJoueur=malloc(sizeof(char)*50);
		strcpy(j.carte.cases[x][y].typeJoueur,(char *)row[6]);
		
		
		j.carte.cases[x][y].idBonus=(int)row[4];
		j.carte.cases[x][y].bombe=(int)row[5];
		/*
		printf("lololol %d %d %s %s %s %s %s %s lololol\n",x,y,row[1],row[2], row[3],row[4],row[5],row[6]);
		*/
	
	}
	//mysql_free_result(result);
	//mysql_close(&mysql);
	/* TEEST */
	printf("%s  typeCase\n",j.carte.cases[42][1].typeCase); 
	printf("%s  typeJoueur\n",j.carte.cases[42][1].typeJoueur);
	printf("%s  idBonus\n",j.carte.cases[42][1].idBonus);
	printf("%s  bombe\n",j.carte.cases[42][1].bombe);
	
	
	return j;
}



Jeu initJoueur(Jeu* j)
{
	//Jeu j;
	int x;
	//Requête qui sélectionne tout dans ma table scores
	mysql_query(&mysql, "SELECT * FROM joueur");
	
	//Déclaration des pointeurs de structure
	MYSQL_RES *result = NULL;
	MYSQL_ROW *row = NULL;

	unsigned int i = 0;
	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result(&mysql);

	//On récupère le nombre de champs
	num_champs = mysql_num_fields(result);

	//Tant qu'il y a encore un résultat ...
	while ((row = mysql_fetch_row(result)))
	{
		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long *lengths;

		//On stocke cette taille dans le pointeur
		lengths = mysql_fetch_lengths(result);
		//printf("%s \n",row[2]);
		
		//printf("\n");
		//printf("%s %s\n",row[1],row[2]);
		x = atoi(row[0]);

		//j->joueurs[x].idJoueur=malloc(sizeof(char)*50);
		//strcpy(j->joueurs[x].idJoueur,(char *)row[0]);
		j->joueurs[x].idJoueur=(int)row[0];

				
		j->joueurs[x].pseudo=malloc(sizeof(char)*200);
		strcpy(j->joueurs[x].pseudo,(char *)row[1]);
	
		j->joueurs[x].typeJoueur=malloc(sizeof(char)*200);
		strcpy(j->joueurs[x].typeJoueur,(char *)row[2]);
		
		
		j->joueurs[x].firePlus=(int)row[3];
		j->joueurs[x].fireMoins=(int)row[4];
		j->joueurs[x].bombePlus=(int)row[5];
		j->joueurs[x].bombeMoins=(int)row[6];
		j->joueurs[x].nbBombe=(int)row[7];
		j->joueurs[x].idCarte=(int)row[8];
/*TEST*/
	printf("  idjoueur: %s\n",j->joueurs[x].idJoueur); 
	printf("  pseudo: %s\n",j->joueurs[x].pseudo);
	printf("  typeJoueur: %s\n",j->joueurs[x].typeJoueur);
	printf("  firePlus: %s\n",j->joueurs[x].firePlus);
	printf("  fireMoins: %s\n",j->joueurs[x].fireMoins);
	printf("  bombePlus: %s\n",j->joueurs[x].bombePlus);
	printf("  bombmoins: %s\n",j->joueurs[x].bombeMoins);
	printf("  nbBombe: %s\n",j->joueurs[x].nbBombe);
	printf("  idcarte: %s\n",j->joueurs[x].idCarte);	
	printf("----------------------------------- \n");		
	}
	int y =0;
	printf("%s  typeCase\n",j->carte.cases[x][y].typeCase); 
	printf("%s  typeJoueur\n",j->carte.cases[x][y].typeJoueur);
	printf("%s  idBonus\n",j->carte.cases[x][y].idBonus);
	printf("%s  bombe\n",j->carte.cases[x][y].bombe);
	printf("--------------------------------------- \n");
	
	return *j;
}




Jeu initJeu(void)
{
	Jeu j1,j2;
	j1=initCarte();
	j2=initJoueur(&j1);
	
	return j2;
}
