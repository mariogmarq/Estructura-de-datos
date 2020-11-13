bin/main: obj/main.o obj/pila.o
	g++ obj/main.o obj/pila.o -o bin/main

obj/main.o: src/main.cpp
	g++ -g -c -I./include src/main.cpp -o obj/main.o

obj/pila.o: src/Pila_max_VD.cpp include/Pila_max_CD.h
	g++ -g -c -I./include src/Pila_max_VD.cpp -o obj/pila.o

clean:
	rm obj/* bin/*

rebuild: clean bin/main

documentacion:
	doxygen Doxyfile
