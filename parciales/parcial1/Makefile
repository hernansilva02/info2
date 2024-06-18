main: main.o src/leer_archivo.o src/crear_archivo.o src/escritura.o
	gcc src/leer_archivo.o src/crear_archivo.o src/escritura.o main.o -o main

main.o: main.c
	gcc -c main.c

src/leer_archivo.o: src/leer_archivo.c
	gcc -c src/leer_archivo.c -o src/leer_archivo.o

src/escritura.o: src/escritura.c
	gcc -c src/escritura.c -o src/escritura.o

src/crear_archivo.o: src/crear_archivo.c
	gcc -c src/crear_archivo.c -o src/crear_archivo.o

clean:
	rm -f main.o src/*.o main
