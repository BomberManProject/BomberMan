CC=gcc
CFLAGS=-g -I${BOMBERMANHOME}/src
LD=gcc
LIBS=${BOMBERMANHOME}/src/libBomberMan.a -lm

all: client

client: client.c
	$(LD) $(CFLAGS) $< -o $@ ${LIBS}

clean:
	rm -f client.o client
	
