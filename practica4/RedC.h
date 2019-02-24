//  Manuel Fernández La-Chica

#ifndef __REDCIUDADES
#define __REDCIUDADES


#include <iostream>

using namespace std;

/**
 * @brief Informacion de cada Ciudad
 */
struct InfoCiudad{
    /// Nombre de la ciudad
    char * nombre; 
    /// Censo de la ciudad
    int poblacion;
};

/**
 * @brief Clase para almacenar un conjunto de ciudades conectadas
 * Guardaremos la cantidad de ciudades en el conjunto, su informacion
 * y la distancia entre ellas
 */
class RedCiudades{
    private:
    /// Cantidad de ciudades en el conjunto
        int num_ciudades;
    /// Array con la informacion todas las ciduades del conjunto
        InfoCiudad * info;
    /// Distancia entre las ciudades
        double ** distancia;

    public:
        /**
        * @brief Constructor por defecto
        */
        RedCiudades();
        /**
        * @brief Constructor con un nº de ciudades 
        * para reservar memoria
        */
        RedCiudades(int size);
        /**
        * @brief Constructor de copia
        */
        RedCiudades(RedCiudades &rc);
        /**
        * @brief Destructor
        */
        ~RedCiudades();

        /**
        * @brief Set del dato privado num_ciudades
        * @param c nº de ciudades a almacenar
        */
        void set_num_ciudades(int nc);

        /**
        * @brief Get del dato privado num_ciudades
        * @return nº de ciudades en el conjunto
        */
        int get_num_ciudades();

        /**
        * @brief Get del nombre de una ciudad especifica
        * @param pos posicion en el indice de ciudades
        * @return cadena de caracteres que forman el nombre de la ciudad
        * en la posicion pos
        */
        char * get_nombre(int pos);
        /**
        * @brief Get del dato del struct dentro del dato privado info
        * @param pos posicion de la ciudad en el indice del array
        * @return nº de habitantes en la ciudad
        */
        int get_poblacion(int pos);

        /**
        * @brief Set para el dato privado info
        * que contiene el conjunto de ciudades
        * @param inf array con la coleccion de ciduades
        */
        void set_info(InfoCiudad * inf);

        /**
        * @brief Set para introducir una ciudad, con toda su informacion
        * @param pos posicion del indice de la ciudad
        * @param nombre nombre de la ciudad
        * @param pob poblacion de la ciudad
        * 
        */
        void set_ciudad(int pos, string nombre, int pob, double **distancias);

        /**
        * @brief Comprobador para saber si esta vacia o no una ciudad
        * @return devuelve true si esta vacia, false en caso contrario
        */
        bool EstaVacia() const;
        /**
        * @brief Distancia entre 2 ciudades dando sus indices en la coleccion
        * @param i indice ciudad1
        * @param j indice ciudad2
        * @return distancia entre ciudad1 y ciudad2
        */
        double Distancia(int i, int j);
        
        /**
        * @brief Funcion que nos dice que ciudad del conjunto tiene mejor
        * conexiones con las otras ciudades
        * 
        * @return indice en la coleccion de la ciudad con mejor conexion
        */
        int CiudadMejorConectada();
        /**
        * @brief Dadas dos ciudades nos devolvera la ciudad intermedia con
        * la ruta mas corta que las conecta
        * @param c1 ciudad inicio
        * @param c2 ciudad destino
        * 
        * @return indice en la coleccion de la ciudad intermedia con la ruta
        * mas corta, si estan ya conectadas devolvera -2, si se ha introducido 
        * la misma ciudad en @param c1 y en @param c2 devolvera -1
        */
        int MejorEscalaEntre(int c1, int c2);

        /**
        * @brief Libera memoria del objeto
        * @param rc objeto del que liberaremos la memoria
        */
        void del();
        /**
        * @brief Sobrecarga del operador de entrada para construir objetos
        * mediante la entrada de ficheros
        * @param is documento de texto con la informacion de los objetos
        * para procesar
        * @param rc objeto donde almacenaremos los datos del documento
        * 
        * @return referencia al istream
        */
        friend istream& operator>> (istream& is, RedCiudades &rc);
        
        /**
        * @brief Sobrecarga del operador de salida para construir un fichero
        * con los objetos almacenados en el programa
        * @param is documento de texto donde escribiremos la informacion 
        * de nuestros objetos
        * @param rc objeto del cual estamos escribiendo la informacion
        * 
        * @return referencia al ostream
        */
        friend ostream& operator<< (ostream& os, RedCiudades &rc);

        /**
        * @brief Sobrecarga del operador de asignacion para igualar 
        * dos objetos sin necesidad de crear una funcion de copia
        * @param rc objeto del que copiamos la informacion
        * @return copia del objeto parado por parametro
        */
        RedCiudades &operator=(const RedCiudades &rc);

};

#endif
