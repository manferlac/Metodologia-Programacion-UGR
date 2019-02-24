/**
 * @file rellenar.cpp
 * @version 1.0
 * @date 05/06/2018
 * @author Manuel Fernández La-Chica
 * @title Main del programa rellenar
 */

#include "imagen.cpp"

using namespace std;

int main(int argc, char * argv[]){
    if(argc!=3){
        cerr << "ERROR: Numero de parametros incorrecto" << endl;
        exit(1);
    }

    color** m = 0; 
    int c = 0;
    int f = 0;
    char** com = 0;
    unsigned short num_com = 0;
    int color_maximo = 0;

    
        leer_pgm(argv[1], m, c, f, com, num_com, color_maximo);
        Imagen rellenada(c, f, num_com, color_maximo, com, m);
        int valor = atoi(argv[2]);
        rellenada.rellenarImagen((color)valor);
        salvar_pgm(argv[1], rellenada.getMatrizPixeles(), rellenada.getColumna(), rellenada.getFila(), rellenada.getComentarios(), rellenada.getNumeroComentarios(), rellenada.getColorMaximo()); 
        cout << "Imagen rellenada con el color: " << valor << endl; 
}