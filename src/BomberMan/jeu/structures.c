#include <stdio.h>
//#include "BomberMan/jeu/structures.h"
#include "structures.h"

int creationFichier( Jeu j )
{
	FILE * fichier;  
    char filename[255];   
	sprintf((char *) &filename, "Fichier.txt"); // penser à l'endroit où est créé le fichier pour qu'il soit utilisé par d'autres fonctions
	fichier = fopen(filename, "a");  
	if (fichier) 
	{ 
		//int i, j;
		//for (i=0;i<j.carte.nbJoueur;i++)
		//{
			//fprintf(fichier,"#Joueur%d\n", i);
			fprintf(fichier,"idJoueur=%s\ntypeJoueur=%s\nnumCarte=%d\nfirePlus=%d\nfireMoins=%d\nbombePlus=%d\nbombeMoins=%d\nnbBombe=%d\nidCarte=%d\n", j.joueur.idJoueur, j.joueur.typeJoueur, j.joueur.numCarte, j.joueur.firePlus, j.joueur.fireMoins, j.joueur.bombePlus, j.joueur.bombeMoins, j.joueur.nbBombe, j.joueur.idCarte);  
		//}
		//for (j=0;j<4;j++)
		//{
			//fprintf(fichier,"#Case%d\n", j);
			fprintf(fichier,"caseX=%d\ncaseY=%d\ntypeCase=%s\ntypeJoueur=%s\nidBonus=%d\nbombe=%d\n", j.carte.cases.caseX, j.carte.cases.caseY, j.carte.cases.typeCase, j.carte.cases.typeJoueur, j.carte.cases.idBonus, j.carte.cases.bombe);
		//}
		fprintf(fichier,"#Autre\n");
		fprintf(fichier,"nbJoueur=%d\nidCarte=%d\n", j.carte.nbJoueur, j.carte.idCarte);
		fclose(fichier);  
	} 
	else
	{
		fprintf(stderr, "Erreur pour écrire %s\n", filename);
		return 0;
	}	   
    return 1;  
}

int creationMap( Jeu j )
{
	FILE * fichier;  
    char filename[255];   
	sprintf((char *) &filename, "FichierMap.txt"); // penser à l'endroit où est créé le fichier pour qu'il soit utilisé par d'autres fonctions
	fichier = fopen(filename, "a");  
	if (fichier) 
	{ 
		fprintf(fichier,"caseX=%d\ncaseY=%d\ntypeCase=%s\ntypeJoueur=%s\nidBonus=%d\nbombe=%d\n", j.carte.cases.caseX, j.carte.cases.caseY, j.carte.cases.typeCase, j.carte.cases.typeJoueur, j.carte.cases.idBonus, j.carte.cases.bombe);
		fclose(fichier);  
	} 
	else
	{
		fprintf(stderr, "Erreur pour écrire %s\n", filename);
		return 0;
	}	   
    return 1;  
}

int eraseMap()
{
	FILE * fichier;  
    char filename[255];   
	sprintf((char *) &filename, "FichierMap.txt"); // penser à l'endroit où est créé le fichier pour qu'il soit utilisé par d'autres fonctions
	fichier = fopen(filename, "w");  
	if (fichier) 
	{ 
		fclose(fichier);  
	} 
	else
	{
		return 0;
	}	   
    return 1;  
}
