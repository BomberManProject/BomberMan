CC=gcc
CFLAGS=-g -I${BOMBERMANHOME}/src
LD=gcc

SRC=BomberMan/jeu/structures.c

OBJ=${SRC:.c=.o}

all: libBomberMan.a

libBomberMan.a: $(OBJ)
	ar cq libBomberMan.a $(OBJ)
	ranlib libBomberMan.a

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) libBomberMan.a

fullclean: clean
	rm -rf BomberMan/*/*~
	rm -rf BomberMan/*/*.dSYM
