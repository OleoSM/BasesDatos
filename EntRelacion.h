
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TRUE 1


/* TIPOS DE ATRIBUTO
Atributo Simple = 1
Atributo Compuesto = 2
Atributo Multi Valor = 3
Atributo Derivado = 4
*/

typedef struct AtributoSimple
{
    char Nombre[20];
    int Tipo;
}AtributoSimple;

typedef struct AtributoCompuesto{

    char Nombre [20];
    AtributoSimple AtributosS[3];
    int TotalAS;
    int Tipo;

} AtributoCompuesto;

typedef struct AtributoMultivalor{
    char Nombre[20];  //NOMBRE DEL ATRIBUTO
    AtributoSimple Valores[40]; // ATRIBUTOS SIMPLES DEL ATRIBUTO MULTIVALOR
    int TotalAMV;
    int Tipo;
} AtributoMultivalor;

    typedef struct Atributo {
    AtributoSimple AS;
    AtributoCompuesto AC;
    AtributoMultivalor AMV;
    int Tipo;
    int cuantos;
} Atributo;

typedef struct Entidad{

    char Nombre[9];
    AtributoSimple AS[3];
    AtributoCompuesto AC[3];
    AtributoMultivalor AMV[3];
    int EsFuerte;   //RECIBE SOLO VALORES BOOLEANOS [TRUE/FALSE]
    int CuantasTotal;
    int CuantasAS;
    int CuantasAC;
    int CuantasAMV;
    //int Participacion[2];

}Entidad;

    typedef struct Relacion{

    char Nombre[21];
    Entidad Entidades[3];
    char CardinalidadRelacion[10];
    int Participacion[2];
    int opcion [3];
    int TotRel;

}Relacion;
    typedef struct NombreRelacion{
    char *Nombre;
    int valor;

    } NombreRelacion;

//Atributo InsertaAtributo ();
//Relacion InsertarRelacion ();
void BorrarPantalla();
void MenuAtributo ();
Relacion CreaRelacion ();
AtributoSimple InsertaAS ();
AtributoSimple InsertaASMV ();
AtributoCompuesto InsertaAC ();
AtributoMultivalor InsertaAMV ();
Relacion InsertarRelacion ();
void ImprimeNombreRelacion (char cadena1[21], char  cadena2[21]);
void DibujaEntidad (char pal[25],int tipo, int x, int y);


void gotoxy (int a, int b);
void ColocaTexto (char *Pal, int pos);
void DibujaCuadrado(int n,int x, int y, char pal[30]);
void DibujaLineaHorizontal(int n, int x, int y, int flavor);
void DibujaLineaVertical(int n, int x, int y,int flavor);
void DibujaEntidad (char pal[25],int tipo,int x, int y);
void DibujaRelacion(char pal[25],int tipo,int x, int y, int flavor);
void DibujaAtributo(char pal[4],int i ,int x, int y, int tipo);
void DibujaAtributoH(char pal[25],int i ,int x, int y,int tipo);
void InsertarCardinalidad(char Card[3],int x, int y);
void DibujaParticipacionV (int t, int x, int y, int participacion);
void DibujaParticipacion (int t, int x, int y, int participacion);
void ImprimeAtributos (Entidad E,int x,int y);
