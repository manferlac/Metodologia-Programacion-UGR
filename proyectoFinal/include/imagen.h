/**
 * @file imagen.h
 * @version 1.0
 * @date 05/06/2018
 * @author Manuel Fernández La-Chica
 * @title Cabecera del proyecto
 * @brief Constructores, Destructor, metodos get y funciones de tratamiento de imagenes
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

typedef unsigned char color;

class Imagen{

    private:
        int columna;
        int fila;
        int numero_comentarios;
        char ** comentarios;
        int color_maximo;
        color ** matriz_pixeles;
    
    public:

        /**
         * @brief Constructor por defecto
         * @definicion Crea una imagen con todos los valores a cero o nulos
         */
        Imagen();

        /**
         * @brief Constructor de copia
         * @param imagen Imagen que utilizaremos desde donde copiar los valores a nuestra imagen
         * @definicion Esta función copia todos los valores de la imagen pasada como argumento a nuestra imagen
         */
        Imagen(const Imagen & imagen);

        /**
         * @brief Constructor de paso por parámetros
         * @param columna: numero de columnas de la matriz
         * @param fila: numero de filas de la matriz
         * @param numero_comentarios: cantidad de comentarios que hay en la imagen
         * @param color_maximo: valor del color maximo que pueden tener la matriz
         * @param comentarios: Puntero a puntero de char donde se guardan los comentarios de la imagen
         * @param matriz_pixeles: Matriz con los valores de la matriz
         * @definicion Esta funcion crea una imagen con los valores pasados por referencia en los parametros
         */
        Imagen(const int & columna, const int & fila, const int & numero_comentarios, const int & color_maximo, char ** comentarios, color ** matriz_pixeles);

        /**
         * @brief Destructor
         * @definicion Libera memoria 
         */
        ~Imagen();

        /**
         * @brief Operador de asignacion
         * @param imagen Imagen que utilizaremos desde donde copiar los valores a nuestra imagen
         * @definicion Esta función copia todos los valores de la imagen pasada como argumento a nuestra imagen
         * @return Imagen Esta función devuelve una Imagen que será exactamente igual a la que le hemos pasado por parametro
         */
        Imagen& operator=(const Imagen & imagen);

        /**
         * @brief getColumna
         * @return int Devuelve un entero con la cantidad de columnas
         */
        inline int getColumna() const;

        /**
         * @brief getFila
         * @return int Devuelve un entero con la cantidad de filas
         */
        inline int getFila() const;

        /**
         * @brief getNumeroComentarios
         * @return int Devuelve un entero con la cantidad de comentarios que tiene la imagen
         */
        inline int getNumeroComentarios() const;

        /**
         * @brief getComentarios
         * @return char** Devuelve un puntero a cadena de caracteres
         */
        inline char** getComentarios() const;

        /**
         * @brief getColorMaximo
         * @return int Devuelve un entero con el color maximo de la imagen
         */
        inline int getColorMaximo() const;

        /**
         * @brief getMatrizPixeles
         * @return color** Devuelve un puntero a cadena de unsigned char
         */
        inline color** getMatrizPixeles() const;

        /**
         * @brief Guardara en un archivo todos los datos pasados por parametro
         * @definicion La función escribe en un archivo pasado por parametro
         * todos los datos que se pasan también por parametro.
         * @param name Nombre del archivo donde se escribiran los datos
         * @param m Matriz de colores
         * @param c Columnas de la matriz
         * @param f Filas de la matriz
         * @param com Matriz de comentarios
         * @param num_com Numero de comentarios de la imagen
         * @param color_maximo Color maximo que pueden tener los valores de la matriz
         */
        friend void salvar_pgm(char *name, color** m, int c, int f, char** com, unsigned short num_com, int color_maximo);
        
        /**
         * @brief Leerá de un archivo todos los datos pasados por parametro
         * @definicion La función leerá de un archivo pasado por parametro y guardará todo el contenido
         * de dentro de ese archivo en las distintas variables pasadas por parámetro, de ahí el porque
         * se pasan las variables por referencia
         * @param name Nombre del archivo donde se escribiran los datos
         * @param m Matriz de colores
         * @param c Columnas de la matriz
         * @param f Filas de la matriz
         * @param com Matriz de comentarios
         * @param num_com Numero de comentarios de la imagen
         * @param color_maximo Color maximo que pueden tener los valores de la matriz
         */
        friend void leer_pgm(char *name, color** &m, int & c, int & f, char** &com, unsigned short &num_com, int & color_maximo);
        
        /**
         * @brief Rellena una imagen con el color pasado por parametro
         * @definicion Recorre toda la matriz de colores y los rellena con el color pasado por parametro
         * @param color El color con el cual se va a rellenar toda la matriz
         */ 
        void rellenarImagen(const color & valor);

        /**
         * @brief Contrasta una imagen pasando unos valores por parametro
         * @definicion Se asigna un nuevo valor de color según 2 valores pasados por parametro,
         * el contraste se consigue con una función explicada en el PDF del proyecto
         * @param color valor_maximo El color maximo del contraste
         * @param color valor_minimo El color minimo del contraste
         */ 
        void contrasteImagen(const color & valor_maximo, const color & valor_minimo);
};

void salvar_pgm(char *name, color** m, int c, int f, char** com, unsigned short num_com);
void leer_pgm(char *name, color** &m, int & c, int & f, char** &com, unsigned short &num_com);

#endif

