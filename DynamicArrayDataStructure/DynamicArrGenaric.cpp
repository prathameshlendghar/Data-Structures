#include<iostream>
using namespace std;
template<typename X>
class Array{
    private:
        int capacity;
        int lastIndex;
        X *ptr;
    public:
        Array(int size){
            capacity = size;
            lastIndex = -1;
            ptr = new X[size];
        }

        Array(Array &a){
            capacity = a.capacity;
            lastIndex = a.lastIndex;
            ptr =new X[a.capacity];
            for(int i = 0;i<=lastIndex; i++){
                ptr[i] = a.ptr[i];
            }
        }

        void operator=(Array &a){
            capacity = a.capacity;
            lastIndex = a.lastIndex;
            ptr =new int[a.capacity];
            for(int i = 0;i<=lastIndex; i++){
                ptr[i] = a.ptr[i];
            }
        }

        bool isFull(){
            return lastIndex==capacity-1;
        }
        bool isEmpty(){
            return lastIndex==-1;
        }
        void DoubleArray(){
            capacity*=2;
            X *temp = new X[capacity];
            for(int i=0;i<=lastIndex;i++){
                temp[i] = ptr[i];
            }
            delete []ptr;
            ptr = temp;
        }

        void halfArray(){
            capacity/=2;
            X *temp = new X[capacity];
            for(int i=0;i<=lastIndex;i++){
                temp[i] = ptr[i];
            }
            delete []ptr;
            ptr = temp;
        }
        void append(X data){
            lastIndex++;
            if(lastIndex >= 0 && lastIndex <= capacity-1){
                ptr[lastIndex] = data;
            }else if(lastIndex > capacity-1){
                DoubleArray();
                ptr[lastIndex] = data;
            }
        }
        void insert(int index,X data){
            if(lastIndex == capacity - 1){
                DoubleArray();
            }
            if(lastIndex < capacity-1){
                if(index >= 0 && index <= lastIndex){
                    for(int i = lastIndex; i>=index; i--){
                        ptr[i+1] = ptr[i];
                    }        
                    ptr[index] = data;
                    lastIndex++;
                }
                else{
                    cerr<<"Invalid index to insert data"<<endl;
                }
            }
        }

        X& operator[](int index){
            if(index >= 0 && index <= lastIndex){
                return ptr[index];
            }else{
                cerr<<"Invalid index"<<endl;
            }
        }

        void Delete(int index){
            if(index >= 0 && index <= lastIndex){
                for(int i = index; i < lastIndex; i++){
                    ptr[i]=ptr[i+1];
                }
                lastIndex--;
                if(lastIndex < capacity/2){
                    halfArray();
                }
            }else{
                cerr<<"invalid Deletion";
            }
        }

        void edit(int index,X data){
            if(index >=0 && index <= lastIndex){
                ptr[index] = data;
            }else{
                cerr<<"Invalid index to edit Data";
            }
        }

        X get(int index){
            if(index >= 0 && index<=lastIndex)
                return ptr[index];
            else{
                cerr<<"Index invalid";
            }
        }

        int isElementPresent(X data){
            int count=0;
            for(int i=0;i<=lastIndex;i++){
                if(ptr[i]==data){
                    count++;
                    return i;
                }
            }
            if(count == 0) return -1;
        }

        void print(){
            for(int i=0;i<=lastIndex;i++){
                cout<<ptr[i]<<" ";
            }
            cout<<endl;
        }

        int getCapacity(){
            return capacity;
        }

        int getlastIndex(){
            return lastIndex;
        }

        ~Array(){
            delete []ptr;
        }
};

