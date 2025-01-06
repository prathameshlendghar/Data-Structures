#include "../stack/stack-for-queue.h"
#include<iostream>
using namespace std;


class Queue{
    private:
        stack* st1;
        stack* st2;
    public:
        Queue();
        void push(int);
        void pop();
        int front();
        int size();
};

Queue::Queue(){
    this->st1 = new stack;
    this->st2 = new stack;
}

void Queue::push(int ele){
    while(this->st1->size()>0){
        int top = this->st1->top();
        this->st2->push(top);
        this->st1->pop();
    }
    this->st1->push(ele);
    while(this->st2->size() > 0){
        int top = this->st2->top();
        this->st1->push(top);
        this->st2->pop();
    }
}

int Queue::size(){
    return this->st1->size();
}

void Queue::pop(){
    if(this->st1->size() == 0){
        cout<<"Queue Empty"<<endl;
        return;
    }
    this->st1->pop();
}

int Queue::front(){
    if(this->st1->size() == 0){
        cout<<"Queue Empty"<<endl;
        return -1;
    }
    return this->st1->top();
}

int main(){
    Queue Q;
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    Q.push(6);
    Q.push(7);
    Q.push(8);
    Q.push(9);
    Q.push(10);
    
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;

    Q.push(11);
    Q.push(12);
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;

    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    Q.pop();
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;
    Q.push(99);
    Q.push(100);
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;
    Q.pop();
    cout<<Q.front()<<endl;
    cout<<Q.size()<<endl;

}