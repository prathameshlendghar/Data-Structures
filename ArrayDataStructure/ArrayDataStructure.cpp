#include<iostream>
using namespace std;
class Array{
    int capacity;
    int lastIndex;
    protected:
        int *a;
    public:
        
        Array(int);
        bool IsEmpty();
        void append(int);
        void insert(int,int);
        void Edit(int,int);
        void Delete(int);
        bool IsFull();
        int GetEle(int);
        int NoOfEle();
        int Search(int);
        void print();
        ~Array();
};

Array::Array(int size){
    capacity = size;
    lastIndex = -1;
    a = new int[size];
};
bool Array::IsEmpty(){
    return lastIndex;
};
void Array::append(int element){
    lastIndex++;
    if(lastIndex <= capacity-1){
        a[lastIndex] = element;
    }else{
        cout<<"Out of bound Exception"<<endl;
    }
};
void Array::insert(int index,int element){
    if(index>=0 && index<=lastIndex){
        for(int i=lastIndex;i>=index;i--){
            a[i+1]=a[i];
        }
        a[index] = element;
        lastIndex++;
    }else{
        cout<<"invalid index";
    }
};
void Array::Edit(int index,int element){
    if(index>=0 && index<=lastIndex){
        a[index] = element;
    }
    else{
        cout<<"There is no element at "<<index<<" to be Edited"<<endl;
    }
};
void Array::Delete(int index){
    if(index>0 && index<=lastIndex){
        while(index < lastIndex){
            a[index]=a[index+1];
            index++;
        }
        lastIndex--;
    }
    else{
        cout<<"Error";
    }
};

bool Array::IsFull(){
    return lastIndex+1==capacity;
};

int Array::GetEle(int index){
    if(index > 0 && index <= lastIndex)
        return a[index];
    else{
        cout<<"invalid index"<<endl;
        return -1;
    }
};

int Array::NoOfEle(){
    return lastIndex;
};

int Array::Search(int element){
    int count=0;
    for(int i=0;i<=lastIndex;i++){
        if(a[i]==element){
            count++;
            return i;
        }
    }
    if(count==0){
        cout<<"No such element found";
        return -1;
    }
};

void Array::print(){
    for(int i=0;i<=lastIndex;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
};

Array::~Array(){
    delete a;
};

