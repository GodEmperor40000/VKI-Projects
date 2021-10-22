#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};
struct list *head=NULL;
struct list  *p, *t, *l;

void searching(struct list* head)
{
    struct list* p, * t;
    printf("Enter the element for searching: ");

    int nomer;
    scanf("%d", &nomer);
    p = head;
    int pos=1;
    if (head == NULL)
    printf ("List does not exist");

    else {
        while (p->data != nomer) {
            p = p->next;
            if (p == NULL) {
            printf("Element does not exist in the list");
            return;
            }
            else pos++;
            }
        printf("Your element is in %d position", pos);
    }
}

struct list* Addition(struct list *head) {
struct list* p, *t, *k, *r;

    if (head == NULL)
       printf("List does not exist\n");
    else {
    printf("Enter the new element: ");
    int nomer;
    scanf("%d", &nomer);
    k = head;
    r = head;

    while(r != NULL){
        if(r->data != nomer){
        r=r->next;
    }
        else{
            printf("this element is already exist");
            return head;
        }
    }

    r = head;

    p = (struct list*)malloc(sizeof(struct list));
    int max = 0;

    while (r != NULL) {
        if (max < r->data)
            max = r->data;
        r = r->next;
    }

    r = head;
    int F;
    while (r != NULL) {
        if (r->data > nomer) {
            F = r->data;
            break;
        }
        r = r->next;
    }

    if (nomer < k->data) {
        p->data = nomer;
        p->next = head;
        head = p;
    }
    if ((nomer < max) && (nomer > k->data)) {
        p->data = nomer;
        t = head;
        while (t->next->data != F)
            t = t->next;
        p->next = t->next;
        t->next = p;
    }

    if (nomer > max) {
        p->data = nomer;
        p->next = NULL;
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }



    return head;
    }
}


struct list* Delition(struct list* head) {

    if(head == NULL) printf("No list, create new list");
    else{
    printf("Enter the item for deliting: ");
    int x;
    scanf("%d", &x);
    t = head;
    p = head;

    if (x == p->data) {
        head = p->next;
        free(p);
        return head;
    }

    while ((t->next->data != x) && (t->data != x)){
        t = t->next;
        if(t->next == NULL){
            printf("This element does not exist");
            return head;
        }
    }
    p = t->next;
    l = p->next;
    free(p);
    t->next = l;

    }

return head;

}

struct list* Creation(struct list *head){

int x=0;
struct list *p = (struct list*) malloc( sizeof( struct list ) );

    if(head !=NULL) {printf("List already exist");}

    else{
        printf("Enter 1 item value: ");
        scanf("%d", &x);
        p->data=x;
        p->next = NULL;
        head = p;
    }

 return head;
}

void Pr(struct list *head){

p=head;
if(p==NULL) printf("No list, create new list\n");

else{while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
        }
    }
}

int main()
{
    int G=0;

    while(G != 6){
    printf("\n\n=========Menu========\n\n");

    printf("1. Create list\n");
    printf("2. add list item\n");
    printf("3. delete list item\n");
    printf("4. Find list item\n");
    printf("5. Print all list items\n");
    printf("6. Exit\n");
    printf("Choose action: ");

    scanf("%d", &G);
    if(G==1) head = Creation(head);
    if(G==2) head = Addition(head);
    if(G==3) head = Delition(head);
    if(G==4) searching(head);
    if(G==5) {Pr(head);}
    if(G==6) return 0;
    }


    return 0;
}
