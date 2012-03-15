#ifndef _FONCTIONSBDD_H
#define _FONCTIONSBDD_H

extern void connexion_Bdd(char* adresse , char* user,char* pwd, char* bdd);

extern void requete_Bdd(char* requete);
extern void init_carte(void);
#endif
