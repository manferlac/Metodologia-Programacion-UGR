//
//  ejercicioB.cpp
//  Manuel Fernández La-Chica
//
//  Created by MacBook Pro on 11/4/18.
//

#include <iostream>
#include <cmath>

using namespace std;

struct coeficientes{
    int coef;
    int grado;
    coeficientes* sig;
};

typedef coeficientes* TipoPolinomio;

int evaluar(const TipoPolinomio p, const int valor){
    
    TipoPolinomio aux = p;
    int resultado = 0; //Donde voy a guardar el resultado final
    
    while (aux != NULL) {
        resultado = resultado + aux->coef*(pow(valor,aux->grado));
        aux = aux->sig;
    }
    return resultado; //Devuelvo el resultado final
}

int obtener(const TipoPolinomio p, const int i){
    TipoPolinomio aux = p;
    int coeficiente = 0;
    bool encontrado = false;
    
    while (aux != NULL && !encontrado) {
        if (aux->grado == i) {
            coeficiente = aux->coef;
            encontrado = true;
        }else{
            aux=aux->sig;
        }
    }
    
    return coeficiente;
}

TipoPolinomio sumar(const TipoPolinomio p1, const TipoPolinomio p2){
    TipoPolinomio polinomioSuma;
    TipoPolinomio aux1 = p1;
    TipoPolinomio aux2 = p2;
    bool finaliza = false;
    
    while(!finaliza){
        if (aux1->grado == aux2->grado) {
            polinomioSuma->coef = aux1->coef + aux2->coef;
            polinomioSuma->grado = aux1->grado;
            aux1 = aux1->sig;
            aux2 = aux2->sig;
            polinomioSuma = polinomioSuma->sig;
        }else if(aux1->grado < aux2->grado){
            polinomioSuma->coef = aux1->coef;
            polinomioSuma->grado = aux1->grado;
            aux1 = aux1->sig;
            polinomioSuma = polinomioSuma->sig;
        }else if(aux1->grado > aux2->grado){
            polinomioSuma->coef = aux2->coef;
            polinomioSuma->grado = aux2->grado;
            aux2 = aux2->sig;
            polinomioSuma = polinomioSuma->sig;
        }else if(aux1 == NULL){
            polinomioSuma->coef = aux2->coef;
            polinomioSuma->grado = aux2->grado;
            aux2 = aux2->sig;
            polinomioSuma = polinomioSuma->sig;
        }else if(aux2 == NULL){
            polinomioSuma->coef = aux1->coef;
            polinomioSuma->grado = aux1->grado;
            aux1 = aux1->sig;
            polinomioSuma = polinomioSuma->sig;
        }else if(aux1 == NULL && aux2 == NULL){
            finaliza = true;
        }
    }
    
    
    return polinomioSuma;
}

TipoPolinomio derivada(const TipoPolinomio p){
    TipoPolinomio resultado;
    TipoPolinomio aux = p;
    
    while (aux->sig != NULL) {
        if (aux->grado != 0) {
            resultado->coef = aux->coef * aux->grado;
            resultado->grado = aux->grado - 1;
            aux = aux->sig;
            resultado = resultado->sig;
        } else {
            resultado->coef = 0;
            resultado->grado = 0;
        }
    }
    
    return resultado;
}


int main(){
    TipoPolinomio p, p2;
    cout << "Introduce el primer polinomio: " << endl;
    int coeficiente, grado;
    while(p->grado != 0){
        cout << "Coeficiente: " << endl;
        cin >> coeficiente;
        p->coef = coeficiente;
        cout << "Coef: " << p->coef << endl;
        cout << "grado: " << endl;
        cin >> grado;
        p->grado = grado;
        cout << "grado: " << p->grado << endl;
        p = p->sig;
        
    }
    
    cout << "Introduce el segundo polinomio: " << endl;
    while(p2->grado != 0){
        cout << "Coeficiente: " << endl;
        cin >> coeficiente;
        p2->coef = coeficiente;
        cout << "Coef: " << p2->coef << endl;
        cout << "grado: " << endl;
        cin >> grado;
        p2->grado = grado;
        cout << "grado: " << p2->grado << endl;
        p2 = p2->sig;
        
    }
    
}
