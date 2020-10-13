#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//	En nameFile deben colocar el nombre del archivo con el cual van a ejecutar.
//	Ej: "01_abierto.txt"

char nameFile[30] = {"01_abierto.txt"};

/*====================================================================================
====================================================================================*/

char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if (str == NULL)
    {
        return NULL;
    }
    if (str[0] == '\0')
    {
        return str;
    }

    len = strlen(str);
    endp = str + len;

    while (isspace((unsigned char)*frontp))
    {
        ++frontp;
    }
    if (endp != frontp)
    {
        while (isspace((unsigned char)*(--endp)) && endp != frontp)
        {
        }
    }

    if (str + len - 1 != endp)
        *(endp + 1) = '\0';
    else if (frontp != str && endp == frontp)
        *str = '\0';

    endp = str;
    if (frontp != str)
    {
        while (*frontp)
        {
            *endp++ = *frontp++;
        }
        *endp = '\0';
    }

    return str;
}

//esta función obtiene el valor que se necesita, ejemplo: #piel,#ojoIzq,etc.
int getValor(char *valor)
{

    FILE *file = fopen(nameFile, "r");

    if (NULL == file)
    {
        fprintf(stderr, "Error al abrir el archivo\n");
        return 1;
    }

    size_t buffer_size = 80;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    int line_number = 0;

    while (-1 != getline(&buffer, &buffer_size, file))
    {
        char *aux = buffer;
        aux = trim(buffer);

        if (strcmp(aux, valor) == 0)
        {
            fflush(stdout);
            fclose(file);
            free(buffer);
            return ++line_number;
        }

        ++line_number;
    }
}

int loadRango(char region[])
{

    //	Esta función parsea el rango de los array a cargar
    //	Parametros: regio[] - De que región cargar el n
    //	Ej: "ojoIzq"

    int linea = getValor(region);

    FILE *file = fopen(nameFile, "r");

    if (NULL == file)
    {
        fprintf(stderr, "Error al abrir el archivo\n");
        return 1;
    }

    size_t buffer_size = 80;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    int line_number = 0;
    while (-1 != getline(&buffer, &buffer_size, file))
    {

        if (linea == line_number)
        {

            char *aux = buffer;
            aux = trim(buffer);
            aux = strtok(aux, "n");

            int y = atoi(aux);
            fflush(stdout);
            fclose(file);
            free(buffer);

            return y;
        }
        ++line_number;
    }
}

void loadCoord(int cant, int coordX[], int coordY[], char region[])
{

    //	Esta función parsea los datos de las coordenadas
    //	Parametros:
    //		- cant: n cargado anteriormente (dimension del array)
    //		- coordX[]: array donde almacenar las coordenadas en x
    //		- coordY[]: array donde almacenar las coordenadas en y
    //		- region[]: region de la cual se pretende cargar las coordenadas.
    //	Ej: loadCoord(Nojo,xOjoIz,yOjoIz,"#ojoIzq")ñ

    int linea = getValor(region);

    FILE *file = fopen(nameFile, "r");

    if (NULL == file)
    {
        fprintf(stderr, "Error al abrir el archivo\n");
        return;
    }

    size_t buffer_size = 80;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    int line_number = 0;
    int inc = 0;

    while (-1 != getline(&buffer, &buffer_size, file))
    {

        ++line_number;
        int cont = (linea + cant) + 1;

        if (line_number > (linea + 1) && line_number < (cont + 1))
        {

            char *coso = buffer;
            coso = trim(coso);
            coso = strtok(coso, " ");
            coordX[inc] = atoi(coso);
            coso = strtok(NULL, " ");
            coordY[inc] = atoi(coso);
            ++inc;
        }
    }

    fflush(stdout);
    fclose(file);
    free(buffer);
}
/*====================================================================================
====================================================================================*/

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////// AQUI VAN LAS FUNCIONES A IMPLEMENTAR /////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

//EJERCICIO 2

/**
* Calcula la distancia entre dos pares de coordenadas
*
* @param x1
* @param y1
* @param x2
* @param y2
* @return Disatancia entre dos puntos
*/
int distancia(int x1, int y1, int x2, int y2)
{
    //Se debe devolver --> raiz cuadrada de: (x2 −x2)^2 +(y2 −y2)^2
}

/**
* Calcula el centroide dado dos arrays de puntos
*
* @param coord almacenar las coordenadas (x, y) del centroide a calcular
* @param coordX coordenadas x de los puntos
* @param coordY coordenadas y de los puntos
* @param tam tamanio de los vectores
* @return Coordneadas X e Y del centroide
*/
int centroide(int coord[], int coordX[], int coordY[], int tam)
{
    /*
    int CentX
    int CentY
    int sumCoordX
    int sumCoordY

    for cX in coordX
        sumCoordX + cX
    
    for cY in coordY
        sumCoordY + cY

    return [1/tam * sumCoordX, 1/tam * sumCoordY] --> Devuelve un array de 2, con X e Y del centroide
    */
}

/**
* Calcula el angulo dado dos puntos (Figura 3)
*
* @param puntoA Coordenadas centroide A
* @param puntoB Coordenadas centroide B
* @return Angulo en grados
*/
int calcularAngulo(int puntoA[], int puntoB[])
{
    /*
        Este está complicado jaja, todavía no entendí bien el cálculo
    */
}


//Ejercicio 3

/**
* Resuelve si el ojo está abierto
*
* @param punto1 Coordenadas del punto 1 y 2 del ojo
* @return True: Ojo abierto
*/
int ojoAbierto(int punto1, int punto2)
{
    /*
    Si la distancia entre estos puntos de cada OJO es menor a 30 px --> Está cerrado
    Imprimir en pantalla: distancia y si está abierto o cerrado
    return --> si distancia(punto1, punto2) > 30: True, de lo contrario, False
    */
}

// TODO Parte 2 y 3 del Ejercicio 3

int main()
{

    //////////////////////////////////////////////////////////////////////////////////////
    /////////////////////// AQUI VA EL CUERPO DEL PROGRAMA COMPLETO /////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////

    // EJERCICIO 1

    // Cargar en dos variables enteras la dimensi ́on (n) de los vectores coordenadas
    int NojoIzq = loadRango("#ojoIzq");
    int NojoDer = loadRango("#ojoDer");
    int NbocInt = loadRango("#bocaInt");

    //Defino array para las coord (x,y) de ambos ojos y el interior de la boca
    int xOjoIzq[NojoIzq], yOjoIzq[NojoIzq];
    int xOjoDer[NojoDer], yOjoDer[NojoDer];
    int xBocaInt[NbocInt], yBocaInt[NbocInt];

    //Cargo las coordenadas en los array definidos
    loadCoord(NojoIzq, xOjoIzq, yOjoIzq, "#ojoIzq");
    loadCoord(NojoDer, xOjoDer, yOjoDer, "#ojoDer");
    loadCoord(NbocInt, xBocaInt, yBocaInt, "#bocInt");
    fprintf(stderr, "Inicio\n");
}
