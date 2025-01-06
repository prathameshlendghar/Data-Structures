#include<iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int capacity;
        int start;
        int end;
        int siz;
    public:
        Queue();
        Queue(int);
        void pop();
        int front();
        void push(int);
        int size();

};

Queue::Queue(){
    this->siz=0;
    this->start = -1;
    this->end = -1;
    this->capacity = 5;
    this->arr = new int[this->capacity];
}
Queue::Queue(int siz){
    this->siz = 0;
    this->start = -1;
    this->end = -1;
    this->capacity = siz;
    this->arr = new int[this->capacity];
}

int Queue::size(){
    return this->siz;
}

void Queue::push(int ele){
    if(this->siz == this->capacity){
        cout<<"Queue full"<<endl;
        return;
    }
    if(this->siz == 0){
        this->start++;
    }
    this->end++;
    int end = this->end%this->capacity;
    if(this->end/this->capacity > 0)this->end = end;

    this->arr[end] = ele;
    this->siz++;
}
void Queue::pop(){
    if(this->siz == 0){
        cout<<"Queue Empty"<<endl;
        return;
    }
    if(this->siz == 1){
        this->start = -1;
        this->end = -1;
    }
    else{
        this->start++;
        int start = this->start%this->capacity;
        if(this->start/this->capacity > 0)
            this->start = start;
    }
    this->siz--;
}
int Queue::front(){
    if(this->siz == 0){
        cout<<"Queue Empty"<<endl;
        return -1;
    }
    return arr[this->start];
}

// int main(){
//     Queue Q(15);
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;
//     Q.push(1);
//     Q.push(2);
//     Q.push(3);
//     Q.push(4);
//     Q.push(5);
//     Q.push(6);
//     Q.push(7);
//     Q.push(8);
//     Q.push(9);
//     Q.push(10);
    
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;

//     Q.push(11);
//     Q.push(12);
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;

//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     Q.pop();
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;
//     Q.push(99);
//     Q.push(100);
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;
//     Q.pop();
//     cout<<Q.front()<<endl;
//     cout<<Q.size()<<endl;

// }