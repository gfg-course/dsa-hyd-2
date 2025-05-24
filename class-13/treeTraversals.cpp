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
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// TC: O(n)
// AS: O(h)
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// TC: O(n)
// AS: O(h)
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// TC: O(n)
// AS: O(max nodes in any level)
vector<int> levelOrder(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<int> result;
    queue<Node*> q;
    
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();

        result.push_back(curr->data);
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    return result;
}

// TC: O(n)
// AS: O(max nodes in any level)
vector<vector<int>> levelOrderLevelByLevel(Node* root) {
    if (root == NULL) {
        return {};
    }

    vector<vector<int>> result;
    queue<Node*> q;
    
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> currLevel;
        for (int i = 0; i < sz; i++) {
            Node *curr = q.front();
            q.pop();

            currLevel.push_back(curr->data);
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        result.push_back(currLevel);
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

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;

    vector<int> res = levelOrder(root);
    vector<vector<int>> res2 = levelOrderLevelByLevel(root);

    for (int i : res) {
        cout << i << " ";
    }
    cout <<endl;
    for (auto i : res2) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout <<endl;
}