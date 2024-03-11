#include "iostream"
using namespace std;

void err(string s) { throw new runtime_error(s); }

struct Node {
    int val;
    Node *next;
};

class Stack {
  public:
    Node *top;

    void push(int val) {
        Node *newNode = createNode(val);
        if (!top) {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (!top) {
            err("removing from empty stack");
        }
        if (!top->next) {
            int val = top->val;
            delete top;
            top = nullptr;
            return val;
        }
        Node *uwu = top;
        int val = top->val;
        top = top->next;
        delete uwu;
        return val;
    }

    int topVal() { return !top ? -1 : top->val; }

    void uwuPrinter() {
        Node *runner = top;
        while (runner) {
            cout << runner->val << "\n";
            runner = runner->next;
        }
    }

  private:
    Node *createNode(int val) {
        Node *newNode = new Node();
        newNode->val = val;
        return newNode;
    }
};

int main() {
    Stack ss;
    cout << ss.topVal() << "\n";
    ss.push(2);
    ss.push(5);
    ss.push(11);
    cout << ss.topVal() << "\n";
    ss.pop();
    cout << ss.topVal() << "\n";
    ss.push(32);
    ss.push(0);
    ss.uwuPrinter();
    cout << "uwu\n";
    return 0;
}
