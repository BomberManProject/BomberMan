#include <stdio.h>
#include <string.h>
#include "structures.h"

int creationJoueur( Jeu jeu, int numJoueur )
{
	FILE * fichierJoueur;  
    char nomFichier[255];
       
	sprintf((char *) &nomFichier, "FichierJoueur%d.txt", numJoueur); 
	fichierJoueur = fopen(nomFichier, "a"); //option "a" pour écrire à la fin du fichier 
	if (fichierJoueur) 
	{ 
		fprintf(fichierJoueur,"#Joueur%d\n", numJoueur);
		fprintf(fichierJoueur,"idJoueur=%s\ntypeJoueur=%s\nfirePlus=%d\nfireMoins=%d\nbombePlus=%d\nbombeMoins=%d\nnbBombe=%d\nidCarte=%d\n", jeu.joueur[numJoueur].idJoueur, jeu.joueur[numJoueur].typeJoueur, jeu.joueur[numJoueur].firePlus, jeu.joueur[numJoueur].fireMoins, jeu.joueur[numJoueur].bombePlus, jeu.joueur[numJoueur].bombeMoins, jeu.joueur[numJoueur].nbBombe, jeu.joueur[numJoueur].idCarte);  
		fclose(fichierJoueur);  
	} 
	else
	{
		fprintf(stderr, "Erreur pour écrire %s\n", nomFichier);
		return 0;
	}	   
    return 1;  
}

int creationListeJoueur( Jeu jeu )
{
	FILE * fichierListeJoueur;
	FILE * fichierALire;  
    char nomFichier[255];
    char nomFichierLire[255]; 
    int i, result, taille; 
    char * buffer;
	
	sprintf((char *) &nomFichier, "FichierListeJoueur.txt"); 
	fichierListeJoueur = fopen(nomFichier, "w"); 
	if (fichierListeJoueur) 
	{ 
		for (i=0;i<jeu.carte.nbJoueur;i++)
		{
			result = creationJoueur ( jeu, i );
			if (result)
			{
				sprintf((char *) &nomFichierLire, "FichierJoueur%d.txt", i);
				buffer=NULL;
				fichierALire=fopen(nomFichierLire,"r");
				if (fichierALire)
				{
					taille=255;
					buffer=malloc(sizeof (char)*taille);
					fread(buffer,sizeof (char),taille,fichierALire);
					fclose(fichierALire);
					fprintf(fichierListeJoueur, "%s\n", buffer);
					free(buffer);
				}
			}
		}
		fclose(fichierListeJoueur); 
		system("rm -R FichierJoueur*");
		system("rm client");
	} 
	else
	{
		fprintf(stderr, "Erreur pour écrire %s\n", nomFichier);
		return 0;
	}	   
    return 1;  
}

int creationMap( Jeu jeu )
{
	FILE * fichierMap;  
    char nomFichier[255]; 
    int i, j;
      
	sprintf((char *) &nomFichier, "FichierMap.txt"); 
	fichierMap = fopen(nomFichier, "w");  
	if (fichierMap) 
	{ 
		fprintf(fichierMap,"#Autre\n");
		fprintf(fichierMap,"idCarte=%d\nnbJoueur=%d\n", jeu.carte.idCarte, jeu.carte.nbJoueur);
		for (i=0;i<2;i++) //jusqu'à 100 normalement
		{
			for (j=0;j<2;j++) //jusqu'à 100 normalement
			{
				fprintf(fichierMap,"#Case [%d][%d]\n", i, j);
				fprintf(fichierMap,"typeCase=%s\ntypeJoueur=%s\nidBonus=%d\nbombe=%d\n", jeu.carte.cases[i][j].typeCase, jeu.carte.cases[i][j].typeJoueur, jeu.carte.cases[i][j].idBonus, jeu.carte.cases[i][j].bombe);
			}
		}
		fclose(fichierMap);  
	} 
	else
	{
		fprintf(stderr, "Erreur pour écrire %s\n", nomFichier);
		return 0;
	}	   
    return 1;  
}
