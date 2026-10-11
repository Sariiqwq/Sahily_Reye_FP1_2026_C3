
#include <stdio.h>

int primo(int NUM)
{
    int I;

    if (NUM < 2)
        return 0;

    for (I = 2; I <= NUM / I; I++)
    {
        if (NUM % I == 0)
            return 0;
    }

    return 1;
}

int main(void)
{
    int NUM;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    if (primo(NUM))
        printf("%d es primo.\n", NUM);
    else
        printf("%d no es primo.\n", NUM);

    return 0;
}
