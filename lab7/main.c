
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char date[20];
    float temp;
    struct Node *prev, *next;
} Node;

Node* add(Node* head, char* date, float temp) {
    Node* n = malloc(sizeof(Node));
    strcpy(n->date, date);
    n->temp = temp;
    n->next = NULL;

    if (!head) {
        n->prev = NULL;
        return n;
    }

    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

Node* merge(Node* a, Node* b) {
    if (!a) return b;
    Node* t = a;
    while (t->next) t = t->next;
    t->next = b;
    if (b) b->prev = t;
    return a;
}

void minmax(Node* head) {
    float min = head->temp, max = head->temp;
    Node* t = head;
    while (t) {
        if (t->temp < min) min = t->temp;
        if (t->temp > max) max = t->temp;
        t = t->next;
    }
    printf("Min: %.2f Max: %.2f\n", min, max);
}

void freeList(Node* head){
    while(head){
        Node* t=head;
        head=head->next;
        free(t);
    }
}

int main(){
    Node* A=NULL;
    Node* B=NULL;

    A=add(A,"01-01",5.2);
    A=add(A,"02-01",3.1);

    B=add(B,"01-02",7.4);
    B=add(B,"02-02",6.8);

    Node* C=merge(A,B);

    minmax(C);

    freeList(C);
    return 0;
}
