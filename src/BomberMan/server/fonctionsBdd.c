#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
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



void init_carte(void)
{
			//Requête qui sélectionne tout dans ma table scores
            mysql_query(&mysql, "SELECT * FROM carte1");

            //Déclaration des pointeurs de structure
            MYSQL_RES *result = NULL;
            MYSQL_ROW *row = NULL;

            unsigned int i = 0;
            unsigned int num_champs = 0;

            //On met le jeu de résultat dans le pointeur result
            result = mysql_use_result(&mysql);

            //On récupère le nombre de champs
            num_champs = mysql_num_fields(result);
printf("plop\n");
            //Tant qu'il y a encore un résultat ...
            while ((row = mysql_fetch_row(result)))
            {
                //On déclare un pointeur long non signé pour y stocker la taille des valeurs
                unsigned long *lengths;

                //On stocke cette taille dans le pointeur
                lengths = mysql_fetch_lengths(result);

                //On fait une boucle pour avoir la valeur de chaque champs
               for(i = 0; i < num_champs; i++)
               {
                   //On ecrit toutes les valeurs
                   printf("[%.*s] ", (int) lengths[i], row[i] ? (char *)row[i] : "NULL");
               }
               printf("\n");
            }

            //Libération du jeu de résultat
            mysql_free_result(result);

            //Fermeture de MySQL
            mysql_close(&mysql);
}
