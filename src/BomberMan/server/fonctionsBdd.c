#include <stdio.h>
#include <stdlib.h>
#include "fonctionsBdd.h"


MYSQL mysql;



void connexion_Bdd( char* adresse , char* user,char* pwd, char* bdd)
{

	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,adresse,user,pwd,bdd,0,NULL,0))
	{
		printf("connexion Bdd réussie \n");
				
	}else
	{
		printf("Aie il y a une erreur de connexion a la bdd \n");
	}
}

void requete_Bdd(char* requete)
{
	mysql_query(&mysql,requete);
}


