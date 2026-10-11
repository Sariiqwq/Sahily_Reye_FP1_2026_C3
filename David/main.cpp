
#include <stdio.h>

int inverso(int N)
{
    int A, B, C, D;

    A = N / 1000;
    B = (N / 100) % 10;
    C = (N / 10) % 10;
    D = N % 10;

    return D * 1000 + C * 100 + B * 10 + A;
}

int main(void)
{
    int N;

    printf("Ingrese un numero de cuatro digitos: ");
    scanf("%d", &N);

    if (N < 1000 || N > 9999)
    {
        printf("El numero debe tener cuatro digitos.\n");
        return 1;
    }

    printf("Numero invertido: %04d\n", inverso(N));

    return 0;
}
