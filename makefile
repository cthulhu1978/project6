#
p6:     p6.c
	cc -c -g p6.c
	cc -o p6 p6.o

clean:
	rm -f p6
	rm -f *.o
