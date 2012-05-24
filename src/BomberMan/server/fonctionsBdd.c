#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "fonctionsBdd.h"

MYSQL mysql;

void connexion_Bdd( char * adresse, char * user, char * pwd, char * bdd )
{

	mysql_init( &mysql );
	if( mysql_real_connect( &mysql, adresse, user, pwd, bdd, 0, NULL, 0 ) )
	{
		printf( "Connexion BDD reussie\n" );
				
	}
	else
	{
		printf( "Il y a une erreur de connexion a la BDD\n" );
	}
}

void requete_Bdd( char * requete )
{
	mysql_query( &mysql, requete );
}


