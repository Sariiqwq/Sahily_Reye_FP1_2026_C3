
#include <stdio.h>
#include <math.h>

double inversion(double CAP, double TAS, int MES)
{
    return CAP * pow(1.0 + TAS / 100.0, MES);
}

int main(void)
{
    int MES;
    double CAP, TAS, RES;

    printf("Ingrese el capital inicial: ");
    scanf("%lf", &CAP);

    printf("Ingrese la tasa mensual en porcentaje: ");
    scanf("%lf", &TAS);

    printf("Ingrese el numero de meses: ");
    scanf("%d", &MES);

    if (CAP < 0 || TAS < 0 || MES < 0)
    {
        printf("Los datos no pueden ser negativos.\n");
        return 1;
    }

    RES = inversion(CAP, TAS, MES);

    printf("Monto final: %.2f\n", RES);

    return 0;
}
