#include <stdio.h>
float promedio(int suma, int cantidad)
{
    if (cantidad == 0)
        return 0;
    return (float)suma / cantidad;
}

int main(void)
{
    int N, num, i;
    int sumaP = 0, sumaI = 0;
    int cantP = 0, cantI = 0;

    printf("Cantidad de numeros: ");
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            sumaP += num;
            cantP++;
        }
        else
        {
            sumaI += num;
            cantI++;
        }
    }

    if (cantP > 0)
        printf("Promedio de pares: %.2f\n",
               promedio(sumaP, cantP));
    else
        printf("No hay numeros pares.\n");

    if (cantI > 0)
        printf("Promedio de impares: %.2f\n",
               promedio(sumaI, cantI));
    else
        printf("No hay numeros impares.\n");

    return 0;
}
