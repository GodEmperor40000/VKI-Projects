#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct Vershina {
    int x;
    struct Vershina* L;
    struct Vershina* R;
} *V = NULL;

struct Vershina* Dobavlenie(int a1, struct Vershina* der) {
    if(der == NULL) {
        der = (struct Vershina*)malloc(sizeof(struct Vershina));
        der->L = NULL;
        der->R = NULL;
        der->x = a1;
        printf("Dobavleno: %d\n", a1);
        return der;
    }
    int x = der->x;
    struct Vershina* L = der->L, *R = der->R;
    if(a1 > x) der->R = Dobavlenie(a1, R);
    else if(a1 < x) der->L = Dobavlenie(a1, L);
    return der;
}



struct Vershina* poisk(int a1, struct Vershina* der) {
    if(der == NULL) return NULL;
    int x = der->x;
    struct Vershina* L = der->L, *R = der->R;
    if(a1 == x) return der;
    else if(a1 > x) return(poisk(a1, R));
    else if(a1 < x) return(poisk(a1, L));
}

void InfObh(struct Vershina* der) {
    if(der == NULL) return;
    int x = der->x;
    struct Vershina* L = der->L, *R = der->R;
    InfObh(L);
    printf("%d ", x);
    InfObh(R);
}


void Oper(char znak, int a1) {

    if(znak == '1'){

        if(V == NULL) V = Dobavlenie(a1, V);
        else Dobavlenie(a1, V);

    }
    if(znak == '2'){

        if(poisk(a1, V) == NULL) puts("Element ne sushestvuet");
        else puts("Element sushestvuet");

    }
    if(znak == '3'){
        InfObh(V);
        puts("");
    }
}



char znak, a[10];
int a1;

int main() {
   bool A = true, OB = true;
   int a2;
   printf("Viberete operatsiu: \n 1 - dobavlenie \n 2 - poisk \n 3 - infiksnii obhod \n lubaia bukva - dlia vihoda iz rezimov vvedenia/ poiska/ inf obhoda \n: ");
    while(A) {
        OB = true;
        znak = getc(stdin);
        fgets(a, 10, stdin);
        if(znak != '1' && znak != '2' && znak != '3'){
                A = false;
                continue;
        }

        if(znak == '3'){
            printf("Resultat infiksogo obhoda:");
            Oper(znak, 0);
        }

        while(OB) {
            a2 = scanf("%d", &a1);
            if(a2 == "end" || a2 != 1) {
                fgets(a, 10, stdin);
                OB = false;
                continue;
            }

            Oper(znak, a1);
        }
    }

}
