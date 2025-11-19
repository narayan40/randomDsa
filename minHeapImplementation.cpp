#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
public:
    vector<int> heap;

    int getLeftChildIndex(int i)
    {
        return (i * 2) + 1;
    }
    int getRightChildIndex(int i)
    {
        return (i * 2) + 2;
    }
    int getParentIndex(int i)
    {
        return (i - 1) / 2;
    }
    void insertVal(int val)
    {
        heap.push_back(val);
        heapify(heap.size() - 1);
    }
    void heapify(int i)
    {
        while (i > 0)
        {
            int parentIndex = getParentIndex(i);
            if (heap[parentIndex] > heap[i])
            {
                swap(heap[parentIndex], heap[i]);
                i = parentIndex;
            }
            else{
                break;
            }
        }
       
    }
    void printHeap(){
        for(auto i:heap){
            cout<<i<<" ";
        }cout<<endl;
    }
};
int main()
{
    MinHeap heap;
    heap.insertVal(5);
    heap.insertVal(20);
    heap.insertVal(4);
    heap.insertVal(10);
    heap.insertVal(1);
    heap.insertVal(0);
    heap.printHeap();
    return 0;
}
