BOMBERHOME=$(shell pwd)
CC=gcc
CFLAGS=-g -Wall $(shell mysql_config --cflags) $(shell pkg-config --cflags gtk+-2.0) -lpthread -I${BOMBERHOME}/src 
LIBS=$(shell mysql_config --libs) $(shell pkg-config --libs gtk+-2.0) -lm -lpthread

SRC=\
	src/BomberMan/jeu/structures.c \
	src/BomberMan/server/fonctionsBdd.c \
	src/BomberMan/graph/fonctionGTK.c

OBJ=${SRC:.c=.o}

PROGS=\
	tests/testMain \
	tests/testBdd1 \
	tests/testFichierStruct \
	tests/testStructFichier \
	tests/testBddFichier \
	tests/serveur \
	tests/testgtk \
	tests/client

all: libBomberMan.a $(PROGS)

clean:
	rm -f $(OBJ) $(PROGS)

libBomberMan.a: $(OBJ)
	ar cq libBomberMan.a $(OBJ)
	ranlib libBomberMan.a

tests/testMain: tests/testMain.c libBomberMan.a
	$(CC) $(CFLAGS) $<  libBomberMan.a $(LIBS) -o $@ 

tests/testBdd1: tests/testBdd1.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@
	
tests/testFichierStruct: tests/testFichierStruct.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@
	
tests/testStructFichier: tests/testStructFichier.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@
	
tests/testBddFichier: tests/testBddFichier.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@
	
tests/serveur: tests/serveur.c libBomberMan.a
	$(CC) $(CFLAGS) $<  libBomberMan.a $(LIBS) -o $@
	
tests/testgtk: tests/testgtk.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@
	
tests/client: tests/client.c libBomberMan.a
	$(CC) $(CFLAGS) $<  libBomberMan.a $(LIBS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
