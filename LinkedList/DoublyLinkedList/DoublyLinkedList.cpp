#include<iostream>
using namespace std;

struct node{
    node *prev;
    int item;
    node *next;
};

class DDL{
    public:
        node *start = new node;
        DDL();
        void insertFirst(int);
        void insertEnd(int);
        node* searchNode(int);
        void insertAfterSome(int,int);
        void deleteFirst();
        void deleteLast();
        void printitem();
        void deleteSpecific(int);
        ~DDL();
} D1;

DDL::DDL(){
    node *start = nullptr;
}

void DDL::insertFirst(int data){
    node *n = new node;
    n->prev = nullptr;
    n->item = data;
    n->next = start;
    if(start)    //if(n->next!=nullptr)
        start->prev = n;  //n->next->prev = n;
    start = n;
}

void DDL::insertEnd(int data){
    node *n = new node;
    n->item = data;
    n->next = nullptr;
    if(start){
        node *t = start;
        while(t->next!=nullptr){
            t=t->next;
        }
        n->prev = t;
        t->next = n;
    }
    else{
        n->prev = nullptr;
        start = n;
    }
}

node* DDL::searchNode(int data){
    node *t = start;
    while(t != nullptr){
        if(t->item == data)  //yaha dhyan de t->next nahi hai t!=nullptr hai
            return t; 
        t = t->next;
    }
    return t;
}

void DDL::insertAfterSome(int data,int find){
    node *n = new node;
    n->item = data;

    node *t;
    t = searchNode(find);

    n->prev = t;
    n->next = t->next;
    if(t->next!=nullptr)
        t->next->prev = n;
    t->next = n;
}

void DDL::deleteFirst(){
    if(start != nullptr){
        node *t = start;
        start = start->next;
        delete t;
        if(t->next)
            start->prev = nullptr;
    }
    else
        cout<<"No elements are present in linked list";
}

void DDL::deleteLast(){
    if(start){
        node *t = start;
        while(t->next != nullptr)
            t = t->next;
        if(t->prev)
            t->prev->next = nullptr;
        else 
            start = nullptr;
        delete t;
    }
}

void DDL::deleteSpecific(int data){
    node *t = new node;
    t = searchNode(data);
    if(t->next)
        t->next->prev = t->prev;
    // else
    //     t->prev->next = nullptr;
    if(t->prev)
        t->prev->next = t->next;
    else
        start = t->next;
    delete t;
}

DDL::~DDL(){
    while(start)
        deleteFirst();
}
