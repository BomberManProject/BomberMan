#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include "../src/BomberMan/graph/fonctionGTK.h"
#include "../src/BomberMan/jeu/structures.h"
#include "../src/BomberMan/server/fonctionsBdd.h"

Jeu etatJeu;
int yaFichier = 0;
char demande[ 25 ];

void * reception( void * arg )
{
	int val_sem;
	sem_t * sem = ( sem_t * ) arg;
	while( 1 )
	{
		sem_getvalue( sem, &val_sem );
		if( ( strcmp( "joueurs", demande ) == 0 ) && ( val_sem == 0 ) )
		{
			sem_post( sem );
		}
		if( ( strcmp( "carte", demande ) == 0 ) && ( val_sem == 0 ) )
		{
			sem_post( sem );
		}
		if( ( strcmp( "tous", demande ) == 0 ) && ( val_sem == 0 ) )
		{
			sem_post( sem );
		}
		if( ( strcmp( "joueur", demande ) == 0 ) && ( val_sem == 0 ) && ( yaFichier == 1 ) )
		{
			sem_post( sem );
		}
		if( ( strcmp( "map", demande ) == 0 ) && ( val_sem == 0 ) && ( yaFichier == 1 ) )
		{
			sem_post( sem );
		}
		if( ( strcmp( "tout", demande ) == 0 ) && ( val_sem == 0 ) && ( yaFichier == 1 ) )
		{
			sem_post( sem );
		}
	}
}

void * traitement( void * arg )
{
	int i, j, k, l, m, n, val_sem;
	sem_t * sem = ( sem_t * ) arg;
	while( 1 )
	{
		sem_getvalue( sem, &val_sem );
		if( val_sem == 1 )
		{
			if( yaFichier == 1 )
			{
				if( strcmp( "joueur", demande ) == 0 )
				{
					etatJeu = fichierStructJoueur( etatJeu );
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierListeJoueur.txt" );
					sem_wait( sem );
					yaFichier = 0;
					for( i=1;i<(etatJeu.carte.nbJoueur)+1;i++ )
					{
						printf( "JOUEUR %d:\n", i );
						printf( "idJoueur : %d\n", etatJeu.joueur[i].idJoueur );
						printf( "pseudo : %s\n", etatJeu.joueur[i].pseudo );
						printf( "typeJoueur : %s\n", etatJeu.joueur[i].typeJoueur );
						printf( "firePlus : %d\n", etatJeu.joueur[i].firePlus );
						printf( "fireMoins : %d\n", etatJeu.joueur[i].fireMoins );
						printf( "bombePlus : %d\n", etatJeu.joueur[i].bombePlus );
						printf( "bombeMoins : %d\n", etatJeu.joueur[i].bombeMoins );
						printf( "nbBombe : %d\n", etatJeu.joueur[i].nbBombe );
						printf( "idCarte : %d\n", etatJeu.joueur[i].idCarte );
						printf( "\n" );
					}
				}
				if( strcmp( "map", demande ) == 0 )
				{
					etatJeu = fichierStructMap( etatJeu );
					system( "./testgtk &" );
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierMap.txt" );
					sem_wait( sem );
					yaFichier = 0;
					printf( "idCarte : %d\n", etatJeu.carte.idCarte );
					printf( "nbJoueur : %d\n", etatJeu.carte.nbJoueur );
					printf( "\n" );
					for( j=0;j<10;j++ )
					{
						for( k=0;k<10;k++ )
						{
							printf( "CASE [ %d ] [ %d ]\n", j, k );
							printf( "typeCase : %s\n", etatJeu.carte.cases[j][k].typeCase );
							printf( "idBonus : %d\n", etatJeu.carte.cases[j][k].idBonus );
							printf( "bombe : %d\n", etatJeu.carte.cases[j][k].bombe );
							printf( "\n" );
						}
					}
				}
				if( strcmp( "tout", demande ) == 0 )
				{
					etatJeu = fichierStructMap( etatJeu );
					etatJeu = fichierStructJoueur( etatJeu );
					system( "./testgtk &" );
					strcpy( demande, "AUCUNE" );
					//system( "rm -R FichierListeJoueur.txt" );
					//system( "rm -R FichierMap.txt" );
					sem_wait( sem );
					yaFichier = 0;
					for( l=1;l<(etatJeu.carte.nbJoueur)+1;l++ )
					{
						printf( "JOUEUR %d:\n", l );
						printf( "idJoueur : %d\n", etatJeu.joueur[l].idJoueur );
						printf( "pseudo : %s\n", etatJeu.joueur[l].pseudo );
						printf( "typeJoueur : %s\n", etatJeu.joueur[l].typeJoueur );
						printf( "firePlus : %d\n", etatJeu.joueur[l].firePlus );
						printf( "fireMoins : %d\n", etatJeu.joueur[l].fireMoins );
						printf( "bombePlus : %d\n", etatJeu.joueur[l].bombePlus );
						printf( "bombeMoins : %d\n", etatJeu.joueur[l].bombeMoins );
						printf( "nbBombe : %d\n", etatJeu.joueur[l].nbBombe );
						printf( "idCarte : %d\n", etatJeu.joueur[l].idCarte );
						printf( "\n" );
					}
					printf( "\n" );
					printf( "idCarte : %d\n", etatJeu.carte.idCarte );
					printf( "nbJoueur : %d\n", etatJeu.carte.nbJoueur );
					printf( "\n" );
					for( m=0;m<10;m++ )
					{
						for( n=0;n<10;n++ )
						{
							printf( "CASE [ %d ] [ %d ]\n", m, n );
							printf( "typeCase : %s\n", etatJeu.carte.cases[m][n].typeCase );
							printf( "idBonus : %d\n", etatJeu.carte.cases[m][n].idBonus );
							printf( "bombe : %d\n", etatJeu.carte.cases[m][n].bombe );
							printf( "\n" );
						}
					}
				}
			}
			if( strcmp( "joueurs", demande ) == 0 )
			{
				//Envoi grace à TCP au serveur
				printf( "Demande envoyee au serveur: %s\n", demande );
				strcpy( demande, "AUCUNE" );
				sem_wait( sem );
			}
			if( strcmp( "carte", demande ) == 0 )
			{	
				//Envoi grace à TCP au serveur
				printf( "Demande envoyee au serveur: %s\n", demande );
				strcpy( demande, "AUCUNE" );
				sem_wait( sem );
			}
			if( strcmp( "tous", demande ) == 0 )
			{		
				//Envoi grace à TCP au serveur
				printf( "Demande envoyee au serveur: %s\n", demande );
				strcpy( demande, "AUCUNE" );
				sem_wait( sem );
			}
		}
	}
}

int main()
{
	pthread_t recep, tache;
	sem_t sem;
	sem_init( &sem, 0, 0 );
	// Si deuxieme arg egal NULL, alors attribut par defaut utilisé.
	// Troisieme arg egal fonction appelee et quatrieme arg egal param de la fonction déclaree avant.
	pthread_create( &recep, NULL, reception, &sem );
	pthread_create( &tache, NULL, traitement, &sem );
	
	while( 1 )
	{
		char result[ 10 ];
		printf( "Reception de fichier ou envoie de demande ( fichier/demande ):\n" );
		scanf( "%s", result );
		if( strcmp( "demande", result ) == 0 )
		{
			printf( "Demande:\n" );
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
	sem_destroy( &sem );
	return 0;
}
	
	
