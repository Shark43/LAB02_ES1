#include <stdio.h>

int gcdRecursive(int a, int b);
int isEven(int a);
void swapVar(int *a, int *b);
int gcdDijkstra(int a, int b);
int gcd(int a, int b);
int main( )
{
    int a = 0, b = 0;

    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);
    gcd(a, b);


    return 0;
}

int gcd(int a, int b) {
    int ka = a, kb = b;
    int risMyCode = gcdRecursive(a, b);
    printf("\n DIO %d, %d\n", a, b);
    int risDij = gcdDijkstra(ka, kb);

    if(risDij != risMyCode) {
        printf("Errore nel codice i due risultati sono diversi: %d - %d", risMyCode, risDij);
    } else if(risMyCode == 1) {
        printf("I 2 numeri sono primi tra loro");
    } else {
        printf("La gcd e' %d", risMyCode);
    }
}

int gcdRecursive(int a, int b) {
    if(a < b) {
        swapVar(&a, &b);
    }
    if(b == 0) {
        return a;
    }

    if(isEven(a) && isEven(b)) {
        return 2 * gcdRecursive(a / 2, b / 2);
    } else if(!isEven(a) && isEven(b) ) {
        return gcdRecursive(a, b / 2);
    } else if(!isEven(a) && !isEven(b)) {
        return gcdRecursive((a - b) / 2, b);
    } else if(isEven(a) && !isEven(b)) {
        return gcdRecursive(a / 2, b);
    }

    return gcdRecursive(b, 1);
}

int isEven(int a) {
    return a % 2 == 0;
}

void swapVar(int *a, int *b) {
    int aus;
    aus = *a;
    *a = *b;
    *b = aus;
}

int gcdDijkstra(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcdDijkstra(b, a % b);
}