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

class LinkedList {
public:
    Node* head;

    // TC: O(1)
    void insertAtBeginning(int data) {

        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // TC: O(n)
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // TC: O(n)
    void insertAtEnd(int data) {
        if (head == NULL) {
            insertAtBeginning(data);
            return;
        }
        
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        Node* newNode = new Node(data);
        temp->next = newNode;
    }

    // TC: O(min(pos, n))
    void insertAtPos(int data, int pos) {
        if (pos <= 0 || head == NULL) {
            insertAtBeginning(data);
            return;
        }

        int hops = 0;
        Node* temp = head;
        while (hops < pos - 1 && temp->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // TC: O(1)
    void deleteFromBeginning() {
        if (head == NULL) {
            return;
        }

        Node* toDelete = head;
        head = head->next;
        delete(toDelete);
    }

    // TC: O(n)
    void deleteFromEnd() {
        if (head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = NULL;
        delete(toDelete);
    }

    // TC: O(min(pos, n))
    void deleteFromPos(int pos) {
        if (pos == 0 || head == NULL || head->next == NULL) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        int hops = 0;
        while (hops < pos - 1 && temp->next->next != NULL) {
            temp = temp->next;
            hops++;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete(toDelete);
    }

    // TC: O(n)
    void reverse() {

        Node* prev = NULL;
        Node* curr = head;

        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }
};

int main() {
    
    LinkedList* ll = new LinkedList();

    ll->insertAtBeginning(3);
    ll->insertAtBeginning(2);
    ll->insertAtBeginning(1);
 
    ll->print(); // 1 2 3

    ll->insertAtEnd(4);
    ll->insertAtEnd(6);

    ll->print(); // 1 2 3 4 6

    ll->insertAtPos(5, 4);
    ll->insertAtPos(0, 0);
    ll->insertAtPos(7, 100);

    ll->print(); // 0 1 2 3 4 5 6 7

    ll->deleteFromBeginning();
    ll->print(); // 1 2 3 4 5 6 7

    ll->deleteFromEnd();
    ll->print(); // 1 2 3 4 5 6

    ll->deleteFromPos(0); // 2 3 4 5 6
    ll->deleteFromPos(2); // 2 3 5 6
    ll->deleteFromPos(200); // 2 3 5

    ll->print();

    ll->reverse();
    ll->print(); // 5 3 2
}
