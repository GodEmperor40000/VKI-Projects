#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Uzel {
    struct Versh* data;
    struct Uzel* next;
} *stack = NULL;

bool empty(struct Uzel* GV) {
    if(GV == NULL) return true;
    else return false;
}

struct Versh* top(struct Uzel *GV) {
    if(empty(GV)) return NULL;
    return GV->data;
}

struct Uzel* push(struct Versh* znach, struct Uzel* GV) {
    struct Uzel* SG = GV;
    GV = (struct Uzel*)malloc(sizeof(struct Uzel));
    if(empty(GV)) return NULL;

    GV->next = SG;
    GV->data = znach;
    return GV;
}

struct Uzel* pop(struct Uzel* GV) {
    struct Uzel* SG = GV;
    if(empty(GV)) return NULL;

    GV = GV->next;
    free(SG);
    return GV;
}

struct S {
    int name;
    struct Versh* link;
    struct S* next;
};

struct Versh {
    int name;
    int zavis;
    struct Versh* next;
    struct S* S1;
} *head = NULL, *last = NULL;

struct Versh* NV(int name) {
    for(struct Versh* x = head; x != NULL; x = x->next) if(x->name == name) return x;
    return NULL;
}

struct Versh* DV(int name) {
    struct Versh* x = (struct Versh*)malloc(sizeof(struct Versh));
    x->name = name;
    x->zavis = 0;
    x->next = NULL;
    x->S1 = NULL;

    if(head == NULL) head = x;
    if(last != NULL) last->next = x;
    last = x;
    return x;
}

void DS(struct Versh* a, struct Versh* b) {
    struct S* last_link = a->S1;
    if(last_link != NULL) {
        if(last_link->link == b) return;

        while(last_link->next != NULL) {
            if(last_link->link == b) return;
            last_link = last_link->next;
        }

        last_link->next = (struct S*)malloc(sizeof(struct S));
        last_link->next->link = b;
        last_link->next->name = b->name;

    }
    else {
        a->S1 = (struct S*)malloc(sizeof(struct S));
        a->S1->link = b;
        a->S1->name = b->name;
    }

    b->zavis++;
}

void Obrabotka(int VhodN, int Nazv1) {

    struct Versh* a = NV(VhodN);
    struct Versh* b = NV(Nazv1);
    if(a == NULL) a = DV(VhodN);
    if(b == NULL) b = DV(Nazv1);
    DS(a, b);

}

char step(struct Versh* x) {
    int zavis = x->zavis;
    if(x->zavis >= 0) {
        x->zavis = -1;

        for(struct S* Sx = x->S1; Sx != NULL; Sx = Sx->next) {
            if(step(Sx->link) != 0) return 1; //Return that there is a loop
        }

        x->zavis = -2;
        stack = push(x, stack);
    }
    else if(zavis == -1) return 1;
    return 0;
}

void sort() {
    for(struct Versh* x = head; x != NULL; x = x->next) {
        if(step(x) == 1) {

            puts("\nGraph contains a closed loop so cant been sorted");
            return;
        }
    }
    for(struct Versh* x = top(stack); x != NULL; x = top(stack)) {

        printf("%d ", x->name);
        stack = pop(stack);
        x->next = top(stack);
    }
}

void cleaner() {

    for(struct Versh* x = head, *Ox = x; x != NULL; Ox = x) {

        for (struct S* Sx = x->S1, *SS = Sx; Sx != NULL; SS = Sx) {
            Sx = Sx->next;
            free(SS);
        }

        x = x->next;
        free(Ox);
    }
}

bool end = false;
int a, b;
int a1;

int main() {
    while(!end) {
        a1 = scanf("%d %d", &a, &b);
        if(a1 == EOF || a1 != 2) {
            end = true;
            continue;
        }
        Obrabotka(a, b);
    }
    printf("\nGraph:");
    for(struct Versh* x = head; x != NULL; x = x->next) printf("%d ", x->name);
    printf("\n\nTopologically sorted graph:\n");
    sort();
    cleaner();
    printf("");
}
