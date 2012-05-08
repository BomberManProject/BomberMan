#include <stdio.h>
#include <stdlib.h>
#include "BomberMan/server/fonctionsBdd.h"
#include "BomberMan/jeu/structures.h"


int main(void)
{

	connexion_Bdd("192.168.137.203","joueur","passwordjoueur","bddprojet");
	initJeu();
	return 0;
}
