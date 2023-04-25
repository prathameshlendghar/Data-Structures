#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
class SLL{
    node* start = new node;

    public:
        SLL(){
            start = nullptr;
        }
        void insertAtFirst(int data){
            node *temp = new node;
            temp->data = data;
            temp->next = start;
            start = temp;
        }
        void insertAtEnd(int data){
            node *t;
            node *temp = new node;
            temp->data = data;
            temp->next = nullptr;
            t = start;
            if(t == nullptr){
                insertAtFirst(data);
            }else{
                while(t->next != nullptr){
                    t = t->next;
                }
                t->next = temp;
            }
        }
        node* searchNode(int data){
            node *t = new node;
            t = start;
            while(t!=nullptr){
                if(t->data == data){
                    return t;
                }
                t=t->next;
            }
            return t;
        }

        void insertAfterSome(node * ptr,int data){
            node *n = new node;
            n->data = data;
            n->next = ptr->next;
            ptr->next = n;
        }

        void deleteFirst(){
            node *t;
            if(start){
                t = start;
                start = start->next;
                delete t;
            }
        }
        void deleteLast(){
            node *t;
            if(start == nullptr){
                cout<<"\nunderflow";
            }
            else if(start->next == nullptr){
                delete start;
                start = nullptr;
            }
            else{
                t = start;
                while(t->next->next != nullptr){
                    t = t->next;
                }
                delete t->next;
                t->next = nullptr;
            }
        }
        void deleteSpecific(node *temp){
            node *t;
            if(start == temp){
                start = temp->next;
                delete temp;
            }else if(start==nullptr){
                cout<<"\nunderflow";
            }else{
                t = start;
                while(t->next != temp)
                    t = t->next;
                t->next = temp->next;
                delete temp;

            }
        }
        ~SLL(){    
            while(start){
                deleteFirst();
            }    
        }

        node * getfirstNode(){
            return start;                                                       
        }

        int countElements(SLL);
        void reverseList(SLL);
};


int SLL :: countElements(SLL ll){
    node *t = start;
    int i = 0;
    while(t!=nullptr){
        i += 1;
        t = t->next;
    }
    return i;
}

void SLL :: reverseList(SLL ll){
    // int length = countElements(ll);
    // int i = 1;
    // while(length > i){
        
    // }
    
}