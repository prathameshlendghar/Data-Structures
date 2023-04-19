#include "ArrayDataStructure.cpp"
#include<iostream>

class AdditionalFunction:public Array{
    public:
    // AdditionalFunction(int x){
        
    // AdditionalFunction(int size){
    //     capacity = size;
    //     lastIndex = -1;
    //     a = new int[size];
    // }
    AdditionalFunction(int x):Array(x){}
    void Sort();
    int greatest();
    int smallest();
    int sumAllElements();
    int averageOfAllElements();
    void rotate(int);
    void removeDuplicates();
    int secondLargest();
    void swap(int,int);

};

void AdditionalFunction::Sort(){
    for(int i=0;i<NoOfEle();i++){
        for(int j=i;j<=NoOfEle();j++){
            if(a[i]>a[j]){
                int temp;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
};

int AdditionalFunction::greatest(){
    int temp = a[0];
    for(int i=0;i<=NoOfEle();i++){
        if(a[i]>temp){
            temp = a[i];
        }
    }
    return temp;
};

int AdditionalFunction::smallest(){
    int temp = a[0];
    for(int i=0; i<=NoOfEle();i++){
        if(temp>a[i]){
            temp = a[i];
        }
    }
    return temp;
};

int AdditionalFunction::sumAllElements(){
    int sum = 0;
    for(int i=0;i<=NoOfEle();i++){
        sum+=a[i];
    }
    return sum;
};

int AdditionalFunction::averageOfAllElements(){
    return sumAllElements()/(NoOfEle()+1);
};

void AdditionalFunction::rotate(int num){
    for(int i = 1;i<=num;i++){
        int temp = a[0];
        for(int j = 0;j<NoOfEle();j++){
            a[j] = a[j+1];
        }
        a[NoOfEle()] = temp;
    }
};

void AdditionalFunction::removeDuplicates(){
    for(int i=0;i<NoOfEle();i++){
        for(int j=i+1;j<=NoOfEle();j++){
            if(a[i]==a[j]){
                Delete(j);
                j--;//bcz agar element delete ho gaya uske baad j++ hoga to jo shift hoga vo miss kar diya humne
            }
        }
    }
};

int AdditionalFunction::secondLargest(){
    int temp1 = greatest();
    int temp2 = a[0];
    for(int i=0;i<=NoOfEle();i++){
        if(a[i]>temp2 && a[i]<temp1)
            temp2 = a[i];
    }
    return temp2;
};

void AdditionalFunction::swap(int index1,int index2){
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
};
