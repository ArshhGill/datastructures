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
    Node *createNode(int val) {
        Node *uwu = new Node;
        uwu->val = val;
        uwu->next = uwu->prev = nullptr;
        return uwu;
    }

  public:
    void push(int val) {}

    void pop() {}

    Node *top() { return nullptr; }
};

int main() {
    cout << "uwu";
    return 0;
}
