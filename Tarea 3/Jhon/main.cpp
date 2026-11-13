
#include <stdio.h>

long long factorial(int N)
{
    int I;
    long long RES = 1;

    for (I = 1; I <= N; I++)
        RES *= I;

    return RES;
}

int main(void)
{
    int NUM;

    printf("Ingrese un numero: ");
    scanf("%d", &NUM);

    if (NUM < 0 || NUM > 20)
    {
        printf("Ingrese un numero entre 0 y 20.\n");
        return 1;
    }

    printf("El factorial es: %lld\n", factorial(NUM));

    return 0;
}
