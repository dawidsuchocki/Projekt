Program: main.o menu.o pliki.o implanty.o
	gcc -o Program main.o menu.o pliki.o implanty.o

main.o: main.c menu.h pliki.h implanty.h
	gcc -c main.c

menu.o: menu.c menu.h 
	gcc -c menu.c

pliki.o: pliki.c pliki.h 
	gcc -c pliki.c 

implanty.o: implanty.c implanty.h
	gcc -c implanty.c

clean:
	rm -f *.o Program