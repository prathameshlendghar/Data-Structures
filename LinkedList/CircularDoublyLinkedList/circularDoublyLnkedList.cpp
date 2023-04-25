#include<iostream>
using namespace std;

struct node{
    node *prev;
    int item;
    node *next;
};

class CDLL{
    node * start;    
    
    public:
    CDLL();
    void insertFirst(int);
    void insertLast(int);
    node* searchNode(int);
    void inserAfterSome(int,int);
    void deleteFirst();
    void deleteLast();
    void deleteSpecific(int);
    ~CDLL();
};

CDLL::CDLL(){
    start = nullptr;
};

void CDLL::insertFirst(int data){
    node *n = new node;
    n->item = data;
    if(start){
        n->prev = start -> prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
        start = n;
    }
    else{
        start = n;
        n->prev = n;
        n->next = n;
    }
}

void CDLL::insertLast(int data){
    node *n = new node;
    n->item = data;
    if(start){
        n->prev = start->prev;
        n->next = start;
        start->prev->next = n;
        start->prev = n;
    }else{
        start = n;
        n->prev = n;
        n->next = n;
    }
}

node* CDLL :: searchNode(int data){
    node *t = start;
    while(t->next != start){
        if(t->item == data){
            return t;
        }
        t = t->next;
    }
    return nullptr;
}

void CDLL::inserAfterSome(int data,int find){
    node *t = searchNode(find);
    if(t){
        node *n = new node;
        n->prev = t;
        n->item = data;
        n->next = t->next;
        t->next->prev = n;
        t->next = n;

    }else{
        cout<<"No element found";
    }
}

void CDLL::deleteFirst(){
    node *t = start;
    if(start->next != start){
        start->next->prev = start->prev;
        start->prev->next = start->next;
        start = start->next;
        delete t;
    }else if(start->next == start){
        start = nullptr;
        delete t;
    }else
        cout<<"linked list is Empty";
}

void CDLL::deleteLast(){
    node *t = start->prev;
    if(t->prev != t){
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }else if(t->prev == t){
        start = nullptr;
        delete t;
    }else{
        cout<<"List is empty";
    }
}

void CDLL::deleteSpecific(int data){
    node *t = searchNode(data);
    if(t && t->next != t){
        t->prev->next = t->next;
        t->next->prev = t->prev;
            if(start == t)
                start = temp->next;
        delete t;
    }else if(t && t->next == t){
        delete t;
        start = nullptr;
    }else{
        cout<<"List is empty";
    }
}

CDLL::~CDLL(){
    while(start){
        deleteFirst();
    }
}