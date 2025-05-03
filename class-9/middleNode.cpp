#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next; // reference/the address of the next node.

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// TC: O(n)
// AS: O(1)
int getMiddle(Node* head) {
    // TODO: Try to modify the solution in case the definition of middle
    // node in the even-length linked lists is the first out of the two
    // middle nodes.
    if (head == NULL) {
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

Node* isPalindromeUtil(Node* curr, Node* head, bool &result) {
    if (curr == NULL) {
        return head;
    }

    Node* toCompare = isPalindromeUtil(curr->next, head, result);

    if (curr->data != toCompare->data) {
        result = false;
    }

    return toCompare->next;
}

// TC: O(n)
// AS: O(n)
bool isPalindrome(Node* head) {
    bool result = true;
    isPalindromeUtil(head, head, result);
    return result;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(1);

    cout << isPalindrome(head) << endl;
}