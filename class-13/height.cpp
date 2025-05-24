#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// TC: O(n)
// AS: O(h)
int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->left->left = new Node(7);
    root->left->right = new Node(5);
    root->left->right->right = new Node(8);
    root->right = new Node(3);
    root->right->right = new Node(6);

    cout << height(root) << endl;
}