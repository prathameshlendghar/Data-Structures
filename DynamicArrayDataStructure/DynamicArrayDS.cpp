#include<iostream>
using namespace std;
class Array{
    private:
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array(int size){
            capacity = size;
            lastIndex = -1;
            ptr = new int[size];
        }
        bool isFull(){
            return lastIndex==capacity-1;
        }
        bool isEmpty(){
            return lastIndex==-1;
        }
        void DoubleArray(){
            capacity*=2;
            int *temp = new int[capacity];
            for(int i=0;i<=lastIndex;i++){
                temp[i] = ptr[i];
            }
            delete []ptr;
            ptr = temp;
            //delete []temp;
        }
        void halfArray(){
            capacity/=2;
            int *temp = new int[capacity];
            for(int i=0;i<=lastIndex;i++){
                temp[i] = ptr[i];
            }
            delete []ptr;
            ptr = temp;
            //delete []temp;
        }
        void append(int data){
            lastIndex++;
            if(lastIndex >= 0 && lastIndex <= capacity-1){
                ptr[lastIndex] = data;
            }else if(lastIndex > capacity-1){
                DoubleArray();
                ptr[lastIndex] = data;
            }
        }
        void insert(int index,int data){
            if(lastIndex < capacity-1){
                if(index >= 0 && index <= lastIndex){
                    for(int i = lastIndex; i>=index; i--){
                        ptr[i+1] = ptr[i];
                    }        
                    ptr[index] = data;
                    lastIndex++;
                }
            }else{
                DoubleArray();
                if(index >= 0 && index <= lastIndex){
                    for(int i = lastIndex; i>=index; i--){
                        ptr[i+1] = ptr[i];
                    }
                    ptr[index] = data;
                    lastIndex++;
                }
                else{
                    cout<<"Invalid index to insert data"<<endl;
                }
            }
        }
        void Delete(int index){
            if(index<=lastIndex){
                for(int i = index;i < lastIndex;i++){
                    ptr[i]=ptr[i+1];
                }
                lastIndex--;
                if(lastIndex < capacity/2){
                    halfArray();
                }
            }else{
                cout<<"invalid Deletion"<<endl;
            }

        }
        void edit(int index,int data){
            if(index >=0 && index <= lastIndex){
                ptr[index] = data;
            }else{
                cout<<"Invalid index to edit Data"<<endl;
            }
        }
        int get(int index){
            if(index<=lastIndex)
                return ptr[index];
            else{
                cout<<"Index invalid";
                return -1;
            }
        }

        int isElementPresent(int data){
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
        ~Array(){
            delete []ptr;
        }
};

int main(){

    Array A1(5);
    A1.append(4);
    A1.append(8);
    A1.append(2);
    A1.append(9);
    A1.append(5);
    A1.append(154);
    cout<<A1.getCapacity()<<endl;
    //A1.append(9);
    A1.print();
    cout<<A1.getCapacity()<<endl;
    A1.edit(6,8);
    A1.edit(4,10);
    A1.print();
    cout<<A1.getCapacity()<<endl;
    cout<<endl;
    A1.insert(3,12);
    cout<<A1.getCapacity()<<endl;
    A1.print();
    A1.Delete(2);
    A1.print();
    cout<<A1.isElementPresent(8)<<endl;
    cout<<A1.getCapacity()<<endl;
    cout<<A1.get(3);
    return 0;
}