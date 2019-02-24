//
//  ejercicioVoluntario.cpp
//  Manuel Fernández La-Chica
//
//  Created by MacBook Pro on 13/4/18.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct Conjunto{
    int max_elem;
    int num_elem;
    int * elementos;
};

void inicializar(Conjunto &conj){
    if (conj.num_elem != 0) {
        delete [] conj.elementos;
    }
    
    conj.max_elem = 10;
    conj.num_elem = 0;
    conj.elementos = new int[10];
}

void inicializarConArray(Conjunto &conj, int numeroElementos, int elementos[]){
    if (conj.num_elem != 0) {
        delete [] conj.elementos;
    }
    
    conj.max_elem = numeroElementos;
    conj.num_elem = numeroElementos;
    conj.elementos = new int[numeroElementos];
    
    for(int i = 0; i<num_elem; i++){
        conj.elementos[i] = elementos[i];
    }
}

void inicializarDinamico(Conjunto &conj, int * arrayDinamico, int numeroElementos){
    if (conj.num_elem != 0) {
        delete [] conj.elementos;
    }
    
    conj.max_elem = numeroElementos;
    conj.num_elem = numeroElementos;
    conj.elementos = arrayDinamico;
}

void liberarMemoria(Conjunto &conj){
    conj.max_elem = 0;
    conj.num_elem = 0;
    delete [] conj.elementos;
    conj.elementos = 0;
}

bool encontrarElemento(Conjunto &conj, int elemento){
    bool encontrado = false;
    int i = 0;
    while(!encontrado){
        if (conj.elementos[i] == elemento) {
            encontrado = true;
        } else {
            i++;
        }
    }
    
    return encontrado;
}

void nuevoElemento(Conjunto &conj, int elemento){
    bool elementoRepetido = encontrarElemento(conj,elemento);
    if (conj.num_elem < conj.max_elem) {
        if(!elementoRepetido){
            conj.elementos[num_elem] = elemento;
        }
    }
}

void eliminarElemento(Conjunto &conj, int elemento){
    for (int i = 0; i<conj.num_elem; i++) {
        if (conj.elementos[i] == elemento) {
            conj.elementos[i] = 0;
            conj.num_elem--;
        }
    }
}


