#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node(){
        data = -1;
        next = nullptr;
    }
};

class Queue{
    private:
        node* fron;
        node* bac;
        int siz;
    public:
        Queue();
        int front();
        void push(int);
        void pop();
        int size();
};

Queue::Queue(){
    this->fron = nullptr;
    this->bac = nullptr;
    this->siz = 0;
}
int Queue::front(){
    if(this->siz == 0){
        cout<<"Queue Empty"<<endl;
        return -1;
    }
    return this->fron->data;
}
void Queue::push(int ele){
    node* n = new node;
    n->data = ele;      //contructor will mark the next to nullptr
    if(this->bac != nullptr)
        this->bac->next = n;
    this->bac = n;
    if(this->siz == 0){
        this->fron = n;
    }
    this->siz++;
}

void Queue::pop(){
    if(this->siz == 0){
        cout<<"Queue Empty"<<endl;
        return;
    }
    node *temp = this->fron;
    this->fron = this->fron->next;
    this->siz--;
    if(this->siz == 0){
        this->bac = nullptr;
    }
    delete temp;
}

int Queue::size(){
    return this->siz;
}

// int main(){
//     Queue Q;
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

// }