SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


# ************** Binario **********
$(BIN)/rutas_aereas : $(OBJ)/Punto.o $(OBJ)/Pais.o $(OBJ)/Paises.o $(OBJ)/Ruta.o $(OBJ)/almacen_rutas.o $(OBJ)/imagen.o $(OBJ)/imagenES.o $(OBJ)/rutas_aereas.o
	$(CXX) -I$(INC) $^ -o $@

# ************ Objetos ***************
$(OBJ)/Punto.o : $(SRC)/Punto.cpp $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) $< -o $@


$(OBJ)/Pais.o : $(SRC)/Pais.cpp $(INC)/Pais.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Paises.o : $(SRC)/Paises.cpp $(INC)/Paises.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Ruta.o : $(SRC)/Ruta.cpp $(INC)/Ruta.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/almacen_rutas.o : $(SRC)/almacen_rutas.cpp $(INC)/almacen_rutas.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/rutas_aereas.o : $(SRC)/rutas_aereas.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Generación de documentación ******************
documentacion :
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
