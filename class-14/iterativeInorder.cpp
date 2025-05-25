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

void pushLeft(Node* root, stack<Node*> &s) {
    while (root != NULL) {
        s.push(root);
        root = root->left;
    }
}

// TC: O(n)
// AS: O(h)
vector<int> iterativeInorder(Node* root) {

    stack<Node*> s;
    pushLeft(root, s);

    vector<int> result;

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        result.push_back(current->data);

        pushLeft(current->right, s);
    }

    return result;
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

    vector<int> res = iterativeInorder(root);
    for (int i  : res) {
        cout << i << " ";
    }
}