//
//  ejercicioA.cpp
//  Manuel Fernández La-Chica
//
//  Created by MacBook Pro on 11/4/18.
//

#include <iostream>
using namespace std;

struct vectorSD{
    double *info;
    int util;
    int reservado;
};

void punto1(vectorSD &v, int nCasillas){
    if (v.util != 0) {
        delete [] v.info;
    }
    
    v.reservado = nCasillas;
    v.util = 0;
    v.info = new double[nCasillas];
}

void punto2(vectorSD &v, double elemento){
    //si no hay espacio
    if (v.util == v.reservado) {
        v.reservado *= 2;
        double *auxiliar = new double[v.reservado];
        
        for (int i=0; i<v.util; i++) {
            auxiliar[i] = v.info[i];
        }
        
        delete [] v.info;
        v.info = auxiliar;
    }
    
    //añadir elemento
    v.info[v.util]=elemento;
    v.util++;
}

vectorSD punto3(vectorSD &v){
    vectorSD vector;
    vector.util = v.util;
    vector.reservado = v.util;
    
    vector.info = new double[vector.reservado];
    
    for (int i=0; i<v.util; i++) {
        vector.info[i] = v.info[i];
    }

    return vector;
}

void punto4(vectorSD &v){
    delete [] v.info;
    v.util = 0;
    v.reservado = 0;
    v.info = 0;
}

int main(){
    vectorSD vector;
    punto1(vector, 6);
    punto2(vector, 2);
    punto2(vector, 4);
    punto2(vector, 2.4);
    punto2(vector, 1.1);
    
    cout << "Vector original: " << endl;
    for (int i=0; i<vector.util; i++) {
        cout << "[" << vector.info[i] << "]";
    }
    
    vectorSD vectorCopia = punto3(vector);
    
    cout << "/nVector copia: " << endl;
    for (int i=0; i<vectorCopia.util; i++) {
        cout << "[" << vectorCopia.info[i] << "]";
    }
    
    punto4(vector);
    
}
