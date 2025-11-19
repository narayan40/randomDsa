#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> heap;

    MinHeap() {
        heap = {5, 10, 20, 30};
    }

    int getLeftChildIndex(int i) { return (2 * i) + 1; }
    int getRightChildIndex(int i) { return (2 * i) + 2; }
    int getParentIndex(int i) { return (i - 1) / 2; }

    void insert(int val) {
        heap.push_back(val);
        int lastIndex = heap.size() - 1;
        heapifyUp(lastIndex);
    }

    void heapifyUp(int i) {
        while (i > 0) {
            int parentIndex = getParentIndex(i);
            if (heap[i] < heap[parentIndex]) {
                swap(heap[i], heap[parentIndex]);
                i = parentIndex;
            } else break;
        }
    }

    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(1);
    heap.printHeap(); 
}
