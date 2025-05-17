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

// TC: O(n*k) where k is the number of time we circle through the looped part.
// AS: O(1)
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void printLinkedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// TC: O(n*k) where k is the number of time we circle through the looped part.
// AS: O(1)
void detectAndRemoveCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (slow != fast) {
        return;
    }

    // Circular Linked List when meeting point is head.
    if (slow == head) {
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }

    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

int main() {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    detectAndRemoveCycle(n1);
    printLinkedList(n1);

    Node* n11 = new Node(1);
    Node* n21 = new Node(2);
    Node* n31 = new Node(3);
    Node* n41 = new Node(4);

    n11->next = n21;
    n21->next = n31;
    n31->next = n41;
    n41->next = n11;

    detectAndRemoveCycle(n11);
    printLinkedList(n11);
}