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

void insertAt(int idx, int val) {
    if (idx > ll->size) {
        printf("Index out of bounds!\n");
        return;
    }
    if (idx == 0) {
        prepend(val);
        return;
    }
    if (idx == ll->size) {
        append(val);
        return;
    }

    Node *nn = createNode(val);
    Node *runner = ll->head;
    ll->size++;

    for (int i = 0; i < idx; i++) {
        runner = runner->next;
    }

    nn->next = runner;
    nn->prev = runner->prev;
    runner->prev->next = nn;
    runner->prev = nn;
}

void removeAt(int idx) {
    if (idx >= ll->size) {
        printf("Index out of bounds!\n");
        return;
    }
    ll->size--;
    if (ll->size == 0) {
        ll->head = NULL;
        free(ll->tail);
        ll->tail = NULL;
        return;
    }
    if (idx == 0) {
        Node *nn = ll->head->next;
        nn->prev = NULL;
        free(ll->head);
        ll->head = nn;
        return;
    } else if (idx == ll->size) {
        Node *nn = ll->tail->prev;
        nn->next = NULL;
        free(ll->tail);
        ll->tail = nn;
        return;
    }

    Node *runner = ll->head;

    for (int i = 0; i < idx; i++) {
        runner = runner->next;
    }

    runner->prev->next = runner->next;
    runner->next->prev = runner->prev;
    free(runner);
}

int searcher(int val) {
    Node *runner = ll->head;
    int idx = 0;
    while (runner) {
        if (runner->val == val) {
            return idx;
        }
        runner = runner->next;
        idx++;
    }
    return -1;
}

int main() {
    printf("hey\n");
    ll = createLl();
    append(1);
    append(2);
    append(3);
    append(4);
    prepend(0);
    insertAt(1, 69);
    removeAt(9);
    printer();
    printf("\n");
    printf("%d\n", searcher(3));
    return 0;
}
