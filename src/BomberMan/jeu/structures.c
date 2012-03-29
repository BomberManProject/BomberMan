#include <stdio.h>
#include "BomberMan/jeu/structures.h"

void initJeu( Jeu* j )
{
  initCarte( &(j->carte) );
}

void initCarte( Carte* c )
{
  int x, y;
  for ( x = 0; x < 100; ++x )
    for ( y = 0; y < 100; ++y )
      c->cases[ x ][ y ] = 0;
}


    
