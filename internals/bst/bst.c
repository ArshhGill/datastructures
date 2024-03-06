#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int val;
    Node *left;
    Node *right;
};

Node *createNode(int val) {
    Node *uwu = malloc(sizeof(Node));
    uwu->val = val;
    uwu->left = uwu->right = NULL;
    return uwu;
}

void inorder(Node *root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    printf("%d\n", root->val);
    inorder(root->right);
}

Node *destroyer(Node *root, int val) {
    if (!root) {
        return NULL;
    } else if (root->val > val) {
        root->left = destroyer(root->left, val);
    } else if (root->val < val) {
        root->right = destroyer(root->right, val);
    } else {
        if (!root->left && !root->right) {

        } else if (!root->right) {

        } else if (!root->left) {

        } else {
        }
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (!root) {
        return createNode(val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    } else if (val <= root->val) {
        root->left = insert(root->left, val);
    }

    return root;
}

int main() {
    Node *root = insert(NULL, 1);
    insert(root, 2);
    insert(root, 6);
    insert(root, 16);
    insert(root, 32);

    printf("uwu\n");

    inorder(root);

    return 0;
}
