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

int height(Node* root, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return 0;
    }

    // If the height of the root is already computed.
    if (heights.find(root) != heights.end()) {
        return heights[root];
    }

    int lh = height(root->left, heights);
    int rh = height(root->right, heights);

    return heights[root] = 1 + max(lh, rh);
}

void diameterUtil(Node* root, int &result, unordered_map<Node*, int> &heights) {
    if (root == NULL) {
        return;
    }

    int lh = height(root->left, heights);
    int rh = height(root->right, heights);

    result = max(result, lh + rh);

    diameterUtil(root->left, result, heights);
    diameterUtil(root->right, result, heights);
}

// TC: O(n)
// AS: ??
int diameter(Node* root) {
    
    unordered_map<Node*, int> heights;
    int result = 0;
    diameterUtil(root, result, heights);
    return result;
}

int getHeightAndMaintainDiameter(Node* root, int &diam) {
    if (root == NULL) {
        return 0;
    }

    int lh = getHeightAndMaintainDiameter(root->left, diam);
    int rh = getHeightAndMaintainDiameter(root->right, diam);

    diam = max(diam, lh + rh);

    return 1 + max(lh, rh);
}

// TC: O(n)
// AS: O(h)
int diameterUsingHeightFunc(Node* root) {
    int diam = 0;
    getHeightAndMaintainDiameter(root, diam);
    return diam;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);

    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    cout << diameter(root) << endl;
    cout << diameterUsingHeightFunc(root) << endl;
}