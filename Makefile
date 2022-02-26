all: main

main: main.o FASTAreadset_LL.o
	g++ -g -Wall -o main  main.o FASTAreadset_LL.o

main.o: main.cpp
	g++ -g -Wall -o main.o -c main.cpp

FASTA_readset_LL.o: FASTA_readset_LL.cpp
	g++ -g -Wall -o FASTAreadset_LL.o -c FASTAreadset_LL.cpp

clean:
	rm main main.o FASTAreadset_LL.o
