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

int main()
{

    //////////////////////////////////////////////////////////////////////////////////////
    /////////////////////// AQUI VA EL CUERPO DEL PROGRAMA COMPLETO /////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
}
