#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "EntRelacion.h"

#define color SetConsoleTextAttribute

void BorrarPantalla(){
system("cls");
}

void MenuAtributo (){
    BorrarPantalla();
    printf("INTRODUZCA LOS ATRIBUTOS A LA ENTIDAD\n");
    printf ("1)Atributo simple\n");     // Solo meter el nombre del atributo
    printf ("\n2)Atributo compuesto\n");  // Constituido por dos o varios atributos simples
    printf ("\n3)Atributo mulvivalor\n");   // Puede tener mas de un valor
    printf ("\n4)Avanzar\n");               // Sale de la entidad y da por hecho que termino de insertar atributos
    printf ("\n\n------DIGITE QUE TIPO DE ATRIBUTO DESEA ANADIR: ------\n\n");

}

AtributoSimple InsertaAS (){
    AtributoSimple AS [50];
    int ASV=1;

printf ("Ingresa el nombre del atributo simple: ");
        scanf ("%s" ,&AS->Nombre);

 AS->Tipo = ASV;

return *AS;}


AtributoSimple InsertaASMV (){
    AtributoSimple AS [50];
    int ASMVv = 1;
        printf ("Introduzca valor: ");
        scanf ("%s" ,&AS->Nombre);

AS->Tipo = ASMVv;

return *AS;}


AtributoCompuesto InsertaAC (){
    AtributoCompuesto AC;
    AtributoSimple AS;
    int ACV= 2;
    int i=0,j=0,opcion=1;

    printf ("Introduzca el nombre del atributo: ");
    scanf ("%s", &AC.Nombre);
    puts("");

    //for (i=0; i<100; i++){
        while (opcion == 1){
        AS = InsertaAS() ;
        AC . AtributosS[j] = AS;
        printf ("\nDESEA ANADIR MAS ATRIBUTOS SIMPLES [1 PARA CONTINUAR]");
            scanf ("%d", &opcion);
            j++;
        if (opcion !=1 ){
            break;
                }

        }


//}
    AC.TotalAS = j;

    AC.Tipo = ACV;
return AC;}



AtributoMultivalor InsertaAMV (){
    AtributoMultivalor AMV;
    AtributoSimple AS;
    int AMVv=3;
    int i=0,j=0,opcion=1;

    printf ("Introduzca el nombre del AMV: ");
    scanf ("%s", &AMV.Nombre);
    puts("");

    //for (i=0; i<100; i++){
        while (opcion == 1){
        AS = InsertaASMV() ;
        AMV . Valores[j] = AS;
        printf ("\nDESEA ANADIR MAS VALORES AL ATRIBUTO? [1 PARA CONTINUAR]");
            scanf ("%d", &opcion);
            j++;
        if (opcion !=1 ){
            break;
                }

        }


//}
    AMV.TotalAMV = j;
    AMV.Tipo= AMVv;
return AMV;}


Entidad InsertarEntidad (){
    Entidad E;
    AtributoSimple AS;
    AtributoCompuesto AC;
    AtributoMultivalor AMV;
    int Opciones=1, Evaluacion, i=0;
    int CAS=0, CAC=0, CAMV=0;

    printf ("Inserte nombre de la entidad:");
        scanf ("%s", &E.Nombre);

    printf ("Es una entidad fuerte? [0 PARA INDICAR NO]");
        scanf("%d", &E.EsFuerte);



        for (int a=0; a<3; a++){//while (Opciones == 1){
        MenuAtributo();
        scanf ("%d", &Evaluacion);
        switch (Evaluacion){

        case 1:
            BorrarPantalla();
            AS=InsertaAS();
            E.AS[i] = AS;
            CAS++;
        break;

        case 2:
            BorrarPantalla();
            AC = InsertaAC();
            E.AC[i]= AC;
            CAC++;
        break;

        case 3:
            BorrarPantalla();
            AMV= InsertaAMV();
            E.AMV[i]= AMV;
            CAMV++;
        break;

        case 4:
        BorrarPantalla();
        Opciones=2;
        break;
        }
        if (Opciones==2){break;}
        if (Opciones != 2){
      printf ("Seguir anadiendo mas atributos 1 PARA CONTINUAR: ");
        scanf ("%d", &Opciones);
        if (Opciones !=1)
            break;
        i++;
        }




}


        E.CuantasTotal = i;
        E.CuantasAS = CAS;
        E.CuantasAC = CAC;
        E.CuantasAMV = CAMV;

return E;
}

Relacion InsertarRelacion (){
    Entidad Entidades[1];
    Relacion R;
    char Cardinalidad[10];
    int i;

    printf("Introduzca la cardinalidad de la relacion: ");
        scanf ("%s", &R.CardinalidadRelacion);

        //R.Entidades[0] = E1;
return R;
}

void ImprimeNombreRelacion (char cadena1[21], char  cadena2[21]){
    NombreRelacion n1,n2,n3,n4;
    int random;
    n1.Nombre ="Tiene";
        n1.valor=1;

    n3.Nombre ="Posee";
        n2.valor=2;

    n3.Nombre ="Contiene";
        n3.valor=3;

    random  = rand()%3;
    if (random == 0 )
        printf ("\n%s_%s_%s",cadena1,n1.Nombre,cadena2);

    else if (random == 1)
        printf ("\n%s_%s_%s",cadena1,n2.Nombre,cadena2);

    else if (random == 2)
            printf ("\n%s_%s_%s",cadena1,n3.Nombre,cadena2);


    return;
}


void gotoxy (int x, int y){
    HANDLE Manipulador;
    COORD Coordenandas;
    Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
    Coordenandas.X = x;
    Coordenandas.Y = y;
    SetConsoleCursorPosition(Manipulador, Coordenandas);

}

void ColocaTexto (char *Pal, int pos){
     int size_texto = strlen (Pal);

     gotoxy (40- (size_texto/2),pos); printf("%s",Pal);

}

void DibujaCuadrado(int n,int x, int y, char pal[30]){
int longi;
char Pal[30];
int a=5,i=0,tampico;
HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
color (hConsole, 5);
tampico = strlen(pal);
n=tampico ;
	printf("\n");

        if (n<=3){
        n=n+3;
		for(int ren=1; ren<=n ; ren++)
	  	{
	  		gotoxy (x,y+ren); for(int col=1; col<=n; col++)
	  		{

				if(ren == 1 || ren == n || col== 1 || col==n)
	  			{
					printf("* ");
					i++;

				}
	  			else
	  			{
	  				printf("  ");

				}
			}

			printf("\n");


	  }
	  }//

	  else {for(int ren=1; ren<=n ; ren++)
	  	{
	  		gotoxy (x,y+ren); for(int col=1; col<=n; col++)
	  		{

				if(ren == 1 || ren == n || col== 1 || col==n)
	  			{
					printf("* ");
					i++;

				}
	  			else
	  			{
	  				printf("  ");

				}
			}

			printf("\n");


	  }}
	  gotoxy (x+1,y+3);printf ("%s", pal);gotoxy (0,0);
color (hConsole, 2);
}

void DibujaLineaHorizontal(int n, int x, int y, int flavor){
    int i;
    HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);


    if (flavor == 1){
        color (hConsole, 12);
        gotoxy(x,y);
    for (i=0; i<n; i++){
        printf ("%==");

        }

        }

    else if (flavor == 0){
        color (hConsole, 13);
        gotoxy(x,y);
    for (i=0; i<n; i++){
        printf ("%__");
        }
        }

color (hConsole, 2);
    }
void DibujaLineaVertical(int n, int x, int y,int flavor){
    int i;


    HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);


    if (flavor == 1){
        color (hConsole, 12);
        gotoxy(x,y);
    for (i=0; i<n; i++){
        gotoxy(x,y+i);printf ("||\n");gotoxy(0,0);

        }

        }

    else if (flavor == 0){
        color (hConsole, 13);

    for (i=0; i<n; i++){
        gotoxy(x,y+i);printf ("|\n");gotoxy(0,0);
        }

        }

color (hConsole, 2);
    /*for (i=0; i<n; i++){
    gotoxy(x,y+i); printf ("|");
    printf("\n");gotoxy(0,0);*/



    }


void hola (){
int i,j,num;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    for(i=0; i<num ; i++){
        for(j=0; j<num; j++)
            printf("*");
        printf("\n");
    }
}


void DibujaEntidad (char pal[25],int tipo,int x, int y){
    int i,j,tam;        //0 PP Y 1 PT
int ancho,alto=3;
char letra;

tam = strlen(pal)+2;
    ancho=tam;
    HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
        //SI ES ENTIDAD FUERTE PINTALA DE ROJO
    if (tipo == 0 ){
    color (hConsole, 1);
gotoxy(x,y);
    for (i=1; i<=ancho; i++)

    printf ("*");
    printf ("\n");
    gotoxy(0,0);
    for (i=1; i<=alto-2; i++){
        gotoxy(x,y+1);printf ("*%s*",pal);
            for (j=1; j<=ancho-3; j++)
                printf (" ");
            printf ("\n");
        gotoxy(0,0);
    }
gotoxy(x,y+2);
    for (int i=1; i<=ancho; i++)
        printf ("*");
    printf ("\n");
    color (hConsole, 10);
    gotoxy(0,0);
    }

    //SI ES PARTICIPACION TOTAL LO PINTAS DE AZUL
    else if (tipo == 1 ){
    color (hConsole, 4);
gotoxy(x,y);
    for (i=1; i<=ancho; i++)

    printf ("*");
    printf ("\n");
    gotoxy(0,0);
    for (i=1; i<=alto-2; i++){
        gotoxy(x,y+1);printf ("*%s*",pal);
            for (j=1; j<=ancho-3; j++)
                printf (" ");
            printf ("\n");
        gotoxy(0,0);
    }
gotoxy(x,y+2);
    for (int i=1; i<=ancho; i++)
        printf ("*");
    printf ("\n");
    color (hConsole, 10);
    gotoxy(0,0);
    }

    color (hConsole, 10);

    }


void DibujaRelacion (char pal[25],int tipo,int x, int y, int flavor){
    int i,j,tam;        //0 PP Y 1 PT
int ancho,alto=3;
char letra;

tam = strlen(pal)+2;
    ancho=tam;
    HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
        //SI ES ENTIDAD FUERTE PINTALA DE ROJO
    color (hConsole, flavor);
gotoxy(x,y);
    for (i=1; i<=ancho; i++)

    printf ("*");
    printf ("\n");
    gotoxy(0,0);
    for (i=1; i<=alto-2; i++){
        gotoxy(x,y+1);printf ("*%s*",pal);
            for (j=1; j<=ancho-3; j++)
                printf (" ");
            printf ("\n");
        gotoxy(0,0);
    }
gotoxy(x,y+2);
    for (int i=1; i<=ancho; i++)
        printf ("*");
    printf ("\n");
    color (hConsole, 10);
    gotoxy(0,0);
    }

    void DibujaAtributo(char pal[],int i ,int x, int y,int tipo){ //1 si es normal, 2 si es compuesto, 3 si es multivalor
    int q,r;

    q=strlen(pal);
    r=(q/2)+1;
        HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
    int queda;

            if (tipo == 0){
            queda= 3;
            color (hConsole, 3);
            }
        else if (tipo== 1){
                queda= 7;
            color (hConsole, 7);
            }
            else if (tipo== 2){
                queda= 13;
            color (hConsole, 13);
            }

        DibujaRelacion(pal,1,x,y,queda);
        color (hConsole, queda);
        DibujaLineaVertical(i,x+r,y+3,tipo);
        color (hConsole, 2);


    }



    void DibujaAtributoH(char pal[4],int i ,int x, int y,int tipo){ //1 si es normal, 2 si es compuesto, 3 si es multivalor
    int q,r;

    q=strlen(pal);
    r=(q/2)+1;
        HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
    int queda;

            if (tipo == 0){
            queda= 3;
            color (hConsole, 3);
            }
        else if (tipo== 1){
                queda= 7;
            color (hConsole, 7);
            }
            else if (tipo== 2){
                queda= 13;
            color (hConsole, 13);
            }

        DibujaRelacion(pal,1,x,y,queda);
        color (hConsole, queda);
        DibujaLineaHorizontal(i,x+q+2,y+1,9);
        color (hConsole, 2);


    }

     void InsertarCardinalidad(char Card[3],int x, int y){
    gotoxy(x,y); printf ("%s",Card); gotoxy(0,0);
    }


void DibujaParticipacionV (int t, int x, int y, int participacion){
    if (participacion == 1){
    DibujaLineaVertical(t, x,  y,1);

    }
    else if (participacion == 0){
        DibujaLineaVertical(t, x,  y,participacion);
    }

    else {
        DibujaLineaVertical(t, x,  y,participacion);
    }
}

void DibujaParticipacion (int t, int x, int y, int participacion){
    if (participacion == 1){
    DibujaLineaHorizontal(t, x,  y, participacion);

    }
    else if (participacion == 0){
        DibujaLineaHorizontal(t, x,  y, participacion);
    }

    else {
        DibujaLineaHorizontal(t, x,  y, participacion);
    }
}


void ImprimeAtributos (Entidad E,int x,int y){
gotoxy(x,y-1); printf ("titulo:%s", E.Nombre);  gotoxy(0,0);


    gotoxy(x,y+1); printf("AtributoSimple1:%s", (E.AS[0]).Nombre);  gotoxy(0,0);
    gotoxy(x,y+2); printf ("AtributoSimple2:%s", (E.AS[1]).Nombre);  gotoxy(0,0);
   gotoxy(x,y+3); printf ("AtributoCompuesto1:%s", (E.AC[0]).Nombre);  gotoxy(0,0);
   gotoxy(x,y+4); printf ("AtributoCompuesto2:%s", (E.AS[1]).Nombre);  gotoxy(0,0);
    gotoxy(x,y+5); printf ("AtributoMultivalor1:%s", (E.AMV[0]).Nombre);  gotoxy(0,0);
    gotoxy(x,y+6); printf ("AtributoMultivalor2:%s", (E.AMV[1]).Nombre);  gotoxy(0,0);

}


