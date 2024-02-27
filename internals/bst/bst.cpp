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

void postorder(Node *root) { // orders you post
    if (!root) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << endl;
}

void preorder(Node *root) { // orders you pre
    if (!root) {
        return;
    }

    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) { // orders you in
    if (!root) {
        return;
    }

    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

bool searcher(Node *root, int val) { // searches you
    if (!root) {
        return false;
    }

    if (root->val == val) {
        return true;
    } else if (val < root->val) {
        return searcher(root->left, val);
    } else {
        return searcher(root->right, val);
    }
}

Node *findMax(Node *root) {
    if (!root) {
        return root;
    }
    if (root->right) {
        return findMax(root->right);
    } else {
        return root;
    }
}

Node *destroyer(Node *root, int val) { // destroys you

    if (!root) {
        return nullptr;
    }
    if (val < root->val) {
        root->left = destroyer(root->left, val);
    } else if (val > root->val) {
        root->right = destroyer(root->right, val);
    } else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        } else if (!root->right && root->left) {
            auto uwu = root;
            root = root->left;
            delete uwu;
        } else if (root->right && !root->left) {
            auto uwu = root;
            root = root->right;
            delete uwu;
        } else {
            auto uwu = findMax(root->left);
            root->val = uwu->val;
            root->left = destroyer(uwu, uwu->val);
            uwu = nullptr;
        }
    }
    return root;
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
    root = destroyer(root, 5);

    inorder(root);

    return 0;
}
