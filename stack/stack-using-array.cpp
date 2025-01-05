#include<iostream>
using namespace std;

class stack{
    private:
        int capacity;
        int *st;
        int last;
    public:
        stack();
        stack(int);
        int top();
        void pop();
        void push(int);
        int size();
};

stack::stack(){
    this->capacity = 5;
    this->last = -1;
    this->st = new int[capacity];
}
stack::stack(int cap){
    this->capacity = cap;
    this->last = -1;
    this->st = new int[capacity];
}
void stack::push(int val){
    if(this->last < this->capacity-1){
        last++;
        this->st[last] = val;
    }else{
        cout<<"Stack full"<<endl;
    }
}

int stack::top(){
    if(this->last > -1){
        return this->st[last];
    }
    else{
        cout<<"Stack empty";
        return -1;
    }
}

void stack::pop(){
    if(this->last == -1){
        cout<<"Stack Empty"<<endl;
        return;
    }
    this->last--;
}

int stack::size(){
    return this->last+1;
}

// int main(){
//     stack st(7);
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
// }