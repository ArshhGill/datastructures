#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node *next;
    Node *prev;
    int val;
};

typedef struct {
    int size;
    Node *head;
    Node *tail;
} linkedList;

linkedList *ll;

Node *createNode(int val) {
    Node *uwu = malloc(sizeof(Node));
    uwu->val = val;
    uwu->next = NULL;
    uwu->prev = NULL;
    return uwu;
}

linkedList *createLl() {
    linkedList *uwu = malloc(sizeof(linkedList));
    uwu->size = 0;
    uwu->head = uwu->tail = NULL;
    return uwu;
}

bool isEmpty() { return ll->size <= 0; }

void printer() {
    Node *runner = ll->head;
    while (runner) {
        printf("%d\n", runner->val);
        runner = runner->next;
    }
}

void append(int val) {
    ll->size++;
    Node *nn = createNode(val);
    if (ll->size == 1) {
        ll->head = ll->tail = nn;
        return;
    }
    if (ll->size == 2) {
        nn->prev = ll->tail;
        ll->tail->next = nn;
        ll->tail = nn;
        return;
    }
    ll->tail->next = nn;
    nn->prev = ll->tail;
    ll->tail = nn;
}

void prepend(int val) {
    Node *nn = createNode(val);
    ll->size++;
    if (ll->size == 1) {
        ll->head = ll->tail = nn;
        return;
    }
    if (ll->size == 2) {
        nn->next = ll->head;
        ll->head->prev = nn;
        ll->head = nn;
        return;
    }
    ll->head->prev = nn;
    nn->next = ll->head;
    ll->head = nn;
}

int main() {
    printf("hey\n");
    ll = createLl();
    printer();
    printf("\n");
    append(1);
    append(6);
    prepend(69);
    printer();
    return 0;
}
