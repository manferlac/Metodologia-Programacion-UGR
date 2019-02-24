/**
 * @file contraste.cpp
 * @version 1.0
 * @date 05/06/2018
 * @author Manuel Fernández La-Chica
 * @title Main del programa contraste
 */

#include "imagen.cpp"

using namespace std;

int main(int argc, char * argv[]){
    if(argc!=5){
        cerr << "ERROR: PARAMETROS INCORRECTOS" << endl;
        exit(1);
    }

    color** m = 0; 
    int c = 0;
    int f = 0;
    char** com = 0;
    unsigned short num_com = 0;
    int color_maximo = 0;

        leer_pgm(argv[1], m, c, f, com, num_com, color_maximo);
        Imagen contraste(c, f, num_com, color_maximo, com, m);
        int valor_maximo = atoi(argv[2]);
        int valor_minimo = atoi(argv[3]);
        contraste.contrasteImagen((color)valor_maximo, (color)valor_minimo);
        salvar_pgm(argv[4], contraste.getMatrizPixeles(), contraste.getColumna(), contraste.getFila(), contraste.getComentarios(), contraste.getNumeroComentarios(), contraste.getColorMaximo());
        cout << "Imagen contrastada con el color maximo: " << valor_maximo << " y el valor minimo: " << valor_minimo << endl; 
}