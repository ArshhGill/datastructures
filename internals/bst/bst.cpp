#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node *createNode(const int val) {
    Node *newNode = new Node();
    newNode->val = val;
    newNode->left = newNode->right = nullptr;

    return newNode;
}

Node *insertNode(Node *root, const int val) {
    if (!root) {
        root = createNode(val);
        return root;
    }
    if (val <= root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

void inorder(Node *root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

// get val, insert, delete, search, findMin, findMax, findHeight,
// levelordertraversal, preOrder, inOrder, postOrder

int main() {
    auto root = insertNode(nullptr, 5);
    root = insertNode(root, 7);
    root = insertNode(root, 8);
    root = insertNode(root, 0);
    root = insertNode(root, 69);

    inorder(root);

    return 0;
}
