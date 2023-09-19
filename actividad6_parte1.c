#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu(void);
int  msges(void);

//fibonacci
void fibonaccis(void);
void fibonacci_for(void);
void fibonacci_while(void);
void fibonacci_do_while(void);

//factoriales
void factoriales(void);
void factorial_for(void);
void factorial_while(void);
void factorial_do_while(void);

//digitos
void digitos(void);
void digitos_for(void);
void digitos_while(void);
void digitos_do_while(void);

int valid(char msge[], int ri, int rf);

int main()
{

    menu();

    return 0;
}

int msges()
{
    int opcion;
    printf("1) fibonacci\n");
    printf("2) factorial\n");
    printf("3) cantidad de digitos\n");
    printf("0) terminar programa.\n");
    printf("elije una opcion: \n");
    scanf("%d",& opcion);

    return opcion;
}
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            fibonaccis();
            break;
        case 2:
            factoriales();
            break;
        case 3:
            digitos();
            break;
        }

    } while (op != 0);
}

void fibonaccis()
{
    int opcion;
    printf("1) fibonacci con ciclo for\n");
    printf("2) fibonacci con ciclo while\n");
    printf("3) fibonacci con ciclo do while\n");
    printf("elije una opcion: \n");
    scanf("%d",& opcion);
    switch (opcion)
    {
    case 1:
        fibonacci_for();
        break;

    case 2:
        fibonacci_while();
        break;

    case 3:
        fibonacci_do_while();
        break;
    }
}

void factoriales()
{
    int opcion;
    printf("1) factorial con ciclo for\n");
    printf("2) factorial con ciclo while\n");
    printf("3) factorial con ciclo do while\n");
    printf("elije una opcion: \n");
    scanf("%d",& opcion);
    switch (opcion)
    {
    case 1:
        factorial_for();
        break;

    case 2:
        factorial_while();
        break;

    case 3:
        factorial_do_while();
        break;
    }
}

void digitos()
{
    int opcion;
    printf("1) cantidad de digitos con ciclo for\n");
    printf("2) cantidad de digitos con ciclo while\n");
    printf("3) cantidad de digitos con ciclo do while\n");
    printf("elije una opcion: ");
    scanf("%d",& opcion);
    switch (opcion)
    {
    case 1:
        digitos_for();
        break;

    case 2:
        digitos_while();
        break;

    case 3:
        digitos_do_while();
        break;
    }
}

void fibonacci_for()
{
    int repetir, tempnum=0, tempnum2=1, result, op;
    printf("cuantas veces quieres que se realice el programa? :");
    scanf("%d",& repetir);

    for (int i = 0; i <= repetir; i++)
    {
        printf("%d ", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
    }
    op = leave();
}

int valid(char msge[], int ri, int rf)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", msge);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

int leave()
{
    int op;
    printf("\n\nDesea salir?\n");
    printf("0.- No\n");
    printf("1.- Si\n");
    op = valid("Selecciona una opcion: ", 0, 1);
    return op;
}

void fibonacci_while()
{
    int op, num, i, tempnum, tempnum2, result;
    result = 0;
    do
    {
        printf("\nMETODO DE FIBONACCI POR WHILE\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);
        i = 0;
        tempnum = 0;
        tempnum2 = 1;

        while (i <= num)
        {
            printf(" %d ", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
            i++;
        }
        op = leave();

    } while (op != 1);
}

void fibonacci_do_while()
{
    int op, num, i, tempnum, tempnum2, result;
    do
    {
        printf("\nMETODO DE FIBONACCI POR DO WHILE\n");
        num = valid("Introduce la cantidad de numeros Fibonacci que desees imprimir: ", 0, INT_MAX);
        i = 0;
        tempnum = 0;
        tempnum2 = 1;
        do
        {
            printf("%d ", tempnum);
            result = tempnum2 + tempnum;
            tempnum = tempnum2;
            tempnum2 = result;
            i++;
        } while (i <= num);
        op = leave();
    } while (op != 1);
}

void factorial_for()
{
    int op, num, i, result, tempnum;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);

        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            for (i = num, result = 1, tempnum = 1; i != 0; i--)
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
            }
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();

    } while (op != 1);
}

void factorial_while()
{
    int op, num, i, result, tempnum;
    i = 1;
    result = 1;
    tempnum = 1;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR WHILE\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);
        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            i = num;
            while (i != 0)
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
                i--;
            }
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();
    } while (op != 1);
}

void factorial_do_while()
{
    int op, num, i, result, tempnum;
    i = 1;
    result = 1;
    tempnum = 1;
    do
    {
        printf("\nOBTENER UN FACTORIAL POR DO WHILE\n");
        num = valid("Por favor, ingresa un numero al que desee conocer su factorial: ", 0, INT_MAX);
        if (num < 0)
        {
            printf("Introduce un valor positivo\n");
        }
        else
        {
            i = num;
            do
            {
                result *= i;
                printf("\n%d * %d = %d", tempnum, i, result);
                tempnum = result;
                i--;
            } while (i != 0);
            printf("\nEl factorial de %d es: %d", num, result);
        }
        op = leave();
    } while (op != 1);
}


void digitos_for()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);

        for (i = 1, tempnum = 1, result = 1; tempnum <= num; i++)
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
        }
        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}

void digitos_while()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);
        i = 1;
        tempnum = 1;
        result = 0;
        while (tempnum <= num)
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
            i++;
        }

        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}

void digitos_do_while()
{
    int i, num, op, tempnum, result;
    do
    {
        printf("\nOBTENER CANTIDAD DE DIGITOS POR FOR\n");
        num = valid("Por favor, ingresa un numero al que desee conocer la cantidad de digitos: ", 0, INT_MAX);
        i = 1;
        tempnum = 1;
        result = 0;
        do
        {
            tempnum *= 10;
            if (tempnum >= num)
            {
                result = i;
            }
            i++;
        } while (tempnum <= num);

        printf("El numero %d tiene %d digitos", num, result);
        op = leave();
    } while (op != 1);
}