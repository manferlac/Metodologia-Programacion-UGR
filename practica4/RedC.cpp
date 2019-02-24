//  Manuel Fernández La-Chica

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "RedC.h"

using namespace std;

    void RedCiudades::set_num_ciudades(int nc)
    {
        num_ciudades = nc;
    }
    char * RedCiudades::get_nombre(int pos)
    {
        return info[pos].nombre;
    }
    int RedCiudades::get_num_ciudades()
    {
        return num_ciudades;
    }
    int RedCiudades::get_poblacion(int pos)
    {
        return info[pos].poblacion;
    }

    void RedCiudades::set_info(InfoCiudad * inf)
    {
        info = inf;
    }
    void RedCiudades::set_ciudad(int pos, string nombre, int pob, double **distancias)
    {
        info[pos].nombre = new char[nombre.length() + 1];
        strcpy(info[pos].nombre, nombre.c_str());
        info[pos].poblacion = pob;

        distancia = distancias;
    }
    RedCiudades::RedCiudades()
    {
        num_ciudades = 0;
    }

    RedCiudades::RedCiudades(int size)
    {
        num_ciudades = 0;
        info = new InfoCiudad[size];
        distancia = new double*[size];

        for(int i=0;i<size;i++)
        {
            distancia[i] = new double[size];
            info[i].nombre = new char[size];
        }
    }

    RedCiudades::RedCiudades(RedCiudades &rc)
    {
        *this=rc;
    }

    RedCiudades::~RedCiudades()
    {
        if(!this->EstaVacia())
        {
            for(int i=0; i<this->num_ciudades;i++)
            {
                delete[] this->distancia[i];
            }
            delete[] this->distancia;
            delete[] this->info;
        }
    }
    bool RedCiudades::EstaVacia() const
    {
        bool r=true;
        if(this->num_ciudades>0)
            r=false;
        return r;
    }

    double RedCiudades::Distancia(int i, int j)
    {
        return this->distancia[i][j];
    }

    int RedCiudades::CiudadMejorConectada()
{
    int max = 0;
    int aux=0;
    int pos=0;
    for(int i=0;i<(this->num_ciudades);i++)
    {
        for(int j=0;j<(this->num_ciudades);j++)
        {
            if(this->Distancia(i,j)>0)
                aux++;
        }
        if(max<aux)
        {
            max=aux;
            pos = i;
            aux=0;
        }
    }
    return pos;
}

int RedCiudades::MejorEscalaEntre(int c1,int c2)
{
    if(c1==c2)
    {
        //cout << "Se ha dado la misma ciudad\n";
        return -1;
    }

    if(this->distancia[c1][c2]!=0)
    {
        //cout << "Las ciudades estan ya conectadas\n";
        return -2;
    }

    int * caux = new int[this->num_ciudades];
    int * daux = new int[this->num_ciudades];
    int cauxu = 0;
    for(int i=0;i<this->num_ciudades;i++)
    {
        if(this->distancia[c1][i]!=0 && this->distancia[c2][i]!=0)
        {
            caux[cauxu]=i;
            daux[cauxu]=this->Distancia(c1,i) + this->Distancia(c2, i);
            cauxu++;
        }
    }

    double min=999999999;
    int pos;

    for(int i=0;i<cauxu;i++)
    {
        if(daux[i]<min)
        {
            min = daux[i];
            pos = caux[i];
        }
    }

    return pos;
}

void RedCiudades::del()
{
    if(!this->EstaVacia())
    {
        for(int i=0; i<num_ciudades;i++)
        {
            delete[] this->info[i].nombre;
            delete[] distancia[i];
        }
        delete[] this->info;
        delete[] distancia;
        num_ciudades=0;
    }
}


RedCiudades &RedCiudades::operator=(const RedCiudades &rc)
{
    if(!this->EstaVacia())
    {
        delete[] this->info;
        for(int i=0;i<this->num_ciudades;i++)
        {
            delete[] this->distancia[i];
            delete[] this->info[i].nombre;
        }
        delete[] this->distancia;
        delete[] this->info;
    }

    this->num_ciudades=rc.num_ciudades;
    cout << num_ciudades;
    this->info = new InfoCiudad[this->num_ciudades];
    this->distancia = new double*[this->num_ciudades];

    for(int i=0;i<this->num_ciudades;i++)
    {   
        this->distancia[i]=new double[num_ciudades];
        for(int j=0;j<this->num_ciudades;j++)
        {
            this->distancia[i][j]=rc.distancia[i][j];
        }
        
        this->info[i].nombre = new char[this->num_ciudades];
        this->info[i].nombre=rc.info[i].nombre;
        this->info[i].poblacion=rc.info[i].poblacion;

    }
    return *this;

}
istream& operator>> (istream& is, RedCiudades &rc)
{
    string s;
    getline(is,s);
    //introducimos el nº de ciudades
    //RedCiudades rc(stoi(s));
    rc.set_num_ciudades(stoi(s));
    InfoCiudad * inf = new InfoCiudad[rc.get_num_ciudades()];
    rc.set_info(inf);
    double ** distancias = new double*[rc.get_num_ciudades()];
    for(int i=0;i<rc.get_num_ciudades();i++)
    {
        inf[i].nombre = new char;
        distancias[i] = new double[rc.get_num_ciudades()];
    }
    for(int i=0;i<rc.get_num_ciudades();i++)
    {
        for(int j=0;j<rc.get_num_ciudades();j++)
        {
            distancias[i][j]=0;
        }
    }
    for(int j=0;j<rc.get_num_ciudades();j++)
    {
        getline(is,s);
        int pos = stoi(s);
        getline(is,s);
        string nombre = s;
        getline(is,s);
        int poblacion = stoi(s);
        getline(is,s);
        int n_rutas = stoi(s);
        for(int i=0;i<n_rutas;i++)
        {
            getline(is, s);
            int c1 = stoi(s);
            getline(is, s);
            int c2 = stoi(s);
            getline(is,s);
            double distancia = stod(s);
            distancias[c1][c2]=distancia;
            distancias[c2][c1]=distancia;
        }
        rc.set_ciudad(pos, nombre, poblacion, distancias);
    }
/*
    for(int i=0;i<rc.get_num_ciudades;i++)
    {
        delete[] distancias[i];
    }
    delete[] distancias;
    */
   return is;
}

ostream& operator<< (ostream &os, RedCiudades &rc)
{
    os << rc.get_num_ciudades() << endl;
    for(int i=0; i<rc.get_num_ciudades();i++)
    {
        
        os << i << endl;
        os << rc.get_nombre(i) << endl;
        os << rc.get_poblacion(i) << endl;
        int n_rutas=0;
        for(int j=i+1;j<rc.get_num_ciudades();j++)
        {
            if(rc.Distancia(i,j)>0)
                n_rutas++;
        }
            os << n_rutas << endl;
        for(int j=i+1;j<rc.get_num_ciudades();j++)
        {
            if(rc.Distancia(i,j)>0 )
            {    
                os << i << endl;
                os << j << endl;
                os << rc.Distancia(i,j) << endl;
            }
        }
    }
    return os;
}



int main(int argc, char* argv[])
{
    if(argc!=3)
    {
        cout << "Dime el nombre del archivo con los datos\n";
        return -1;
    }

    ifstream f(argv[1]);
    if(!f)
    {
        cout << "No puedo abrir el fichero " << argv[1]<<endl;
        return -1;
    }

    RedCiudades redC;
    f>>redC;

    cout << "NUM CIUDADES: " << redC.get_num_ciudades() << endl; 
    cout << "Ciudad mejor conectada " << redC.get_nombre(redC.CiudadMejorConectada()) << "con ";
    cout << redC.CiudadMejorConectada() << " rutas\n";
    cout << "Poblacion ciudad " << redC.get_nombre(0) << redC.get_poblacion(0) << endl;
    
    for(int i=0; i<redC.get_num_ciudades();i++)
    {
        for(int j=i+1;j<redC.get_num_ciudades();j++)
        {
            if(redC.MejorEscalaEntre(i,j)>0)
            {
                cout << "Escala optima  " << redC.get_nombre(i) << "\t-  " << redC.get_nombre(j);
                cout << "\t-> " << redC.get_nombre(redC.MejorEscalaEntre(i,j)) << endl; 
            }       
        }
    }
    RedCiudades r2;
    cout << r2.get_num_ciudades();
    r2=redC;
    ofstream of(argv[2]);
    of<<r2;
}
