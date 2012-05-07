#include <stdio.h>
#include "BomberMan/jeu/structures.h"

int main( int argc, char** argv )
{
	Jeu j;
	printf( "Les choses serieuses commencent.\n" );
	initJeu( &j );
	return 0;
}
