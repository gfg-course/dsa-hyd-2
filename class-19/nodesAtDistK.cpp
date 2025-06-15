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

void getPathUtil(Node* root, int val, vector<Node*> &currPath, vector<Node*> &result) {
    if (root == NULL || result.size() > 0) {
        return;
    }

    currPath.push_back(root);
    if (root->data == val) {
        result = currPath;
        return;
    }

    getPathUtil(root->left, val, currPath, result);
    getPathUtil(root->right, val, currPath, result);

    currPath.pop_back();
}

vector<Node*> getPath(Node* root, int val) {
    vector<Node*> currPath, result;

    getPathUtil(root, val, currPath, result);
    return result;
}

void getNodesAtDistKBelow(Node* root, int k, vector<int> &result) {
    if (root == NULL || k < 0) {
        return;
    }
    if (k == 0) {
        result.push_back(root->data);
        return;
    }

    getNodesAtDistKBelow(root->left, k - 1, result);
    getNodesAtDistKBelow(root->right, k - 1, result);
}

vector<int> nodesAtDistK(Node* root, Node* target, int k) {

    vector<Node*> path = getPath(root, target->data);
    int n = path.size();

    vector<int> result;

    if (n - k - 1 >= 0) {
        result.push_back(path[n - k - 1]->data);
    }

    getNodesAtDistKBelow(path[n - 1], k, result);
    k--;

    for (int i = n - 2; i >= 0; i--) {
        if (path[i + 1] == path[i]->right) {
            getNodesAtDistKBelow(path[i]->left, k - 1, result);
        } else {
            getNodesAtDistKBelow(path[i]->right, k - 1, result);
        }
        k--;
    }

    return result;
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = nodesAtDistK(root, root->right, 1);
    for (int i : res) {
        cout << i << " ";
    }
}