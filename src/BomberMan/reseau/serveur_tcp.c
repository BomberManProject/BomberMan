#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#define INVALID_SOCKET -1

#define PORT 20002
#define SOCKET_ERROR -1	
    
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;


int main(int argc, char *argv[])
{
  /***************************** VARIABLES ***************************************/
  SOCKET ssock,csock;  
  SOCKADDR_IN ssocket;
  int retour_send=0,retour_recv=0,retour_bind,ecoute;
  unsigned int taille=0;
  char reception [1000],envoi[1000]="ta mere \n";
  /*******************************************************************************/   
  

  /***************************** SOCKET ******************************************/
  ssock = socket(AF_INET, SOCK_STREAM, 0);   //création du socket : Conexion distante, TCP, 0->TCP 												(défaut)
  if(csock==INVALID_SOCKET)
  {
    printf("Erreur de creation du socket\n");
  }
  else
  {
      printf("Socket crée\n");
  }
  /*******************************************************************************/
  

  /***************BIND **********************************/
        ssocket.sin_addr.s_addr = INADDR_ANY;  //ip du poste à joindre
        ssocket.sin_family = AF_INET;
        ssocket.sin_port = htons(PORT);
	retour_bind=bind(ssock,(SOCKADDR*)&ssocket,sizeof(ssocket));
	if (retour_bind == SOCKET_ERROR) printf("Erreur bind");
	
 /***************LISTEN **********************************/
	printf("Mise en attente d'une connexion cliente \n");
	ecoute = listen(ssock,1);
	if (ecoute == SOCKET_ERROR) printf ("Erreur listen");
	

  /*******************************************************************************/

 	csock = socket(AF_INET, SOCK_STREAM, 0);   //création d'un socket pour le client
	
		
  		/******************************* ACCEPT ****************************************/
 		 taille = sizeof(ssocket);
 		 csock = accept(ssock, (SOCKADDR*)&ssocket, &taille);
 		 printf("\n Un client s'est connecté à l'adresse : %s et sur le port %d \n", inet_ntoa(ssocket.sin_addr), htons (ssocket.sin_port));
		/*******************************************************************************/
	while (1)
	{
		 
 	 	 /***************************RECEIVE**********************************************/
 		 retour_recv=recv(csock, reception, sizeof(reception), 0);  

 		 if(retour_recv == SOCKET_ERROR)
 		 {
 	 	 	printf("\nErreur reception !\n\n");
 		 }
 		 else
 	 	{
			printf ("%s",reception);
 	 	  	printf("\nReceptionné correctement\n\n");
	 	 }
 					
		
  		/*******************************************************************************/
	}

 		 /***************************SEND***********************************************/
 		 printf("Message envoyé : %s \n", envoi);
 		 retour_send=send(csock, envoi, sizeof(envoi), 0);  //socket de DESTINATION, chaine de 								caractère, taille de la chaine, TCP (envoi normal)
  		if(retour_send == SOCKET_ERROR)
  		{
   			printf("\nErreur d'envoi des données !\n\n");
		}
		 else
		 {
 		   printf("\nDonnées envoyées correctement\n\n");
 		 }
 		/*******************************************************************************/

close(csock);
close(ssock);

return 0;
}
