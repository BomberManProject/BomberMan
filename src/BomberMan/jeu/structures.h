#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

typedef struct {
  int cases[100][100];
  
} Carte;

typedef struct {
  int joueur[ 10 ];
  Carte carte;
} Jeu;

void initJeu( Jeu* j );
void initCarte( Carte* c );

#endif /* _STRUCTURES_H_ */
