#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *next;
};

void err(string s) { throw new runtime_error(s); }

Node *createNode(const int val) {
    Node *newNode = new Node;
    newNode->val = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

class linked_list {
  private:
    Node *head;
    Node *tail;
    int size;

  public:
    linked_list() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void printer() {
        Node *runner = this->head;
        while (runner) {
            cout << runner->val << " ";
            runner = runner->next;
        }
        cout << endl;
    }

    bool isEmpty() { return !this->head && !this->tail; }
    void appendNode(const int val) {
        this->size++;
        Node *newNode = createNode(val);
        if (this->size == 1) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }
        if (this->size == 2) {
            newNode->prev = this->head;
            this->head->next = newNode;
            this->tail = newNode;

            return;
        }
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }

    void prependNode(const int val) {
        this->size++;
        Node *newNode = createNode(val);
        if (this->size == 1) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }
        if (this->size == 2) {
            newNode->next = this->tail;
            this->tail->prev = newNode;
            this->head = newNode;

            return;
        }
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }

    void insertAt(const int idx, const int val) {
        if (idx > this->size) {
            err("index out of bounds.");
        }
        if (idx == 0) {
            this->prependNode(val);
            return;
        } else if (idx == this->size) {
            this->appendNode(val);
            return;
        }

        this->size++;
        Node *newNode = createNode(val);
        Node *runner = this->head;
        for (int i = 0; i < idx; i++) {
            runner = runner->next;
        }

        runner->prev->next = newNode;
        newNode->prev = runner->prev;
        runner->prev = newNode;
        newNode->next = runner;
    }
    void removeAt(const int idx) {
        if (idx > this->size) {
            err("index out of bounds.");
        }
        this->size--;
        if (this->size == 0) {
            delete this->head;
            this->tail = this->head = nullptr;
            return;
        }

        if (idx == 0) {
            Node *uwu = this->head;
            this->head = uwu->next;
            this->head->prev = nullptr;
            delete uwu;
            return;
        } else if (idx == this->size) {
            Node *uwu = this->tail;
            this->tail = uwu->prev;
            this->tail->next = nullptr;
            delete uwu;
            return;
        }

        Node *runner = this->head;
        for (int i = 0; i < idx; i++) {
            runner = runner->next;
        }
        runner->prev->next = runner->next;
        runner->next->prev = runner->prev;
        delete runner;
    }
};

int main() {
    auto *ll = new linked_list();
    ll->insertAt(0, 69);
    ll->appendNode(10);
    ll->appendNode(10);
    ll->appendNode(10);
    ll->appendNode(10);

    ll->printer();

    ll->prependNode(1);
    ll->prependNode(4);
    ll->printer();
    ll->removeAt(0);
    ll->printer();
    ll->removeAt(2);
    ll->printer();
    return 0;
}
