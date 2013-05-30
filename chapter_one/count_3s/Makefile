iterative: threes.o iterative.c
	gcc  -O2 -std=c99 iterative.c -o iterative

threadv1: threes.o threadv1.c
	gcc  -O2 -std=c99 -pthread threadv1.c -o threadv1

threadv2: threes.o threadv2.c
	gcc -O2  -std=c99 -pthread threadv2.c -o threadv2

threadv3: threes.o threadv3.c
	gcc  -O2 -std=c99 -pthread  threadv3.c -o threadv3

threes.o: threes.h
	gcc -O2 --std=c99 threes.h

