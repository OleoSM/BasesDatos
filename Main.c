/*
Autores:
Buendia Velazco Abel
Dominguez Paez Alejandro Yael
Hernandez Molina Leonardo Gaell
Velazquez Díaz Luis Francisco
Materia: Bases de datos

Descripcion: Programa capáz de modelar un modelo entidad relacion a partir de brindarle los datos

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "EntRelacion.c"
#define TAM 6


int main (){
Entidad E[5];
int z, EntidadElegidaA, EntidadElegidaB;
AtributoSimple AS;
AtributoCompuesto AC;
AtributoMultivalor AMV;
Relacion R[4];
Entidad E1,E2;
char ESFOD[10]="DFFFFFFF";
int Opcion = 1;

srand (time(NULL));
char *palaux1, *palaux2;
int ttor=0 ;
int NOSE=0;
//AS=InsertaAS();
/*
printf ("%s", &AS.Nombre);
puts("---------------------");*/
/*
AMV=InsertaAMV();
printf ("%d", AMV.TotalAMV);
puts("");
    for (int i=0 ; i < AMV.TotalAMV ; i++){
       printf ("%s ", AMV.Valores[i]);



    }

*/

    for (int i=0; i<4 ; i++){
        if (Opcion == 1){
            E[i]= InsertarEntidad();
            printf ("Insertar otra entidad? [1] para continuar\n");
                scanf ("%d", &Opcion);

        }


        else
        {
        break;
        }

    printf ("Entidad 0) %s\n",E[0].Nombre);

    printf ("Entidad 1) %s\n", E[1].Nombre);

    printf ("Entidad 2) %s\n", E[2].Nombre);

    printf ("Entidad 3) %s\n", E[3].Nombre);

    //printf ("Entidad 4) %s\n", E[4].Nombre);




    system ("pause");
    BorrarPantalla();
    }
    BorrarPantalla();

    printf ("------ENTIDADES DISPONIBLES------\n");

    printf ("Entidad 0) %s\n",E[0].Nombre);

    printf ("Entidad 1) %s\n", E[1].Nombre);

    printf ("Entidad 2) %s\n", E[2].Nombre);

    printf ("Entidad 3) %s\n", E[3].Nombre);

    //printf ("Entidad 4) %s\n", E[4].Nombre);

    printf ("\n------------\n");


    for (z=0 ; z<4 ;z++){
            fflush(stdin);
            ErrorA:
            BorrarPantalla();

 //Por si inserta dos entidades debiles, se lo vuelve a pedir
    printf ("------ENTIDADES DISPONIBLES------\n");

    printf ("Entidad 0) [%c]) %s\n", ESFOD[E[0].EsFuerte] ,E[0].Nombre);

    printf ("Entidad 1) [%c]) %s\n", ESFOD[E[1].EsFuerte] ,E[1].Nombre);

    printf ("Entidad 2) [%c]) %s\n", ESFOD[E[2].EsFuerte] ,E[2].Nombre);

    printf ("Entidad 3) [%c] ) %s\n " ,ESFOD[E[3].EsFuerte] ,E[3].Nombre);

    //printf ("Entidad 4) %s\n", E[4].Nombre);

    printf ("\n------------\n");


    printf ("Inserte la entidad 1 para la relacion [9 CHAR]\n");
        scanf ("%d", &EntidadElegidaA);

    printf ("Inserte la entidad 2 para la relacion [9 CHAR]\n");
        scanf ("%d", &EntidadElegidaB);

    R[z] = InsertarRelacion();
    R[z].Entidades[0] = E[EntidadElegidaA];
    R[z].Entidades[1] = E[EntidadElegidaB];

    if (R[z].Entidades[0].EsFuerte == 0 && R[z].Entidades[1].EsFuerte == 0){
        BorrarPantalla();
        printf ("Error: No puede usar 2 entidades debiles para una relacion... \nPor favor intente de nuevo...\n\n");
        system("pause");
        goto ErrorA;

    }

    printf("\nIntroduzca la participacion para la entidad )%s [0 = PP, 1= PT]\n", (R[z].Entidades[0]).Nombre);
            scanf ("%d", &R[z].Participacion[0]);

    printf("\nIntroduzca la participacion para la entidad )%s [0 = PP, 1= PT]\n", (R[z].Entidades[1]).Nombre);
            scanf ("%d", &R[z].Participacion[1]);

    printf ("\nDesea insertar otra relacion? [1 para continuar]: ");
            scanf ("%d", &Opcion);
    NOSE++;
        if (Opcion != 1 ){
        break;
            }
            ttor++;
        BorrarPantalla();
    }

    R[0].TotRel=z;
    int totrel;

    totrel= R[0].TotRel;



int q;
z=3;
int r;
int entidades=1;

int TotAtr=3;
printf ("%d",ttor);
system("pause");

r=NOSE-1;

    switch (r){
        case 0:
    BorrarPantalla();


    DibujaEntidad ((R[0].Entidades[0]).Nombre, (R[0].Entidades[0]).EsFuerte ,35-15,15-10);//PRIMERA
    DibujaEntidad ((R[0].Entidades[1]).Nombre, (R[0].Entidades[1]).EsFuerte ,115-15 ,15-10);//SEGUNDA

    DibujaParticipacion(13,35+9-15,15+1-10,R[0].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 16-10,R[0].Participacion[1]);

    DibujaRelacion ("Relacion_1", 0, 77-3-15,15-10,6);


    InsertarCardinalidad(R[0].CardinalidadRelacion, 77+2-15,15-11);//LA DE ARRIBA

    ImprimeAtributos(E[0],15,31);
    ImprimeAtributos(E[1],50,31);

    break;

        case 1:


        BorrarPantalla();

    DibujaEntidad ((R[0].Entidades[0]).Nombre, (R[0].Entidades[0]).EsFuerte ,35-15,15-10);//PRIMERA
    DibujaEntidad ((R[0].Entidades[1]).Nombre, (R[0].Entidades[1]).EsFuerte ,115-15 ,15-10);//SEGUNDA


    DibujaRelacion ("Relacion_1", 0, 77-3-15,15-10,6);
    //DibujaLineaHorizontal(13,77+10,16,1);

    DibujaParticipacion(13,35+9-15,15+1-10,R[0].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 16-10,R[0].Participacion[1]);

    //DIBUJA ENTIDADES, PARTICIPACION Y RELACION DE ABAJO
    DibujaEntidad ((R[1].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-15,30-10);//TERCERA
    DibujaEntidad ((R[1].Entidades[1]).Nombre, (R[1].Entidades[1]).EsFuerte, 115-15,30-10);//CUARTA
     //ENTRE 2 Y 4 DESPUES DE LA RELACION


    DibujaRelacion ("Relacion_2", 0,77-3-15,30-10,6);
    DibujaParticipacion(13,35+9-15,30+1-10,R[1].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 30+1-10,R[1].Participacion[1]);

    InsertarCardinalidad(R[0].CardinalidadRelacion, 77+2-15,15-11);//LA DE ARRIBA
    InsertarCardinalidad(R[1].CardinalidadRelacion, 77+2-15,30-11); //LA DE ABAJO

    ImprimeAtributos(E[0],15,31);
    ImprimeAtributos(E[1],50,31);




        puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;



        case 2:

        BorrarPantalla();

    DibujaEntidad ((R[0].Entidades[0]).Nombre, (R[0].Entidades[0]).EsFuerte ,35-15,15-10);//PRIMERA
    DibujaEntidad ((R[0].Entidades[1]).Nombre, (R[0].Entidades[1]).EsFuerte ,115-15 ,15-10);//SEGUNDA


    DibujaRelacion ("Relacion_1", 0, 77-3-15,15-10,6);
    //DibujaLineaHorizontal(13,77+10,16,1);

    DibujaParticipacion(13,35+9-15,15+1-10,R[0].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 16-10,R[0].Participacion[1]);

    //DIBUJA ENTIDADES, PARTICIPACION Y RELACION DE ABAJO
    DibujaEntidad ((R[1].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-15,30-10);//TERCERA
    DibujaEntidad ((R[1].Entidades[1]).Nombre, (R[1].Entidades[1]).EsFuerte, 115-15,30-10);//CUARTA
     //ENTRE 2 Y 4 DESPUES DE LA RELACION

    DibujaLineaVertical(4,35-10-15,15-10+3,R[2].Participacion[0] );
    DibujaLineaVertical(4,35-10-15,23-10+3,R[2].Participacion[1] );

    DibujaRelacion ("Relacion_2", 0,77-3-15,30-10,6);
    DibujaParticipacion(13,35+9-15,30+1-10,R[1].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 30+1-10,R[1].Participacion[1]);
    DibujaRelacion ("Relacion_3", 0,35-31,13,6);//Relacion de enmedio a la derecha //MODIFICADO
    //DibujaRelacion ("Relacion_4", 0,115-9,13,6);//Relacion de Enmedio a la izquierda  DibujaEntidad (ENT4, 1,115,30-10);// 115-15+30 MODIFICADOTE

     //ENTRE 1 Y 3
    //DibujaLineaVertical(4,115-3,15-10+3,R[2].Participacion[0] ); //ENTRE 2 Y 4 ajdgadgahdgashdgahjajdgadgahdgashdgahj
    //DibujaLineaVertical(4,115-3,23-10+3,R[2].Participacion[1] ); //ENTRE 2 Y 4 DESPUES DE LA RELACION   ADJGADGASHDHGHASDHASDGHJDGASHDJAS



    InsertarCardinalidad(R[0].CardinalidadRelacion, 77+2-15,15-11);//LA DE ARRIBA
    InsertarCardinalidad(R[1].CardinalidadRelacion, 77+2-15,30-11); //LA DE ABAJO
    InsertarCardinalidad(R[2].CardinalidadRelacion, 35+4-15-15,13-1);//LA DE ENMEDIO A LA DERECHA //MODIFICADO
    //InsertarCardinalidad(R[3].CardinalidadRelacion, 115-3,13-1);//LA DE ENMEDIO A LA IZQUIERDA      //MODIFICADO

    DibujaEntidad ((R[2].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-26,30-10);
    DibujaEntidad ((R[2].Entidades[1]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-26,15-10);

    //DibujaEntidad ((R[3].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,115-4,30-10);
    //DibujaEntidad ((R[3].Entidades[1]).Nombre, (R[1].Entidades[0]).EsFuerte ,115-4,15-10);


    ImprimeAtributos(E[0],15,31);
    ImprimeAtributos(E[1],50,31);
    //ImprimeAtributos(E[2],85,31);
    ImprimeAtributos(E[3],15,31+15);
        //InsertarCardinalidad(pal51, 35+3,13-1);
        //DibujaLineaHorizontal(13,77+q,15+1 );

    //DIBUJA ENTIDADES PARTICIPACION Y RELACION DE LA DERECHA


        puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;

    case 3:
   BorrarPantalla();

    DibujaEntidad ((R[0].Entidades[0]).Nombre, (R[0].Entidades[0]).EsFuerte ,35-15,15-10);//PRIMERA
    DibujaEntidad ((R[0].Entidades[1]).Nombre, (R[0].Entidades[1]).EsFuerte ,115-15 ,15-10);//SEGUNDA


    DibujaRelacion ("Relacion_1", 0, 77-3-15,15-10,6);
    //DibujaLineaHorizontal(13,77+10,16,1);

    DibujaParticipacion(13,35+9-15,15+1-10,R[0].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 16-10,R[0].Participacion[1]);

    //DIBUJA ENTIDADES, PARTICIPACION Y RELACION DE ABAJO
    DibujaEntidad ((R[1].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-15,30-10);//TERCERA
    DibujaEntidad ((R[1].Entidades[1]).Nombre, (R[1].Entidades[1]).EsFuerte, 115-15,30-10);//CUARTA
     //ENTRE 2 Y 4 DESPUES DE LA RELACION

    DibujaLineaVertical(4,35-10-15,15-10+3,R[2].Participacion[0] );
    DibujaLineaVertical(4,35-10-15,23-10+3,R[2].Participacion[1] );

    DibujaRelacion ("Relacion_2", 0,77-3-15,30-10,6);
    DibujaParticipacion(13,35+9-15,30+1-10,R[1].Participacion[0] );
    DibujaParticipacion (13, 77+10-15, 30+1-10,R[1].Participacion[1]);
    DibujaRelacion ("Relacion_3", 0,35-31,13,6);//Relacion de enmedio a la derecha //MODIFICADO
    DibujaRelacion ("Relacion_4", 0,115-9,13,6);//Relacion de Enmedio a la izquierda  DibujaEntidad (ENT4, 1,115,30-10);// 115-15+30 MODIFICADOTE

     //ENTRE 1 Y 3
    DibujaLineaVertical(4,115-3,15-10+3,R[3].Participacion[0] ); //ENTRE 2 Y 4 ajdgadgahdgashdgahjajdgadgahdgashdgahj
    DibujaLineaVertical(4,115-3,23-10+3,R[3].Participacion[1] ); //ENTRE 2 Y 4 DESPUES DE LA RELACION   ADJGADGASHDHGHASDHASDGHJDGASHDJAS



    InsertarCardinalidad(R[0].CardinalidadRelacion, 77+2-15,15-11);//LA DE ARRIBA
    InsertarCardinalidad(R[1].CardinalidadRelacion, 77+2-15,30-11); //LA DE ABAJO
    InsertarCardinalidad(R[2].CardinalidadRelacion, 35+4-15-15,13-1);//LA DE ENMEDIO A LA DERECHA //MODIFICADO
    InsertarCardinalidad(R[3].CardinalidadRelacion, 115-3,13-1);//LA DE ENMEDIO A LA IZQUIERDA      //MODIFICADO

    DibujaEntidad ((R[2].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-26,30-10);
    DibujaEntidad ((R[2].Entidades[1]).Nombre, (R[1].Entidades[0]).EsFuerte ,35-26,15-10);

    DibujaEntidad ((R[3].Entidades[0]).Nombre, (R[1].Entidades[0]).EsFuerte ,115-4,30-10);
    DibujaEntidad ((R[3].Entidades[1]).Nombre, (R[1].Entidades[0]).EsFuerte ,115-4,15-10);


    ImprimeAtributos(E[0],15,31);
    ImprimeAtributos(E[1],50,31);
    ImprimeAtributos(E[2],85,31);
    ImprimeAtributos(E[3],15,31+15);
        //InsertarCardinalidad(pal51, 35+3,13-1);
        //DibujaLineaHorizontal(13,77+q,15+1 );

    //DIBUJA ENTIDADES PARTICIPACION Y RELACION DE LA DERECHA


        puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        break;
 }

    return 0;

}


