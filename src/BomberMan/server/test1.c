#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "fonctionsBdd.h"



int main(void)
{
	//struct carte
	//{
		//int cases[50][50];
		//char * typecase;
		//int idbonus;
		//char* idjoueur;
		//int bombe;
	//}
	
	
	
	
	
	
	
	connexion_Bdd("127.0.0.1","root","projet","bddprojet");
	init_carte();
	//requete_Bdd("CREATE TABLE user21(nom TEXT,prenom TEXT) \n");
	return 0;
}
