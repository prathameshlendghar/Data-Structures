
#ifndef STACK_FOR_QUEUE
#define STACK_FOR_QUEUE

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

#endif