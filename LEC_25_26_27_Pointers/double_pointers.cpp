//Double Pointer
#include<iostream>
using namespace std;

int main()
{   
    system("cls");
    int a=5;
    int* ptr=&a;
    int** ptr2=&ptr;    //double pointer

    cout<<"Value of a "<<endl;
    cout<<"a:      "<<a<<endl;
    cout<<"*ptr:   "<<(*ptr)<<endl;
    cout<<"**ptr2: "<<(**ptr2)<<endl;
    cout<<endl;
    cout<<"Address of a "<<endl;
    cout<<"&a:     "<<&a<<endl;
    cout<<"ptr:    "<<ptr<<endl;
    cout<<"*ptr2:  "<<(*ptr2)<<endl;
    cout<<endl;
    cout<<"Address of ptr"<<endl;
    cout<<"&ptr: "<<&ptr<<endl;
    cout<<"ptr2: "<<ptr2<<endl;
    cout<<endl;
    cout<<"address of ptr2: "<<&ptr2<<endl;

    
    return 0;
}