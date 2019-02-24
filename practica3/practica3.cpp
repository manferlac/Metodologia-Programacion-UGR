//
//  practica3.cpp
//  Manuel Fernández La-Chica
//
//  Created by MacBook Pro on 23/4/18.
//

#include <iostream>
using namespace std;

//Estructura de un partido político
struct Partido{
    string nombre;
    int votos;
};

//Estructura de una provincia
struct Provincia{
    string nombre;
    int escanos;
    int censo;
    int n_partidos;
    Partido * partidos;
    
    int votos_blancos;
    int votos_nulos;
};

struct Eleccion{
    string nombre;
    int n_provincias;
    int escanos;
    Provincia * provincias;
};

void rellenarDatos(Eleccion &ele){
    
    cin >> ele.nombre;
    cin >> ele.n_provincias;
    cin >> ele.escanos;
    
    Provincia * p = new Provincia[ele.n_provincias];
    ele.provincias = p;
    for (int i = 0; i<ele.n_provincias; i++) {
        
        Provincia prov;
        cin >> prov.nombre;
        cin >> prov.escanos;
        cin >> prov.censo;
        cin >> prov.n_partidos;
        prov.partidos = new Partido[prov.n_partidos];
        ele.provincias[i] = prov;
        
        for (int j = 0; j<prov.n_partidos; j++) {
            Partido part;
            cin >> part.nombre;
            cin >> part.votos;
            ele.provincias[i].partidos[j] = part;
        }
        
        cin >> ele.provincias[i].votos_nulos;
        cin >> ele.provincias[i].votos_blancos;
        
    }
}

void ejercicio1(Eleccion ele){
    cout << "-----------------------------------------" << endl;
    cout << "|ELECCIONES - " << ele.nombre << endl;
    cout << "-----------------------------------------" << endl;
    int total_votantes = 0;
    int total_votos_emitidos = 0;
    int votos_blancos = 0;
    int votos_nulos = 0;
    //Mostramos total del censo de todas las provincias conjuntamente
    for (int i = 0; i<ele.n_provincias; i++) {
        total_votantes += ele.provincias[i].censo;
    }
    cout << "Total censo de votantes: " << total_votantes << endl;
    
    //Mostramos total de votos emitidos
    
    for (int i = 0; i<ele.n_provincias; i++) {
        for (int j = 0; j<ele.provincias[i].n_partidos; j++) {
            total_votos_emitidos += ele.provincias[i].partidos[j].votos;
        }
        
        votos_nulos += ele.provincias[i].votos_nulos;
        votos_blancos += ele.provincias[i].votos_blancos;
        
    }
    
    total_votos_emitidos += votos_nulos + votos_blancos;
    
    cout << "Total de votos emitidos: " << total_votos_emitidos << endl;
    
    //% de participacion
    int porcentaje = (total_votos_emitidos*100)/total_votantes;
    cout << "Porcentaje de participacion: " << porcentaje << "%" << endl;
    
    //Porcentaje votos nulos
    
    porcentaje = (votos_nulos*100)/total_votos_emitidos;
    cout << "Porcentaje de votos nulos: " << porcentaje << "%" << endl;
    //Porcentaje votos blancos
    
    porcentaje = (votos_blancos*100)/total_votos_emitidos;
    cout << "Porcentaje de votos en blanco: " << porcentaje << "%" << endl;

}

void ejercicio2(Eleccion ele){
    
    int votos_nulos;
    int votos_blancos;
    int votos_emitidos;
    
    for (int i = 0; i<ele.n_provincias; i++) {
        votos_emitidos = 0;
        cout << "Provincia: " << ele.provincias[i].nombre << endl;
        cout << "-----------------" << endl;
        cout << "Censo: " << ele.provincias[i].censo << endl;
        votos_nulos = ele.provincias[i].votos_nulos;
        votos_blancos = ele.provincias[i].votos_blancos;
        for (int j = 0; j<ele.provincias[i].n_partidos; j++) {
            votos_emitidos = votos_emitidos + ele.provincias[i].partidos[j].votos;
        }
        
        votos_emitidos = votos_emitidos + votos_nulos + votos_blancos;
        cout << "Votos emitidos: " << votos_emitidos << endl;
        cout << "% participacion: " << (votos_emitidos*100)/ele.provincias[i].censo << "%" << endl;
        cout << "% votos nulos: " << (votos_nulos*100)/votos_emitidos << "%" << endl;
        cout << "% votos blancos: " << (votos_blancos*100)/votos_emitidos << "%" << endl;
        
        cout << "-----------------" << endl;
        
    }
}

int main(){
    Eleccion e;
    rellenarDatos(e);
    ejercicio1(e);
    cout << "------------------" << endl;
    ejercicio2(e);
    //ejercicio2b(e);
    
}


