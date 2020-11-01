bin/main: obj/main.o obj/pila.o
	echo Creando el ejecutable
	g++ obj/main.o obj/pila.o -o bin/main

obj/main.o: src/main.cpp
	echo Creando el main.o
	g++ -g -c -I./include src/main.cpp -o obj/main.o

obj/pilavd.o: src/pila_max_vd.cpp include/pila_max_vd.h
	echo Creando pila.o
	g++ -g -c -I./include src/pila_max_vh.cpp -o obj/pila_max_vh.o

obj/pilacola.o: src/pila_max_cola.cpp include/pila_max_cola.h
	echo Creando pila.o
	g++ -g -c -I./include src/pila_max_cola.cpp -o obj/pila_max_cola.o

clean:
	echo Limpiando
	-rm obj/* bin/*

rebuild: clean bin/main

documentation:
	echo Creando la documentacion
	doxygen Doxyfile
