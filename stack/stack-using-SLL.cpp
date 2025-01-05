#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class stack{
    private:
        node* head;
        int siz;
    public:
        stack();
        int top();
        void push(int);
        void pop();
        int size();
};

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


// int main(){
//     stack st;
//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.size()<<endl;
//     st.push(5);
//     st.push(1);
//     st.push(3);
//     st.push(4);
//     st.push(9);
//     st.push(8);
//     st.push(5);
//     st.push(10);

//     cout<<st.top()<<endl;
//     st.pop();
//     st.pop();
//     st.push(0);
//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.size()<<endl;
//     st.pop();
//     st.pop();
//     st.pop();
//     st.pop();
//     cout<<st.size()<<endl;
//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.size()<<endl;
//     cout<<st.top()<<endl;
//     st.pop();
//     st.pop();
//     cout<<st.size()<<endl;
//     cout<<st.top()<<endl;
//     st.push(101);
//     cout<<st.size()<<endl;
//     cout<<st.top()<<endl;
// }

