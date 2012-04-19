#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#define INVALID_SOCKET -1

#define PORT 20000
#define SOCKET_ERROR -1

    
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;


int main(int argc, char *argv[])
{
  /***************************** VARIABLES ***************************************/
  SOCKET csock;  
  SOCKADDR_IN csocket;
  int retour_send=0,retour_recv=0;
  char chaine[256],reception[1000],ip[12],reponse;
  /*******************************************************************************/   
  

  /***************************** SOCKET ******************************************/
  csock = socket(AF_INET, SOCK_STREAM, 0);   //création du socket : Conexion distante, TCP, 0->TCP 												(défaut)
  if(csock==INVALID_SOCKET)
  {
     puts("**Erreur de creation du socket**\n");
  }
  else
  {
      puts("**Socket cree\n");
  }
  /*******************************************************************************/
  
	//printf ("Entrer l'adresse IP a contacter : ");
	//gets(ip);

  /***************Configuration de la connexion **********************************/
        csocket.sin_addr.s_addr = inet_addr("127.0.0.1");  //ip du poste à joindre
        csocket.sin_family = AF_INET;
        csocket.sin_port = htons(PORT);
  /*******************************************************************************/

  
  
  /***************************Connection******************************************/
	 if (      connect(csock, (SOCKADDR*)&csocket,sizeof(csocket)) != SOCKET_ERROR )
        {
         printf ("Connexion a %s sur le port %d\n", inet_ntoa(csocket.sin_addr), htons (csocket.sin_port));
        }
     else
         {
         printf ("Connexion impossible !!!\n");
         }
  /*******************************************************************************/

do
{
  /***************************SEND***********************************************/
  //printf("Message envoye : %s \n", chaine);
  printf ("Saisir votre message :");
  gets (chaine);
  printf("Message envoye : %s", chaine);


  retour_send=send(csock, chaine, sizeof(chaine), 0);  //socket de DESTINATION, chaine de caractère, taille de la chaine, TCP (envoi normal)
  if(retour_send == SOCKET_ERROR)
  {
   	printf("\nErreur d'envoi des donnees !\n\n");
  }
  else
  {
    	printf("\nDonnees envoyees correctement\n\n");
  }
 /*******************************************************************************/
  
  printf ("Voulez-vous continuer a écrire ? \n yes or no\n");
  reponse=getchar();
} while (reponse== 'y');       
  /***************************RECEIVE**********************************************/
  retour_recv=recv(csock, reception, sizeof(reception), 0);  

  if(retour_recv == SOCKET_ERROR)
  {
   	printf("\nErreur reception !\n\n");
  }
  {
    	printf("\nreceptionne correctement\n\n");
  }

  printf ("%s",reception);					
 
  /*******************************************************************************/


 //close(csock);

	return 0;
}
