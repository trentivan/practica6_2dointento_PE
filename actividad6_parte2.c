// Hernandez Ceseña Ivan Fernando  373077
//  17/09/23
// 
// NYP_ACT6_p2_932
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


//control de codigo
int msgs(void);
void menu(void);

//funciones
void promedios(void);
void tablas(void);
void media_numeros(void);
void embarcacion(void);
void limite_materia(void);

//validacion
int validar1(char msgs[], int li, int ls);

int main()
{
    menu();
    return 0;
}

int msgs()
{
    int opcion=0;
    printf("\n1) promedios.\n");
    printf("2) tablas de multiplicar.\n");
    printf("3) media de numeros entre rango dado por ti.\n");
    printf("4) embarcacion finisterra.\n");
    printf("5) limite para cursar una materia\n");
    printf("0) terminar programa. (lo vas a tener que presionar en el siguiente menu tambien)\n");
    printf("elije una opcion:\n");
    opcion = validar1("selecciona una opcion ", 0, 5);

    return opcion;
}

void menu()
{
    int op;
    do
    {
        fflush(stdin);
        op = msgs();
        switch (op)
        {
        case 1:
            promedios();
            break;
        case 2:
            tablas();
            break;
        case 3:
            media_numeros();
            break;
        case 4:
            embarcacion();
            break;
        case 5:
            limite_materia();
            break;
        }
    } while (op != 0);
}

void promedios()
{
    int promedio, cal1, cal2, cal3, cal4, cal5;
    int reprobados=0, n=5, suma, i;

    for(i=0; i<n; i++)
    {
        cal1=validar1("dame la primer calificacion ", 0, 100);
        cal2=validar1("dame la segunda calificacion ", 0, 100);
        cal3=validar1("dame la tercer calificacion ", 0, 100);
        cal4=validar1("dame la cuarta calificacion ", 0, 100);
        cal5=validar1("dame la quinta calificacion ", 0, 100);
        promedio= (cal1+cal2+cal3+cal4+cal5)/5;
        suma=+promedio;
        printf("el promedio es: %d\n\n", promedio);
        if(promedio<=50)
        {
            reprobados++;
        }
    }
    printf("el promedio de los %d alumnos = %d\n", i,suma/i);
    printf("el numero de alumnos que no tienen derecho a examen de recuperacion es: %d\n", reprobados);
    menu();
}

void tablas()
{
    for(int i=1; i<=10; i++)
    {
        printf("pulsa cualquier letra para continuar\n");
        getch();
        for(int j=1; j<=10; j++)
        {
            printf("%d * %d= %d\n",i, j, i*j);
        }
    }
    menu();
}
void media_numeros()
{
    int rango_s, rango_in, num, n, acumulador=0, numeros=0;
    int divisor=0; 
    float prom;
    printf("cuantos numeros quieres evaluar?\n");
    scanf("%d",& n);
    printf("dame tu limite inferior\n");
    scanf("%d",& rango_in);
    printf("dame tu limite superior\n");
    scanf("%d",& rango_s);

    for(int i=0;  i<n; i++, divisor++)
    {
        num=validar1("dame un numero", rango_in, rango_s);
        numeros=+numeros + num;        
    }

    prom= (float)numeros / (float)divisor;
    printf("la suma de todos los numeros es: %d\n", acumulador);
    printf("la media es: %.2f\n", prom);
    menu();
}
void embarcacion()
{
    //peso[15], 
    int kilos=0, i, peso, prom, num=0;
    for(i=1 ; i<=15 && kilos<=(700*1.15) ; i++)
    {
        peso=validar1("dame tu peso ", 0, 700);
        kilos= kilos + peso;
        num++;
    } 
    if(kilos<=(700*1.15))
    {
        printf("no se paso el limite de peso\n");
    }
    else
    {
        printf("se paso el limite de peso\n");
        printf("el numero de pasajeros a navegar es: %d\n", i-1);
    }
    if(i<=15)
    {
        printf("no se paso el limite de tripulantes\n");
    }
    prom= (float)kilos / (float)num;
    printf("el promedio de peso es: %d\n", prom);
    menu();
}
void limite_materia()
{
    int cal1, cal2, cal3, prom;

    for(int i=1;prom<60 && i<=3; i++)
    {
        cal1= validar1("dame tu primer calificacion ", 0, 100);
        cal2= validar1("dame tu segunda calificacion ", 0, 100);
        cal3= validar1("dame tu tercer calificacion ", 0, 100);
        prom= (cal1 + cal2 + cal3)/3;
        if(prom<60)
        {
            printf("debes repetir la materia");
        }
    }
     if(prom>=60)
    {
        printf("alcanzaste el promedio necesario en una de las tres oportunidades.\n");
    }
    else
    {
        printf("no tienes el promedio necesario para pasar\n");
        printf("fuiste dado de baja definitiva");
    }
    fflush(stdin);
    menu();
}

int validar1(char msgs[], int li, int ls)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msgs);
        fflush(stdin);
        gets(cadena);
        num= atoi(cadena);
        if(num<li || num>ls)
        {
            printf("valor invalido. ingrese otro valor.\n");
        }

    }while(num<li || num>ls);
    
    return num;
}