
#include <stdio.h>

int perfecto(int NUM)
{
    int I, SUM = 0;

    for (I = 1; I <= NUM / 2; I++)
    {
        if (NUM % I == 0)
            SUM += I;
    }

    return SUM == NUM;
}

int main(void)
{
    int N, I;

    printf("Ingrese el limite N: ");
    scanf("%d", &N);

    if (N < 1)
    {
        printf("Ingrese un numero positivo.\n");
        return 1;
    }

    printf("Numeros perfectos entre 1 y %d:\n", N);

    for (I = 1; I <= N; I++)
    {
        if (perfecto(I))
            printf("%d\n", I);
    }

    return 0;
}
