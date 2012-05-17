#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "../server/fonctionsBdd.h"

Jeu initMap( Jeu j )
{
	int x,y;
	//Requête qui sélectionne tout dans ma table scores
	mysql_query( &mysql, "SELECT * FROM cartes" );

	//Déclaration des pointeurs de structure
	MYSQL_RES * result = NULL;
	MYSQL_ROW * row = NULL;

	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result( &mysql );

	//On récupère le nombre de champs
	num_champs = mysql_num_fields( result );
	//Tant qu'il y a encore un résultat ...
	while ( ( row = mysql_fetch_row( result ) ) )
	{
		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long * lengths;

		//On stocke cette taille dans le pointeur
		lengths = mysql_fetch_lengths( result );
		j.carte.idCarte = atoi( row[0] );
		j.carte.nbJoueur = atoi( row[1] );

	}
	return j;
}

Jeu initCarte( Jeu j )
{
	int x,y;
	//Requête qui sélectionne tout dans ma table scores
	mysql_query( &mysql, "SELECT * FROM cases" );

	//Déclaration des pointeurs de structure
	MYSQL_RES * result = NULL;
	MYSQL_ROW * row = NULL;

	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result( &mysql );

	//On récupère le nombre de champs
	num_champs = mysql_num_fields( result );
	//Tant qu'il y a encore un résultat ...
	while ( ( row = mysql_fetch_row( result ) ) )
	{
		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long * lengths;

		//On stocke cette taille dans le pointeur
		lengths = mysql_fetch_lengths( result );
		x = atoi( row[1] );
		y = atoi( row[2] );
		strcpy( j.carte.cases[x][y].typeCase, ( char * )row[3] );
		strcpy( j.carte.cases[x][y].typeJoueur, ( char * )row[6] );
		j.carte.cases[x][y].idBonus = atoi( row[4] );
		j.carte.cases[x][y].bombe = atoi( row[5] );
	}
	return j;
}

Jeu initJoueur( Jeu j )
{
	int x;
	//Requête qui sélectionne tout dans ma table scores
	mysql_query( &mysql, "SELECT * FROM joueur" );
	
	//Déclaration des pointeurs de structure
	MYSQL_RES * result = NULL;
	MYSQL_ROW * row = NULL;

	unsigned int num_champs = 0;

	//On met le jeu de résultat dans le pointeur result
	result = mysql_use_result( &mysql );

	//On récupère le nombre de champs
	num_champs = mysql_num_fields( result );

	//Tant qu'il y a encore un résultat ...
	while ( ( row = mysql_fetch_row( result ) ) )
	{
		//On déclare un pointeur long non signé pour y stocker la taille des valeurs
		unsigned long * lengths;

		//On stocke cette taille dans le pointeur
		lengths = mysql_fetch_lengths( result );
		x = atoi( row[0] );
		j.joueur[x].idJoueur = atoi( row[0] );
		strcpy( j.joueur[x].pseudo, ( char * )row[1] );
		strcpy( j.joueur[x].typeJoueur,( char * )row[2] );
		j.joueur[x].firePlus = atoi( row[3] );
		j.joueur[x].fireMoins = atoi( row[4] );
		j.joueur[x].bombePlus = atoi( row[5] );
		j.joueur[x].bombeMoins = atoi( row[6] );
		j.joueur[x].nbBombe = atoi( row[7] );
		j.joueur[x].idCarte = atoi( row[8] );
	}
	
	return j;
}

Jeu initJeu( void )
{
	Jeu j;
	j = initCarte( j );
	j = initJoueur( j );
	j = initMap( j );
	
	return j;
}

int creationJoueur( Jeu jeu, int numJoueur )
{
	FILE * fichierJoueur;  
    char nomFichier[25];
       
	sprintf( nomFichier, "FichierJoueur%d.txt", numJoueur ); 
	fichierJoueur = fopen( nomFichier, "w" ); 
	if( fichierJoueur ) 
	{ 
		fprintf( fichierJoueur, "Joueur %d\n", numJoueur );
		fprintf( fichierJoueur, "idJoueur=%d\npseudo=%s\ntypeJoueur=%s\nfirePlus=%d\nfireMoins=%d\nbombePlus=%d\nbombeMoins=%d\nnbBombe=%d\nidCarte=%d\n", jeu.joueur[numJoueur].idJoueur, jeu.joueur[numJoueur].pseudo, jeu.joueur[numJoueur].typeJoueur, jeu.joueur[numJoueur].firePlus, jeu.joueur[numJoueur].fireMoins, jeu.joueur[numJoueur].bombePlus, jeu.joueur[numJoueur].bombeMoins, jeu.joueur[numJoueur].nbBombe, jeu.joueur[numJoueur].idCarte );  
		fclose( fichierJoueur );  
	} 
	else
	{
		fprintf( stderr, "Erreur pour écrire %s\n", nomFichier );
		return 0;
	}	   
    return 1;  
}

int creationListeJoueur( Jeu jeu )
{
	FILE * fichierListeJoueur;
	FILE * fichierALire;  
    char nomFichier[25];
    char nomFichierLire[25]; 
    int i, result; 
    char  buffer[255];
	
	sprintf( nomFichier, "FichierListeJoueur.txt" ); 
	fichierListeJoueur = fopen( nomFichier, "w" ); 
	if( fichierListeJoueur ) 
	{ 
		for( i=1; i<((jeu.carte.nbJoueur)+1); i++ )
		{
			result = creationJoueur( jeu, i );
			if( result )
			{
				sprintf( nomFichierLire, "FichierJoueur%d.txt", i );
				fichierALire = fopen( nomFichierLire, "r" );
				if( fichierALire )
				{
					fread( buffer, sizeof( char ), 255, fichierALire );
					fclose( fichierALire );
					fprintf( fichierListeJoueur, "%s", buffer );
				}
			}
		}
		fclose( fichierListeJoueur ); 
		system( "rm -R FichierJoueur*" );
	} 
	else
	{
		fprintf( stderr, "Erreur pour écrire %s\n", nomFichier );
		return 0;
	}	   
    return 1;  
}

int creationMap( Jeu jeu )
{
	FILE * fichierMap;  
    char nomFichier[25]; 
    int i, j;
      
	sprintf( nomFichier, "FichierMap.txt" ); 
	fichierMap = fopen( nomFichier, "w" );  
	if( fichierMap ) 
	{ 
		fprintf( fichierMap, "Autre\n" );
		fprintf( fichierMap, "idCarte=%d\nnbJoueur=%d\n", jeu.carte.idCarte, jeu.carte.nbJoueur );
		for( i=0; i<6; i++ ) 
		{
			for( j=0; j<6; j++ ) 
			{
				fprintf( fichierMap, "CASE %d %d\n", i, j );
				fprintf( fichierMap, "typeCase=%s\ntypeJoueur=%s\nidBonus=%d\nbombe=%d\n", jeu.carte.cases[i][j].typeCase, jeu.carte.cases[i][j].typeJoueur, jeu.carte.cases[i][j].idBonus, jeu.carte.cases[i][j].bombe );
			}
		}
		fclose( fichierMap );  
	} 
	else
	{
		fprintf( stderr, "Erreur pour écrire %s\n", nomFichier );
		return 0;
	}	   
    return 1;  
}

Jeu fichierStructMap( Jeu jeu )
{
	FILE * fichier;
	int i, j, a, b;
	int count;
	char * array = NULL;
	size_t longueur = 255;
	
	for( i=0; i<6; i++ )
	{
		for( j=0; j<6; j++ )
		{
			if( ( fichier = fopen( "FichierMap.txt", "r" ) ) == NULL ) 
			{
				fprintf( stderr, "Erreur d'ouverture du fichier\n" );
			}
			while ( ( getline( &array, &longueur, fichier ) ) != -1 ) 
			{
				if( sscanf( array, "idCarte=%d", &( jeu.carte.idCarte ) ) == 1 )
				{
					//printf( "ok1\n" );
				}
				if(sscanf (array, "nbJoueur=%d", &( jeu.carte.nbJoueur ) ) == 1 )
				{
					//printf( "ok2\n" );
				}
				if( ( ( sscanf( array, "%*s %d %d", &a, &b ) ) == 2 ) && ( a == i ) && ( b == j ) )
				{
					count = 0;
					count++;
				}
				if( ( count >= 1 ) && ( count < 5 ) )
				{
					if( sscanf( array, "typeCase=%s", jeu.carte.cases[i][j].typeCase ) == 1 )
					{
						//printf( "ok3\n" );
						count++;
					}
					if( sscanf( array, "typeJoueur=%s", jeu.carte.cases[i][j].typeJoueur ) == 1 )
					{
						//printf( "ok4\n" );
						count++;
					}
					if( sscanf( array, "idBonus=%d", &( jeu.carte.cases[i][j].idBonus ) ) == 1 )
					{
						//printf( "ok5\n" );
						count++;
					}
					if( sscanf( array, "bombe=%d", &( jeu.carte.cases[i][j].bombe ) ) == 1 )
					{
						//printf( "ok6\n" );
						count++;
					}
				}
			}
			fclose( fichier );
		}
	}
	free( array );
	return jeu;
}

Jeu fichierStructJoueur( Jeu jeu )
{
	FILE * fichier;
	int i, a;
	int count;
	char *array = NULL;
	size_t longueur = 255;
	
	for( i=1; i<((jeu.carte.nbJoueur)+1); i++ )
	{
		if( ( fichier = fopen( "FichierListeJoueur.txt", "r" ) ) == NULL ) 
		{
			fprintf( stderr, "Erreur d'ouverture du fichier\n" );
		}
		while ( ( getline( &array, &longueur, fichier ) ) != -1 ) 
		{
			if( ( ( sscanf( array, "%*s %d", &a ) ) == 1 ) && ( a == i ) )
			{
				count = 0;
				count++;
			}
			if( ( count >= 1 ) && ( count < 10 ) )
			{
				if( sscanf( array, "idJoueur=%d", &( jeu.joueur[i].idJoueur ) ) == 1 )
				{
					//printf( "ok\n" );
					count++;
				}
				if( sscanf( array, "pseudo=%s", jeu.joueur[i].pseudo ) == 1 )
				{
					//printf( "okbis\n" );
					count++;
				}
				if( sscanf( array, "typeJoueur=%s", jeu.joueur[i].typeJoueur ) == 1 )
				{
					//printf( "ok2\n" );
					count++;
				}
				if(sscanf(array, "firePlus=%d", &( jeu.joueur[i].firePlus ) ) == 1)
				{
					//printf( "ok3\n" );
					count++;
				}
				if( sscanf( array, "fireMoins=%d", &( jeu.joueur[i].fireMoins ) ) == 1 )
				{
					//printf( "ok4\n" );
					count++;
				}
				if( sscanf( array, "bombePlus=%d", &( jeu.joueur[i].bombePlus ) ) == 1 )
				{
					//printf( "ok5\n" );
					count++;
				}
				if( sscanf( array, "bombeMoins=%d", &( jeu.joueur[i].bombeMoins ) ) == 1 )
				{
					//printf( "ok6\n" );
					count++;
				}
				if( sscanf( array, "nbBombe=%d", &( jeu.joueur[i].nbBombe ) ) == 1 )
				{
					//printf( "ok7\n" );
					count++;
				}
				if( sscanf( array, "idCarte=%d", &( jeu.joueur[i].idCarte ) ) == 1 )
				{
					//printf( "ok8\n" );
					count++;
				}
			}
		}
		fclose( fichier );
	}
	free( array );
	return jeu;
}
