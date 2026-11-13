
#include <stdio.h>

double serie(int N)
{
    int I;
    double RES = 1.0;

    for (I = 2; I <= N; I++)
    {
        if (I % 2 == 0)
            RES *= 1.0 / I;
        else
            RES /= 1.0 / I;
    }

    return RES;
}

int main(void)
{
    int NUM;

    printf("Ingrese el numero de terminos: ");
    scanf("%d", &NUM);

    if (NUM < 1)
    {
        printf("El numero debe ser positivo.\n");
        return 1;
    }

    printf("Resultado: %.6f\n", serie(NUM));

    return 0;
}
