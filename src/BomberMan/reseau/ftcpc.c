/* Compilation: cc ftcpc.c -o client -lpthread    */
/* Execution: ./serveur adresse ou nom du serveur */

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <dirent.h>            
#include <sys/stat.h>           
#include <string.h>             
#include <unistd.h>           
#include <stdio.h>
#include <stdlib.h>              
#include <time.h>              

#define vrai 1
#define faux 0

// Numero du port du serveur
#define SERV_PORT 1200

// taille maximal du buffer
#define MAX_BUF 2048

// Descripteur du fichier cree pour la reception
FILE *fd;

// Le nom sous lequel le fichier transferer sera garder
char nom_fich_recu[MAX_BUF];

// Fonctions utilise par le client
int cree_socket();





int main(int argc, char **argv)
{
// Buffer pour la lecture et l'ecriture dans le socket
char *buf;
int long_buf;

//Descripteur du client
int client;

// Utilise par send pour garder la valeur de retour
int envoye;

// Guarde la valeur de retour de la fonction recv
int recue;

// Pour la construction de l'adresse du serveur
struct sockaddr_in serveur;
int long_serveur;

// Pour avoir les informations concernant le serveur
struct hostent *h;

// Variable indiquant qu'on a atteint la fin de fichoer
int fin = faux;

// Pour le comptage des bloc recu
int num_bloc = 0;

printf("\n Verfication des arguments de la ligne de commande ... ");
if (argc != 2)
   {
   printf(" [FAILED]");
   printf("\n Usage:  client nom_serveur \n");
   exit(1);
   }
printf(" [OK]");   

// creation du socket
printf(" \n Creation du socket ... ");
client = cree_socket();
if(client < 0)
 {
  perror("Cause");
  exit(1);
 }

// Allocation du buffer
printf(" \n Allocation du buffer ... ");
buf = (char *)malloc(MAX_BUF);
if(buf == NULL)
  {
  printf(" [FAILED]\n");  
  perror("Cause");
  exit(1);
  }	
printf(" [OK]\n");


// On construit l'adresse du serveur
printf("\n Construction de l'adresse du serveur ... ");


printf(" [OK]");
printf("\n Resolution du nom de serveur %s ... ", argv[1]);
h = gethostbyname(argv[1]);
if (h == NULL)
    {
    printf(" [FAILED]\n");
    perror("Cause");
    exit(1);
    }
printf(" [OK]\n");

serveur.sin_family = AF_INET;
serveur.sin_port = htons(SERV_PORT);

struct in_addr *addr_ip_serv = (struct in_addr *)h->h_addr_list[0];

printf("\n Adresse ip du serveur est: %s", 
	inet_ntoa(*addr_ip_serv));

memcpy((char*)(&serveur.sin_addr.s_addr), h->h_addr_list[0], h->h_length);
long_serveur = sizeof(serveur);

// On va envoye une demande de connexion au serveur
 
printf("\n Demande de connexion au serveur ... ");
if(connect(client, (struct sockaddr *)&serveur , long_serveur) < 0)
  {
  printf(" [FAILED] \n");	  
  perror("Cause");
  exit(1);
  }	  
printf(" [OK]");   


printf("\n Attente de validation  ou refus de connexion ... ");

memset(buf,0,strlen(buf));

recue = 
	recv(client, buf, long_buf, 0);

if (recue < 0)
   {
   printf(" [FAILED]");
   perror("Cause");
   exit(1); 
   }   

if(strcmp(buf,"OK") != 0 && strcmp(buf,"NO") != 0)
  {
  printf(" [OK] \n");
  printf("\n Attendu OK ou NO recue %s.\n", buf);
  exit(1);
  }

if(strcmp(buf,"NO") == 0)
  {
  printf(" [FAILED]");
  printf("\n\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!   ");   
  printf("\n\t\t !!! Le serveur est charge  !!!   ");   
  printf("\n\t\t !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n");   
  close(client);
  exit(1);
  }

if(strcmp(buf,"OK") == 0)
  {
  printf(" [OK]");
  printf("\n\t\t ***************************************");   
  printf("\n\t\t *** Le serveur a accepte la demande ***");   
  printf("\n\t\t ***************************************");   
  }


// On envoie le nom de fichier a cherche 
printf("\n Entrer le nom de fichier a cherche: ");
scanf("%s",buf);
long_buf = strlen(buf) + 1;

printf("\n Envoi du nom de fichier ... "); 
envoye =
       	send(client, buf, long_buf , 0);
 
if(envoye < 0)
   {
   printf(" [FAILED]");
   perror("Cause");
   close(client);
   exit(1);
   }	
printf(" [OK]"); 


// On envoi la chaine a recherche  dans le fichier  

printf("\n Entrer le motif a cherche: ");
memset(buf,0,strlen(buf));
scanf("%s",buf);
long_buf = strlen(buf);

printf("\n Envoi du motif ... "); 
envoye =
       	send(client, buf, long_buf , 0);
 
if(envoye < 0)
   {
   printf(" [FAILED]\n");
   perror("Cause");
   close(client);
   exit(1);
   }	
printf(" [OK]"); 

// Reception de la reponse pour l'existence du fichier
printf("\n Attente de la reponse d'existence du fichier ...");
memset(buf,0,strlen(buf));
long_buf = MAX_BUF;
recue = 
	recv(client, buf, long_buf, 0);
if (recue < 0)
   {
   printf(" [FAILED]");
   perror("Cause");
   close(client);
   exit(1); 
   }   
printf(" [OK]");
if(!strcmp(buf,"EXIST"))
  {
  printf("\n Le serveur a trouve le fichier cherche. \n");  
  }
  else if(!strcmp(buf,"NO_EXIST"))
     {
     printf("\n Le serveur n'a pas reussi a trouve le fichier.\n");
     close(client);
     exit(1);
     }
    else
       {
       printf(" \n Attendu 'EXIST' ou 'NO_EXIST': Recue %s \n",buf);
       close(client);
       exit(0);
       }

sprintf(nom_fich_recu, "client%d",getpid());
strcat(nom_fich_recu,".log");
fd = fopen(nom_fich_recu,"w+");
printf("\n ***************************************************************   ");
printf("\n *                    Reception du contenu                     *   ");
printf("\n *************************************************************** \n");
long_buf = MAX_BUF;
if(fd == NULL)
  {
  printf("\n Impossible de cree un fichier pour la reception des donnees recu");
  perror("Cause");
  close(client);
  exit(1);
  }
else 
  do /* tanque non fin de fichier */
    {
    printf("\n Attente d'un bloc de donnee ... ");

    // Effacer le contenu du buffer
    long_buf = MAX_BUF;
    memset(buf,0,MAX_BUF);
    recue = 
	    recv(client, buf, long_buf, 0);

    if(recue < 0)
      {
       printf(" [FAILED]\n");
       printf("\n Erreur lors de la reception des donnees. \n");
       perror("Cause");
       continue;
       } /* if recue < 0 */
    
    printf(" [OK]");
    printf("%s",buf);
    
    if(!strcmp(buf,"$FIN$")  || !strcmp(buf, "$ERREUR$"))
       {
	fin = vrai;
       }   


    if(fin == faux) // Car $FIN$, $ERREUR$ ne font pas partie du fichier 
      {
      num_bloc++;	      
      
      // Ecrire les donnees recu dans le fichier qui porte comme nom
      // client-num_port
      
      printf("\n Ecriture du bloc %d sur le fichier ... ", num_bloc);
      if(fprintf(fd,"%s",buf) < 0)
        {
         printf(" [FAILED]\n");
         perror("Cause");
         exit(1);
        }
      }
    printf(" [OK]");
  
    }while(fin == faux);  /* !feof(df) */     
    }while(fin == faux);  /* !feof(df) */     

// On attend la reponse concernant le motif //
printf("\n Attente de la reception concernant le motif ... ");
long_buf = MAX_BUF;
memset(buf,0,MAX_BUF);
recue = 
	recv(client, buf, long_buf, 0);
if(recue < 0)
  {
  printf(" [FAILED]");	  
  perror("Cause");
  }	  
  else
     {
      printf(" [OK]");
      printf("\n %s", buf); 
      printf(" \n Le transfert est termine avec succès.");
      printf(
  " \n Ouvrir le fichier client%d.log pour voir le resultat de la reception.\n"     , getpid());
     }


fclose(fd);
close(client);
printf("\n");
return 0;
}

//////////////////////////////////////////////////////////////////
//Procedure qui permet la creation d'une socket                 //
//et nous renvoie un descripteur sur le socket ainsi cree       //
//////////////////////////////////////////////////////////////////

int cree_socket()
{

  int client;
  
  // Creation du socket
  client = socket(AF_INET, SOCK_STREAM, 0);
  if(client < 0)
    {
      perror(" [FAILED] \n");
      return(-1);
    }
  printf(" [OK]\n"); 

  return client;
}
