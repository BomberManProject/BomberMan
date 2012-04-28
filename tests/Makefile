all: testMain testBdd1

testMain: testMain.c
	$(CC) $(CFLAGS) $< -o $@

testBdd1: testBdd1.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f testMain.o testBdd1.o testMain testBdd1

