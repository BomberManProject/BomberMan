#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "fonctionsBdd.h"
#include "structure.h"


int main(void)
{

	
	
	
	connexion_Bdd("192.168.137.203","joueur","passwordjoueur","bddprojet");
	initJeu();
	return 0;
}
