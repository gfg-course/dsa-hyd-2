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

Node* constructTreeUtil(vector<int> &inorder, int start, int end, 
                        vector<int> &postorder, int &postIndex) {

    if (start > end) {
        return NULL;
    }

    Node* root = new Node(postorder[postIndex]);
    postIndex--;

    int inIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    root->right = constructTreeUtil(inorder, inIndex + 1, end, postorder, postIndex);
    root->left = constructTreeUtil(inorder, start, inIndex - 1, postorder, postIndex);

    return root;
}

// TC: O(n^2)
// AS: O(h)
Node* constructTreeUsingPostAndInorder(vector<int> inorder, vector<int> postorder) {
    int postIndex = postorder.size() - 1;
    return constructTreeUtil(inorder, 0, inorder.size() - 1, postorder, postIndex);
}

int main() {
    Node* root = constructTreeUsingPostAndInorder({4, 8, 2, 5, 1, 6, 3, 7},
                                                  {8, 4, 5, 2, 6, 7, 3, 1});

    inOrder(root);
    cout << endl;
    postOrder(root);
}