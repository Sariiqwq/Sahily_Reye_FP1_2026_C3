
#include <stdio.h>

double potencia(int N)
{
    int I, J;
    double TERM, SUM = 0;

    for (I = 1; I <= N; I++)
    {
        TERM = 1;

        for (J = 1; J <= I; J++)
            TERM *= I;

        if (I % 2 == 0)
            SUM -= TERM;
        else
            SUM += TERM;
    }

    return SUM;
}

int main(void)
{
    int N;

    printf("Ingrese el numero de terminos: ");
    scanf("%d", &N);

    if (N < 1)
    {
        printf("Ingrese un numero positivo.\n");
        return 1;
    }

    printf("Resultado: %.0f\n", potencia(N));

    return 0;
}
