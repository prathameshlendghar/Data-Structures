#include<iostream>
using namespace std;

struct node{
    int item;
    node *next;
};

class CLL{
    node *last;
    public:
        CLL();
        void insertFirst(int);
        void insertLast(int);
        node* searchNode(int);
        void insertAfter(int,int);
        void deleteFirst();
        void deleteLast();
        void deleteSpecific(int);
        ~CLL();
};

CLL::CLL(){
    last = nullptr;
}
void CLL::insertFirst(int data){
    node *n = new node;
    n->item = data;
    if(last){
        n->next = last->next;
        last->next = n;
    }else{
        last = n;
        n->next = last;
    }
}
void CLL::insertLast(int data){
    node *n = new node;
    n->item = data;
    if(last){
        n->next = last->next;
        last->next = n;
        last = n;
    }else{
        last = n;
        n->next = last;
    }
}
node* CLL::searchNode(int data){
    if(last){
        node *t = last->next;
        while(t!= last){
            if(t->item == data)
                return t;
            t = t->next;
        }
        if(t->item == data)
            return t;
        else
            return nullptr;
    }
    else return nullptr;
}
void CLL::insertAfter(int data,int find){
    node *t = searchNode(find);
    if(t){
        node *n = new node;
        n->item = data;
        n->next = t->next;
        if(t == last)
            last = n;
        t->next = n;
    }
}
void CLL:: deleteFirst(){
    if(last){
        node *t = last->next;
        if(last->next->next != last->next)
            last->next = last->next->next;
        else last = nullptr;
        delete t;
    }
    else
        cout<<"Linked list is empty";
}

void CLL::deleteLast(){
    if(last->next = last){
        delete last;
        last = nullptr;
    }
    else if(last){
        node *t = last;
        while(t->next != last){
            t = t->next;
        }
        t->next = last->next;
        last = t;
        delete t;
    }else{
        cout<<"Empty linked list.";
    }
}
void CLL::deleteSpecific(int data){
    if(last){
        node *t = searchNode(data);
        if(t == last)
            deleteLast();
        else if(t == last->next)
            deleteFirst();
        else{
            node *temp = last->next;
            while(temp->next != t){
                temp = temp->next;
            }
            temp->next = t->next;
            delete t;
        }
    }else{
        cout<<"Empty linked list";
    }
}
CLL::~CLL(){
    while(last){
        deleteFirst();
    }
}