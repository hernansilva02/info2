main: main.o src/leer_bajas.o src/leer_archivo.o src/crear_archivo.o src/escritura.o src/ejercicio.o
	gcc src/leer_bajas.o src/leer_archivo.o src/crear_archivo.o src/escritura.o src/ejercicio.o main.o -o main

main.o: main.c
	gcc -c main.c

src/leer_archivo.o: src/leer_archivo.c
	gcc -c src/leer_archivo.c -o src/leer_archivo.o

src/escritura.o: src/escritura.c
	gcc -c src/escritura.c -o src/escritura.o

src/crear_archivo.o: src/crear_archivo.c
	gcc -c src/crear_archivo.c -o src/crear_archivo.o

src/ejercicio.o: src/ejercicio.c
	gcc -c src/ejercicio.c -o src/ejercicio.o

src/leer_bajas.o: src/leer_bajas.c
	gcc -c src/leer_bajas.c -o src/leer_bajas.o

clean:
	rm -f main.o src/*.o main
