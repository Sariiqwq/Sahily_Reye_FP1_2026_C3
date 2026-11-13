/* PS8.1 - Banco: depositos y retiros sobre un arreglo de clientes
   ordenado por numero de cuenta (busqueda binaria). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void leer_cadena(const char *msg, char *dest, size_t n)
{
    printf("%s", msg);
    if (!fgets(dest, (int)n, stdin)) {      /* fin de la entrada */
        printf("\nFin de la entrada.\n");
        exit(0);
    }
    dest[strcspn(dest, "\n")] = '\0';
}

static long long leer_entero(const char *msg)
{
    char buf[64];
    long long v;
    for (;;) {
        leer_cadena(msg, buf, sizeof buf);
        if (sscanf(buf, "%lld", &v) == 1) return v;
        printf("Valor invalido, intenta de nuevo.\n");
    }
}

static double leer_real(const char *msg)
{
    char buf[64];
    double v;
    for (;;) {
        leer_cadena(msg, buf, sizeof buf);
        if (sscanf(buf, "%lf", &v) == 1) return v;
        printf("Valor invalido, intenta de nuevo.\n");
    }
}
#define MAX 100

typedef struct {
    char calle[40], cp[10], colonia[30], ciudad[30], tel[20];
} Domicilio;

typedef struct {
    long long cuenta;
    char nombre[40];
    Domicilio dom;
    double saldo;
} Cliente;

static int cmp(const void *a, const void *b)
{
    long long x = ((const Cliente *)a)->cuenta, y = ((const Cliente *)b)->cuenta;
    return (x > y) - (x < y);
}

static int buscar(Cliente c[], int n, long long cuenta)
{
    int ini = 0, fin = n - 1;
    while (ini <= fin) {
        int med = (ini + fin) / 2;
        if (c[med].cuenta == cuenta) return med;
        if (c[med].cuenta < cuenta) ini = med + 1; else fin = med - 1;
    }
    return -1;
}

int main(void)
{
    Cliente CLI[MAX];
    int n, i;

    do n = (int)leer_entero("Numero de clientes (1-100): ");
    while (n < 1 || n > MAX);

    for (i = 0; i < n; i++) {
        printf("\n--- Cliente %d ---\n", i + 1);
        CLI[i].cuenta = leer_entero("Numero de cuenta: ");
        leer_cadena("Nombre: ", CLI[i].nombre, sizeof CLI[i].nombre);
        leer_cadena("Calle y numero: ", CLI[i].dom.calle, sizeof CLI[i].dom.calle);
        leer_cadena("Codigo postal: ", CLI[i].dom.cp, sizeof CLI[i].dom.cp);
        leer_cadena("Colonia: ", CLI[i].dom.colonia, sizeof CLI[i].dom.colonia);
        leer_cadena("Ciudad: ", CLI[i].dom.ciudad, sizeof CLI[i].dom.ciudad);
        leer_cadena("Telefono: ", CLI[i].dom.tel, sizeof CLI[i].dom.tel);
        CLI[i].saldo = leer_real("Saldo: ");
    }
    qsort(CLI, n, sizeof(Cliente), cmp);   /* garantiza el orden por cuenta */

    for (;;) {
        char op[8];
        long long cuenta = leer_entero("\nNumero de cuenta (0 para terminar): ");
        int pos;
        double monto;
        if (cuenta == 0) break;
        pos = buscar(CLI, n, cuenta);
        if (pos < 0) { printf("La cuenta no existe.\n"); continue; }

        leer_cadena("Operacion (D = deposito, R = retiro): ", op, sizeof op);
        monto = leer_real("Monto: ");
        if (monto <= 0) { printf("El monto debe ser positivo.\n"); continue; }

        if (op[0] == 'D' || op[0] == 'd') {
            CLI[pos].saldo += monto;
            printf("Deposito realizado. Saldo: %.2f\n", CLI[pos].saldo);
        } else if (op[0] == 'R' || op[0] == 'r') {
            if (CLI[pos].saldo < monto)
                printf("Saldo insuficiente (%.2f). Operacion rechazada.\n", CLI[pos].saldo);
            else {
                CLI[pos].saldo -= monto;
                printf("Retiro autorizado. Saldo: %.2f\n", CLI[pos].saldo);
            }
        } else printf("Operacion no valida.\n");
    }
    return 0;
}
