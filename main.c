#include <stdio.h>

int gcd(int a, int b);
int isEven(int a);
void swapVar(int *a, int *b);
int gcdDijkstra(int a, int b);
int main( )
{
    int a = 314159, b = 271828;

    int risMyCode = gcd(a, b);
    int risDij = gcdDijkstra(a, b);
    if(risDij != risMyCode) {
        printf("Errore nel codice i due risultati sono diversi: %d - %d", risMyCode, risDij);
    } else if(risMyCode == 0) {
        printf("I 2 numeri sono primi tra loro");
    } else {
        printf("La gcd è %d", risMyCode);
    }


    return 0;
}

int gcd(int a, int b) {
    if(a < b) {
        swapVar(&a, &b);
    }
    if(b == 1) {
        return a;
    }
    if(a == b) {
        return a;
    } else if(isEven(a) && isEven(b)) {
        return 2* gcd(a/2,b/2);
    } else if(!isEven(a) && isEven(b)) {
        return gcd(a, b/2);
    } else if(!isEven(a) && !isEven(b)) {
        return gcd( (a-2)/2 , b);
    } else {
        return 0;
    }


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
    return gcd(b, a % b);
}