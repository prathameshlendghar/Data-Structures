#include<iostream>
#include "AdditionalFunctionality.cpp"
int main(){
    AdditionalFunction A1(8);
    A1.append(6);
    A1.append(9);
    A1.append(2);
    A1.append(0);
    A1.append(6);
    A1.append(2);
    A1.append(0);
    A1.append(6);

    A1.print();
    A1.Sort();
    A1.print();
    A1.Edit(2,8);
    A1.print();
    cout<<"The gratest is "<<A1.greatest()<<endl;
    cout<<"The samllest is "<<A1.smallest()<<endl;
    int temp = A1.Search(5);
    if(temp>=0){
        cout<<"Element is present at index "<<temp;
    }else{
        temp;
    }
    cout<<"Sum of all the elements in array is "<<A1.sumAllElements()<<endl;
    cout<<"Average of all the elements in array is "<<A1.averageOfAllElements()<<endl;

    A1.rotate(2);
    A1.print();

    A1.swap(1,3);
    A1.print();
    cout<<"Second largest element is "<<A1.secondLargest()<<endl;
    A1.removeDuplicates();
    A1.print();

//     cout<<A1.GetEle(2)<<endl;
//     cout<<A1.GetEle(4)<<endl;

//     A1.Delete(1);
//     A1.Delete(6);
//     A1.print();
//     cout<<A1.IsEmpty();
//     cout<<endl;
//     cout<<A1.Search(8);
//     cout<<endl;
//     cout<<A1.Search(9)<<endl;
//     cout<<"Total num of element present is "<<A1.NoOfEle()<<endl;
//     return 0;
}