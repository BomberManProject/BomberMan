#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "../src/BomberMan/server/fonctionsBdd.h"
#include "../src/BomberMan/jeu/structures.h"


int main( void )
{
	//connexion_Bdd( "192.168.137.203", "joueur", "passwordjoueur", "bddprojet" );
	connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
	initJeu( );
	return 0;
}
