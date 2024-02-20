#include <iostream>
using namespace std;

void err(string s) { throw new runtime_error(s); }

struct Node {
    int val;
    Node *next;
    Node *prev;
};

Node *createNode(int val) {
    Node *n = new Node();
    n->val = val;
    n->prev = n->next = nullptr;
    return n;
}

class LinkedList {
  private:
    Node *tail;
    Node *head;
    size_t size;

  public:
    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    bool isEmpty() { return !this->head && !this->tail; };

    void append(int val) {
        this->size++;
        Node *newNode = createNode(val);

        if (this->isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }

        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
    };
    void prepend(int val) {
        this->size++;
        Node *newNode = createNode(val);

        if (this->isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            return;
        }

        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    };

    void printList() {
        auto node = this->head;
        cout << "[";
        while (node) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << "]" << endl;
    }

    void insertAt(const int idx, const int val) {
        if (idx > this->size) {
            err("Index out of bounds!");
        }
        if (idx == 0) {
            prepend(val);
            return;
        } else if (idx == this->size) {
            append(val);
            return;
        }
        this->size++;
        Node *runner = this->head;
        Node *newNode = createNode(val);

        for (int i = 0; i < idx; i++) {
            runner = runner->next;
        }

        runner->prev->next = newNode;
        newNode->prev = runner->prev;
        runner->prev = newNode;
        newNode->next = runner;
    };
    void removeAt(const int idx) {
        if (idx >= this->size) {
            err("Index out of bounds!");
        }
        this->size--; // decremented the size here.
        if (this->size == 1) {
            this->head = nullptr;
            delete this->tail;
            this->tail = nullptr;
            return;
        }
        if (idx == 0) {
            Node *nextPtr = this->head->next;
            nextPtr->prev = nullptr;
            delete this->head;
            this->head = nextPtr;
            return;
        } else if (idx == this->size) { // (this->size - 1) here cause segmentation fault as we already decremented the this->size on line 101.
            cout << "This" << endl;
            Node *prevPtr = this->tail->prev;
            prevPtr->next = nullptr;
            delete this->tail;
            this->tail = prevPtr;
            return;
        }
        Node *runner = this->head;
        for (int i = 0; i < idx; i++) {
            runner = runner->next;
        }
        cout << "bottom" << endl;
        runner->prev->next = runner->next;
        runner->next->prev = runner->prev;
        delete runner;
    };
};

int main() {
    LinkedList ll;
    /* cout << ll.isEmpty() << endl; */
    ll.append(1);
    ll.prepend(81);
    ll.append(69);
    ll.insertAt(2, 420);
    ll.printList();
    ll.removeAt(2);
    ll.printList();
    return 0;
}
