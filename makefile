Program: main.o menu.o pliki.o
	gcc -o Program main.o menu.o

main.o: main.c menu.h pliki.h
	gcc -c main.c

menu.o: menu.c menu.h
	gcc -c menu.c

pliki.o: pliki.c pliki.h
	gcc -c pliki.c

clean:
	rm -f *.o Program