#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mysql/mysql.h>
#include <mysql/mysql_embed.h>
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/server/fonctionsBdd.h"

Jeu jeu;
Jeu etatJeu;
int yaFichier = 0;
int occupation = 0;
char demande[ 25 ];
int ok = 0;

void * reception( )
{
	int result;
	while( 1 )
	{
		if( ( strcmp( "joueur", demande ) == 0 ) && ( occupation == 0 ) )
		{
			occupation = 1;
			ok = 1;
		}
		if( ( strcmp( "map", demande ) == 0 ) && ( occupation == 0 ) )
		{
			occupation = 1;
			ok = 1;
		}
		if( ( strcmp( "init", demande ) == 0 ) && ( occupation == 0 ) )
		{
			occupation = 1;
			ok = 1;
		}
		if( ( strcmp( "joueurs", demande ) == 0 ) && ( occupation == 0 ) && ( yaFichier == 1 ) )
		{
			occupation = 1;
			ok = 1;
		}
		if( ( strcmp( "carte", demande ) == 0 ) && ( occupation == 0 ) && ( yaFichier == 1 ) )
		{
			occupation = 1;
			ok = 1;
		}
		if( ( strcmp( "tout", demande ) == 0 ) && ( occupation == 0 ) && ( yaFichier == 1 ) )
		{
			occupation = 1;
			ok = 1;
		}
	}
}

void * traitement( )
{
	int result, result2;
	while( 1 )
	{
		if( ( occupation == 1 ) && ( ok == 1 ) )
		{
			if( strcmp( "joueur", demande ) == 0 )
			{
				connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
				jeu = initMap( jeu );
				jeu = initJoueur( jeu );
				result = creationListeJoueur( jeu );
				if( result )
				{
					printf( "Fichier FichierListeJoueur.txt cree.\n" );
				}
				else
				{
					printf( "Erreur creation fichier.\n" );
				}
				/* ENVOIE DU FICHIER !!! */
				strcpy( demande, "AUCUNE" );
				//system( "rm -R FichierListeJoueur.txt" );
				occupation = 0;
				ok = 0;
			}
			if( strcmp( "map", demande ) == 0 )
			{	
				connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
				jeu = initMap( jeu );
				jeu = initCarte( jeu );
				result = creationMap( jeu );
				if( result )
				{
					printf( "Fichier FichierMap.txt cree.\n" );
				}
				else
				{
					printf( "Erreur creation fichier.\n" );
				}
				/* ENVOIE DU FICHIER !!! */
				strcpy( demande, "AUCUNE" );
				//system( "rm -R FichierMap.txt" );
				occupation = 0;
				ok = 0;
			}
			if( strcmp( "init", demande ) == 0 )
			{		
				connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
				jeu = initJeu( );
				result = creationMap( jeu );
				if( result )
				{
					printf( "Fichier FichierMap.txt cree.\n" );
				}
				else
				{
					printf( "Erreur creation fichier.\n" );
				}
				result2 = creationListeJoueur( jeu );
				if( result2 )
				{
					printf( "Fichier FichierListeJoueur.txt cree.\n" );
				}	
				else
				{
					printf( "Erreur creation fichier.\n" );
				}
				/* ENVOIE DES FICHIERS !!! */
				strcpy( demande, "AUCUNE" );
				//system( "rm -R FichierMap.txt" );
				//system( "rm -R FichierListeJoueur.txt" );
				occupation = 0;
				ok = 0;
			}
			if( yaFichier == 1 )
			{
				if( strcmp( "joueurs", demande ) == 0 )
				{
					connexion_Bdd( "127.0.0.1", "joueur", "passwordjoueur", "bddprojet" );
					etatJeu = initMap( etatJeu );
					etatJeu = fichierStructJoueur( etatJeu );
					/* ENVOIE A LA BDD !!! */
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierListeJoueur.txt" );
					occupation = 0;
					ok = 0;
					yaFichier = 0;
					printf( "idJoueur : %d\n", etatJeu.joueur[1].idJoueur );
					printf( "pseudo : %s\n", etatJeu.joueur[1].pseudo );
					printf( "typeJoueur : %s\n", etatJeu.joueur[1].typeJoueur );
					printf( "firePlus : %d\n", etatJeu.joueur[1].firePlus );
					printf( "fireMoins : %d\n", etatJeu.joueur[1].fireMoins );
					printf( "bombePlus : %d\n", etatJeu.joueur[1].bombePlus );
					printf( "bombeMoins : %d\n", etatJeu.joueur[1].bombeMoins );
					printf( "nbBombe : %d\n", etatJeu.joueur[1].nbBombe );
					printf( "idCarte : %d\n", etatJeu.joueur[1].idCarte );
					printf( "\n" );
					printf( "idJoueur : %d\n", etatJeu.joueur[2].idJoueur );
					printf( "pseudo : %s\n", etatJeu.joueur[2].pseudo );
					printf( "typeJoueur : %s\n", etatJeu.joueur[2].typeJoueur );
					printf( "firePlus : %d\n", etatJeu.joueur[2].firePlus );
					printf( "fireMoins : %d\n", etatJeu.joueur[2].fireMoins );
					printf( "bombePlus : %d\n", etatJeu.joueur[2].bombePlus );
					printf( "bombeMoins : %d\n", etatJeu.joueur[2].bombeMoins );
					printf( "nbBombe : %d\n", etatJeu.joueur[2].nbBombe );
					printf( "idCarte : %d\n", etatJeu.joueur[2].idCarte );
					printf( "\n" );
				}
				if( strcmp( "carte", demande ) == 0 )
				{
					etatJeu = fichierStructMap( etatJeu );
					/* ENVOIE A LA BDD !!! */
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierMap.txt" );
					occupation = 0;
					ok = 0;
					yaFichier = 0;
					printf( "idCarte : %d\n", etatJeu.carte.idCarte );
					printf( "nbJoueur : %d\n", etatJeu.carte.nbJoueur );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[0][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[0][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[0][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[0][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[1][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[1][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[1][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[1][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[2][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[2][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[2][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[2][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[3][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[3][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[3][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[3][0].bombe );
					printf( "\n" );
				}
				if( strcmp( "tout", demande ) == 0 )
				{
					etatJeu = fichierStructMap( etatJeu );
					etatJeu = fichierStructJoueur( etatJeu );
					/* ENVOIE A LA BDD !!! */
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierListeJoueur.txt" );
					occupation = 0;
					ok = 0;
					yaFichier = 0;
					printf( "idJoueur : %d\n", etatJeu.joueur[1].idJoueur );
					printf( "pseudo : %s\n", etatJeu.joueur[1].pseudo );
					printf( "typeJoueur : %s\n", etatJeu.joueur[1].typeJoueur );
					printf( "firePlus : %d\n", etatJeu.joueur[1].firePlus );
					printf( "fireMoins : %d\n", etatJeu.joueur[1].fireMoins );
					printf( "bombePlus : %d\n", etatJeu.joueur[1].bombePlus );
					printf( "bombeMoins : %d\n", etatJeu.joueur[1].bombeMoins );
					printf( "nbBombe : %d\n", etatJeu.joueur[1].nbBombe );
					printf( "idCarte : %d\n", etatJeu.joueur[1].idCarte );
					printf( "\n" );
					printf( "idJoueur : %d\n", etatJeu.joueur[2].idJoueur );
					printf( "pseudo : %s\n", etatJeu.joueur[2].pseudo );
					printf( "typeJoueur : %s\n", etatJeu.joueur[2].typeJoueur );
					printf( "firePlus : %d\n", etatJeu.joueur[2].firePlus );
					printf( "fireMoins : %d\n", etatJeu.joueur[2].fireMoins );
					printf( "bombePlus : %d\n", etatJeu.joueur[2].bombePlus );
					printf( "bombeMoins : %d\n", etatJeu.joueur[2].bombeMoins );
					printf( "nbBombe : %d\n", etatJeu.joueur[2].nbBombe );
					printf( "idCarte : %d\n", etatJeu.joueur[2].idCarte );
					printf( "\n\n" );
					printf( "idCarte : %d\n", etatJeu.carte.idCarte );
					printf( "nbJoueur : %d\n", etatJeu.carte.nbJoueur );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[0][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[0][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[0][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[0][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[1][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[1][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[1][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[1][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[2][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[2][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[2][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[2][0].bombe );
					printf( "\n" );
					printf( "typeCase : %s\n", etatJeu.carte.cases[3][0].typeCase );
					printf( "typeJoueur : %s\n", etatJeu.carte.cases[3][0].typeJoueur );
					printf( "idBonus : %d\n", etatJeu.carte.cases[3][0].idBonus );
					printf( "bombe : %d\n", etatJeu.carte.cases[3][0].bombe );
					printf( "\n" );
				}
			}
		}
	}
}

int main()
{
	pthread_t recep, tache;
	// Si deuxieme arg egal NULL, alors attribut par defaut utilisé.
	// Troisieme arg egal fonction appelee et quatrieme arg egal param de la fonction déclaree avant.
	pthread_create( &recep, NULL, reception, NULL );
	pthread_create( &tache, NULL, traitement, NULL );
	
	while( 1 )
	{
		char result[ 10 ];
		printf( "Demande ou envoie de fichier (demande/fichier):\n" );
		scanf( "%s", result );
		if( strcmp( "demande", result ) == 0 )
		{
			printf( "demande:\n" );
			scanf( "%s", demande );
			sleep( 1 );
		}
		if( strcmp( "fichier", result ) == 0 )
		{
			printf( "yaFichier:\n" );
			scanf( "%d", &yaFichier );
			printf( "Quel fichier ?\n" );
			scanf( "%s", demande );
			sleep( 1 );
		}
	}
	
	pthread_join( recep, NULL );
	pthread_join( tache, NULL );
	return 0;
}
	
	
