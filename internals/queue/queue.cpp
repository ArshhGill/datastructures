#include "iostream"
using namespace std;

struct Node {
    Node *next;
    Node *prev;
    int val;
};

class Queue {
  private:
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *createNode(int val) {
        Node *uwu = new Node;
        uwu->val = val;
        uwu->next = uwu->prev = nullptr;
        return uwu;
    }

  public:
    void push(int val) {
        Node *uwu = this->createNode(val);
        if (!head){
            head = uwu;
            tail = uwu;
            return;
        }


    }

    void pop() {}

    Node *top() { return nullptr; }
};

int main() {
    cout << "uwu";
    return 0;
}
