/**
 * @file imagen.cpp
 * @version 1.0
 * @date 05/06/2018
 * @author Manuel Fernández La-Chica
 * @title Funcionamiento de las funciones
 * @brief Constructores, Destructor, metodos get y funciones de tratamiento de imagenes
 */

#include <iostream>
#include <fstream>
#include "imagen.h"

using namespace std;

Imagen::Imagen(){ 
    columna = 0;
    fila = 0;
    numero_comentarios = 0;
    color_maximo = 0;
    matriz_pixeles = 0;
    comentarios = 0;
}

Imagen::Imagen(const Imagen & imagen){
    this->columna = imagen.columna;
    this->fila = imagen.fila;
    this->numero_comentarios = imagen.numero_comentarios;


    if(imagen.comentarios == NULL){
        this->comentarios = NULL;
    }else{
        this->comentarios = new char*[imagen.numero_comentarios];
        for(int i = 0; i < this->numero_comentarios; i++){
            this->comentarios[i] = imagen.comentarios[i];
        }
    }

    this->color_maximo = imagen.color_maximo;

    if(imagen.matriz_pixeles == NULL){
        this->matriz_pixeles = NULL;
    }else{
        this->matriz_pixeles = new color*[imagen.columna];
        for(int i = 0; i<imagen.columna;i++){
            this->matriz_pixeles[i] = new color[imagen.fila];
            for(int j = 0; j<imagen.fila; j++){
                this->matriz_pixeles[i][j] = imagen.matriz_pixeles[i][j];
            }
        }
    }
}

Imagen::Imagen(const int & columna, const int & fila, const int & numero_comentarios, const int & color_maximo, char ** comentarios, color ** matriz_pixeles){
    this->columna = columna;
    this->fila = fila;
    this->numero_comentarios = numero_comentarios;

    if(comentarios == NULL){
        this->comentarios = NULL;
    }else{
        this->comentarios = new char*[numero_comentarios];
        for(int i = 0; i < this->numero_comentarios; i++){
            this->comentarios[i] = comentarios[i];
        }
    }

    this->color_maximo = color_maximo;
    
    if(matriz_pixeles == NULL){
        this->matriz_pixeles = NULL;
    }else{
        this->matriz_pixeles = new color*[columna];
        for(int i = 0; i<columna;i++){
            this->matriz_pixeles[i] = new color[fila];
            for(int j = 0; j<fila; j++){
                this->matriz_pixeles[i][j] = matriz_pixeles[i][j];
            }
        }
    }
}

Imagen::~Imagen(){
    
    if(this->comentarios != NULL){
        for(int i = 0; i<this->numero_comentarios;i++){
            delete[] comentarios[i];
        }
        delete[] comentarios;
    }

    if(this->matriz_pixeles != NULL){
        for(int i = 0; i<this->columna; i++){
            delete[] matriz_pixeles[i];
        }
        delete[] matriz_pixeles;
    }

    columna = 0;
    fila = 0;
    numero_comentarios = 0;
    color_maximo = 0;
}

Imagen& Imagen::operator=(const Imagen & imagen){
    
    ///Libero memoria, limpio el this
    if(this->comentarios != NULL){
        for(int i = 0; i<this->numero_comentarios;i++){
            delete[] this->comentarios[i];
        }
        delete[] this->comentarios;
    }

    if(this->matriz_pixeles != NULL){
        for(int i = 0; i<this->columna; i++){
            delete[] this->matriz_pixeles[i];
        }
        delete[] this->matriz_pixeles;
    }

    this->columna = 0;
    this->fila = 0;
    this->numero_comentarios = 0;
    this->color_maximo = 0;

    ///Copio imagen
    this->columna = imagen.columna;
    this->fila = imagen.fila;
    this->numero_comentarios = imagen.numero_comentarios;

    if(imagen.comentarios == NULL){
        this->comentarios = NULL;
    }else{
        for(int i = 0; i < this->numero_comentarios; i++){
            for(int j = 0; j<70 || imagen.comentarios[i][j] != ' '; j++){
                this->comentarios[i][j] = imagen.comentarios[i][j];
            }
        }
    }

    this->color_maximo = imagen.color_maximo;

    if(imagen.matriz_pixeles == NULL){
        this->matriz_pixeles = NULL;
    }else{
        for(int i = 0; i<imagen.columna;i++){
            for(int j = 0; j<imagen.fila; j++){
                this->matriz_pixeles[i][j] = imagen.matriz_pixeles[i][j];
            }
        }
    }

    return *(this);
}

inline int Imagen::getColumna() const{
    return columna;
}

inline int Imagen::getFila() const{
    return fila;
}

inline int Imagen::getNumeroComentarios() const{
    return numero_comentarios;
}

inline char** Imagen::getComentarios() const{
    return comentarios;
}

inline int Imagen::getColorMaximo() const{
    return color_maximo;
}

inline color** Imagen::getMatrizPixeles() const{
    return matriz_pixeles;
}

void leer_pgm(char *name, color** &m, int & c, int & f, char** &com, unsigned short &num_com, int & color_maximo){
    ifstream archivo;
    string cadena;
    string comentarios[100];
    bool leerTamano = false;
    bool aux = true;
    num_com = 0;
    archivo.open(name, ios::in);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    getline(archivo, cadena); //HAcemos getline para ignorar P5
    while(aux && getline(archivo, cadena)){
        if(cadena[0]=='#'){
            comentarios[num_com] = cadena;
            num_com++;
        }else {
            leerTamano = true;
        }

        if(leerTamano){
            std::size_t pos = cadena.find(" ");
            string columna = cadena.substr(0,pos);
            string fila = cadena.substr(pos);
            c = stoi(columna);
            f = stoi(fila);
            leerTamano = false;
            getline(archivo, cadena);
            color_maximo = stoi(cadena);
            aux = false;
        }
    }

    if(num_com > 0){
        com = new char*[num_com];
        for(int i = 0; i < num_com; i++){
            com[i] = new char[comentarios[i].length()+1];
            strcpy(com[i], comentarios[i].c_str());
        }
    }

	m = new color*[c];
	for(int i=0; i < c; i++)
	{
        char buffer[f];
		archivo.read(buffer, f);

        m[i]=new color[f];      
        for(int j=0; j<f; j++)      
        {
            m[i][j]=(color)buffer[j];    
        }
	}

    archivo.close();
    //return true;

}

void salvar_pgm(char *name, color** m, int c, int f, char** com, unsigned short num_com, int color_maximo){

    ofstream archivo;
    archivo.open(name, ios::out);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << "P5" << endl;

    for(int i = 0; i < num_com ;i++){
       archivo << com[i] << endl;
    }

    archivo << c << " " << f << endl;

    archivo << color_maximo << endl;

    for(int i = 0; i < c; i++){
        char b[f];
        for(int j = 0; j < f; j++)
        {
            b[j]=(char)m[i][j];
        }
        archivo.write(b, f);
    }
    
    archivo.close();
    //return true;
}

void Imagen::rellenarImagen(const color & valor){
    for(int i = 0; i<this->getColumna(); i++){
        for(int j = 0; j<this->getFila(); j++){
            this->matriz_pixeles[i][j] = valor; 
        }
    }
}

void Imagen::contrasteImagen(const color & valor_maximo, const color & valor_minimo){
    for(int i = 0; i<this->getColumna(); i++){
        for(int j = 0; j<this->getFila(); j++){
            color nuevo_valor = valor_minimo+(((valor_maximo-valor_minimo) * this->matriz_pixeles[i][j])/255);
            this->matriz_pixeles[i][j] = nuevo_valor; 
        }
    }
}


