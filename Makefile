CC = gcc
CF = -Wall -Werror

all: client bank

#server: testserver.c
#	$(CC)  -o server testserver.c -lpthread

client: testclient.c
	$(CC)  -o client testclient.c

bank: bank.o testserver.o
	$(CC) $(CF) -o bank bank.o testserver.o -lpthread

testserver.o: testserver.c bank.h
	$(CC) -c testserver.c -g

bank.o: bank.c bank.h
	$(CC) $(CF) -c bank.c -g

clean:
	rm -f *~
	rm -f *.o
	rm -f server
	rm -f client
	rm -f bank