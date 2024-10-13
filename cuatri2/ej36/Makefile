main: main.o src/leer_bajas.o src/leer_archivo.o src/crear_archivo.o src/cargar_archivo.o src/ejercicio.o
	gcc src/leer_archivo.o src/crear_archivo.o src/cargar_archivo.o src/ejercicio.o main.o -o main

main.o: main.c
	gcc -c main.c

src/leer_archivo.o: src/leer_archivo.c
	gcc -c src/leer_archivo.c -o src/leer_archivo.o

src/cargar_archivo.o: src/cargar_archivo.c
	gcc -c src/cargar_archivo.c -o src/cargar_archivo.o

src/crear_archivo.o: src/crear_archivo.c
	gcc -c src/crear_archivo.c -o src/crear_archivo.o

src/ejercicio.o: src/ejercicio.c
	gcc -c src/ejercicio.c -o src/ejercicio.o

clean:
	rm -f main.o src/*.o main

