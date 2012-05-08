#ifndef _FONCTIONSBDD_H
#define _FONCTIONSBDD_H

#include <mysql.h>
#include <mysql_embed.h>

extern MYSQL mysql;

extern void connexion_Bdd(char* adresse , char* user,char* pwd, char* bdd);

extern void requete_Bdd(char* requete);

#endif
