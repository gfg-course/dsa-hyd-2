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

Node* insertInBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }

    if (root->data == val) {
        return root;
    }

    if (val < root->data) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }

    return root;
}

// TC: O(n)
// AS: O(H)
bool isBstUtil(Node* root, int low, int high) {
    if (root == NULL) {
        return true;
    }

    return 
        (root->data >= low && root->data <= high) &&
        isBstUtil(root->left, low, root->data - 1) && 
        isBstUtil(root->right, root->data + 1, high);

}

bool isBst(Node* root) {
    return isBstUtil(root, -1e6, +1e6);
}

int main() {
    Node* root = NULL;
    root = insertInBST(root, 50);
    root = insertInBST(root, 30);
    root = insertInBST(root, 70);
    root = insertInBST(root, 25);
    root = insertInBST(root, 65);
    root = insertInBST(root, 80);

    cout << isBst(root) << endl;


    Node* root2 = NULL;
    root2 = insertInBST(root2, 50);
    root2 = insertInBST(root2, 40);
    root2 = insertInBST(root2, 70);
    root2 = insertInBST(root2, 80);
    root2->right->left = new Node(45);

    cout << isBst(root2) << endl;
}