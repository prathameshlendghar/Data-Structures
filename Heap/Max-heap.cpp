#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    vector<int> heap;
    public:

        MaxHeap(){};
        MaxHeap(vector<int> arr){
            heap = arr;
            heapify();
        }

        MaxHeap* push(int val){
            heap.push_back(val);
            heapify_up();
            return this;
        }
        void pop(){
            if(heap.empty()){
                cout<<"No Element in Heap"<<endl;
                return;
            }
            heap[0] = heap[heap.size()-1];
            heap.pop_back();
            heapify_down();
        }
        int top(){
            if(heap.empty()){
                cout<<"No Element in Heap"<<endl;
                return -1;
            }
            return heap[0];
        }


        void heapify_up() {
            int i = heap.size() - 1;
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (heap[i] > heap[parent]) {
                    swap(heap[i], heap[parent]);
                    i = parent;
                } else {
                    break;
                }
            }
        }

        void heapify_down() {
            int i = 0;
            int n = heap.size();
            while (true) {
                int LChild = 2 * i + 1;
                int RChild = 2 * i + 2;
                int largest = i;

                if (LChild < n && heap[LChild] > heap[largest])
                    largest = LChild;
                if (RChild < n && heap[RChild] > heap[largest])
                    largest = RChild;

                if (largest != i) {
                    swap(heap[i], heap[largest]);
                    i = largest;
                } else {
                    break;
                }
            }
        }

        void heapify_down(int i) {
            int n = heap.size();
            while (true) {
                int LChild = 2 * i + 1;
                int RChild = 2 * i + 2;
                int largest = i;

                if (LChild < n && heap[LChild] > heap[largest])
                    largest = LChild;
                if (RChild < n && heap[RChild] > heap[largest])
                    largest = RChild;

                if (largest != i) {
                    swap(heap[i], heap[largest]);
                    i = largest;
                } else {
                    break;
                }
            }
        }

        void heapify(){
            int n = (heap.size()-1)/2;
            for(int i = n; i>= 0; i--){
                heapify_down(i);
            }
        }

        void print(){
            while(!heap.empty()){
                cout<<this->top()<<" ";
                this->pop();
            }
            cout<<endl;
        }

};


int main(){
    MaxHeap *heap1 = new MaxHeap, *heap2 = new MaxHeap, *heap3 = new MaxHeap, *heap4 = new MaxHeap, *heap5 = new MaxHeap;
    heap1->push(1)->push(2)->push(3)->push(4)->push(5)->push(6)->push(7)->push(8)->push(9);
    heap2->push(5)->push(5)->push(3)->push(2)->push(1)->push(0);

    heap3->push(9)->push(2);

    heap4->push(10);

    heap5->push(101)->push(29)->push(500)->push(50)->push(98)->push(11)->push(43)->push(15)->push(11);
    
    heap1->print();
    heap2->print();
    heap3->print();
    heap4->print();
    heap5->print();

    MaxHeap heap6({1,2,3,4,5,6,7,8,9});
    heap6.print();

    MaxHeap heap7({5,5,3,2,1,0});
    heap7.print();

    MaxHeap heap8({9,2});
    heap8.print();

    MaxHeap heap9({101,29,500,50,98,11,43,15,11});
    heap9.print();
}