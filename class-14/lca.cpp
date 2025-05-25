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

void getPathUtil(Node* root, int val, vector<int> &currPath, vector<int> &result) {
    if (root == NULL || result.size() > 0) {
        return;
    }

    currPath.push_back(root->data);
    if (root->data == val) {
        result = currPath;
        return;
    }

    getPathUtil(root->left, val, currPath, result);
    getPathUtil(root->right, val, currPath, result);

    currPath.pop_back();
}

vector<int> getPath(Node* root, int val) {
    vector<int> currPath, result;

    getPathUtil(root, val, currPath, result);
    return result;
}

// TC: O(n)
// AS: O(h)
int lca(Node* root, int n1, int n2) {

    vector<int> path1 = getPath(root, n1);
    vector<int> path2 = getPath(root, n2);

    int result = path1[0];
    int i = 1;
    while (i < path1.size() && i < path2.size()) {
        if (path1[i] != path2[i]) {
            break;
        }
        result = path1[i];
        i++;
    }

    return result;
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
}