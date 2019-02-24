
SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++ 
AR = ar rsv

all: $(BIN)/rellenar $(BIN)/contraste

$(BIN)/rellenar: $(OBJ)/rellenar.o $(LIB)/libproyecto.a
	$(CXX) -o $(BIN)/rellenar $(OBJ)/rellenar.o -Llib/ -lproyecto

$(BIN)/contraste: $(OBJ)/contraste.o $(LIB)/libproyecto.a
	$(CXX) -o $(BIN)/contraste $(OBJ)/contraste.o -Llib/ -lproyecto

$(LIB)/libproyecto.a: $(OBJ)/imagen.o 
	$(AR) $(LIB)/libproyecto.a $(OBJ)/imagen.o 

$(OBJ)/rellenar.o: $(SRC)/rellenar.cpp 
	$(CXX) -c $(SRC)/rellenar.cpp -o $(OBJ)/rellenar.o -Iinclude/

$(OBJ)/contraste.o: $(SRC)/contraste.cpp 
	$(CXX) -c $(SRC)/contraste.cpp -o $(OBJ)/contraste.o -Iinclude/

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o -Iinclude/

clean :
	rm $(OBJ)/* $(LIB)/* $(BIN)/*