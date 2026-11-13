
#include <stdio.h>
#include <math.h>

double coseno(double X, int *C)
{
    double TERM = 1.0, SUM = 1.0;
    int K = 1;

    *C = 1;

    do
    {
        TERM *= -X * X / ((2.0 * K - 1) * (2.0 * K));
        SUM += TERM;
        (*C)++;
        K++;
    }
    while (fabs(TERM) > 0.001);

    return SUM;
}

int main(void)
{
    double X, RES;
    int C;

    printf("Ingrese el valor de X en radianes: ");
    scanf("%lf", &X);

    RES = coseno(X, &C);

    printf("Coseno aproximado: %.6f\n", RES);
    printf("Numero de terminos: %d\n", C);

    return 0;
}
