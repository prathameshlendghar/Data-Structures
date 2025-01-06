#include "stack-for-queue.h"
#include<iostream>
using namespace std;

stack::stack(){
    this->head = nullptr;
    this->siz = 0;
}

int stack::size(){
    return siz;
}

void stack::pop(){
    if(this->head == nullptr){
        cout<<"stack empty"<<endl;
        return;
    }
    node* temp = this->head;
    this->head = this->head->next;
    delete temp;
    this->siz--;
}

void stack::push(int ele){
    //creating the node
    node* n = new node;
    n->data = ele;
    n->next = this->head;
    this->head = n;
    this->siz++;
}

int stack::top(){
    if(this->head == nullptr){
        cout<<"Stack Empty";
        return -1;
    }
    return head->data;
}
