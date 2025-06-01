#include<bits/stdc++.h>
using namespace std;

// Max heap

// TC: O(log(n))
// AS: O(log(n))
void topDownHeapify(vector<int> &heap, int index) {

    int leftChildIndex = 2*index + 1;
    int rightChildIndex = 2*index + 2;

    int maxValueIndex = index;
    if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = leftChildIndex;
    }
    if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[maxValueIndex]) {
        maxValueIndex = rightChildIndex;
    }

    if (maxValueIndex != index) {
        swap(heap[index], heap[maxValueIndex]);
        topDownHeapify(heap, maxValueIndex);
    }
}

// TC: O(log(n))
// AS: O(log(n))
void deleteFromHeap(vector<int> &heap) {
    if (heap.size() == 0) {
        return;
    }
    int n = heap.size();

    // Step-1: Replace the root with the last node & delete the last node.
    heap[0] = heap[n - 1];
    heap.pop_back();

    // Step-2: Top-down heapify from the root.
    topDownHeapify(heap, 0);
}

// TC: O(log(n))
// AS: O(log(n))
void bottomUpHeapify(vector<int> &heap, int index) {
    if (index == 0) {
        return;
    }

    int parentIndex = (index - 1) / 2;
    if (heap[index] > heap[parentIndex]) {
        swap(heap[index], heap[parentIndex]);
        bottomUpHeapify(heap, parentIndex);
    }
}

// TC: O(log(n))
// AS: O(log(n))
void insertInHeap(vector<int> &heap, int val) {
    
    // Step-1: Insert at the end
    heap.push_back(val);

    // Step-2: bottom-up heapify from the last node
    bottomUpHeapify(heap, heap.size() - 1);
}

int main() {
    vector<int> heap = {100, 40, 50, 10, 15, 50, 40};
    deleteFromHeap(heap);

    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    insertInHeap(heap, 100);
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;

    insertInHeap(heap, 70);
    for (int i : heap) {
        cout << i << " ";
    }
}