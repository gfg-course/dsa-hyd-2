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

// TC: O(h)
// AS: O(h)
bool searchInBST(Node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (root->data == target) {
        return true;
    }
    if (target < root->data) {
        return searchInBST(root->left, target);
    }
    return searchInBST(root->right, target);
}

// TC: O(h)
// AS: O(1)
bool searchInBSTIterative(Node* root, int target) {

    while (root != NULL) {
        if (root->data == target) {
            return true;
        }

        if (target < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return false;
}

// TC: O(h)
// AS: O(h)
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

int getMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// TC: O(H)
// AS: O(H)
Node* deleteFromBst(Node* root, int val) {
    if (root == NULL) {
        return root;
    }

    if (val < root->data) {
        root->left = deleteFromBst(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBst(root->right, val);
    } else {
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }
        int inorderSucc = getMin(root->right);
        root->data = inorderSucc;
        root->right = deleteFromBst(root->right, inorderSucc);

        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // }
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // // Case-1: 0 child nodes.
        // if (childCount == 0) {
        //     return NULL;
        // }
        // // Case-2: 1 child node.
        // else if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     } else {
        //         return root->right;
        //     }
        // } 
        // // Case-3: 2 child nodes.
        // else {
        //     int inorderSucc = getMin(root->right);
        //     root->data = inorderSucc;
        //     root->right = deleteFromBst(root->right, inorderSucc);
        // }
    }

    return root;
}

int main() {
    
    Node* root = NULL;
    root = insertInBST(root, 7);
    root = insertInBST(root, 3);
    root = insertInBST(root, 15);
    root = insertInBST(root, 2);
    root = insertInBST(root, 10);
    root = insertInBST(root, 20);
    root = insertInBST(root, 19);
    root = insertInBST(root, 25);

    cout << searchInBST(root, 18) << endl;
    cout << searchInBST(root, 19) << endl;
    cout << searchInBST(root, 25) << endl;
    cout << searchInBST(root, 2) << endl;
}