BOMBERHOME=$(shell pwd)
CC=gcc
CFLAGS=-g -Wall $(shell mysql_config --cflags) -I${BOMBERHOME}/src
LIBS=$(shell mysql_config --libs) -lm

SRC=\
	src/BomberMan/jeu/structures.c \
	src/BomberMan/server/fonctionsBdd.c

OBJ=${SRC:.c=.o}

PROGS=\
	tests/testMain \
	tests/testBdd1

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

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
