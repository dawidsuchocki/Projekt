Program: main.o menu.o
	gcc -o Program main.o menu.o

main.o: main.c menu.h
	gcc -c main.c

menu.o: menu.c menu.h
	gcc -c menu.c

clean:
	rm -f *.o Program