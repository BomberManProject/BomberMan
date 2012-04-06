CC=gcc
CFLAGS=-g -I${BOMBERMANHOME}/src
LD=gcc
LIBS=${BOMBERMANHOME}/src/libBomberMan.a -lm

all: client serveur


client: client.c
	$(LD) $(CFLAGS) $< -o $@ ${LIBS}

serveur: serveur.c
	$(LD) $(CFLAGS) $< -o $@ ${LIBS}

clean:
	rm -f client.o client serveur.o serveur
	
