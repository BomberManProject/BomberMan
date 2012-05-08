BOMBERHOME=$(shell pwd)
CC=gcc
CFLAGS=-g -Wall $(shell mysql_config --cflags) $(shell pkg-config --cflags gtk+-2.0) -I${BOMBERHOME}/src
LIBS=$(shell mysql_config --libs) $(shell pkg-config --libs gtk+-2.0) -lm

SRC=\
	src/BomberMan/jeu/structures.c \
	src/BomberMan/server/fonctionsBdd.c \
	src/BomberMan/graph/fonctionGTK.c

OBJ=${SRC:.c=.o}

PROGS=\
	tests/testMain \
	tests/testBdd1 \
	tests/testgtk

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

tests/testgtk: tests/testgtk.c libBomberMan.a
	$(CC) $(CFLAGS) $< libBomberMan.a $(LIBS) -o $@

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
