//just passing values and printing them
#include<iostream>
using namespace std;

void print(int *a)  //a is formal parameter
{
    cout<<*a<<endl;;
}
void printarr(int *a,int size)
{
    for(int i=0; i<size; i++)
        cout<< *(a + i)<<" ";
    
    cout<<endl;
}
void printchar(char *a)
{
    cout<<"*a: "<<*a<<endl;
    cout<<" a: "<<a<<endl;
    cout<<"through loop: ";
    for(int i=0; *(a+i)!= '\0'; i++)    //*(a+i)!='\0' i.e traverse till we encounter null character(which is placed at last of char array) 
        cout<<*(a + i)<<" ";
    cout<<endl;
}
int main()
{   
    system("cls");
    //passing single variable through pointer
    int a=5;
    int *ptr=&a;
    print(ptr); //passing pointers(actual parameter) to formal parameters(in function defination)

    //for int array
    int arr[4]={1,3,6,8};
    printarr(arr,4);    //passing array arras base address as parameters

    int *ptr2=arr;   //or int *ptr2=&b both are same in case of int type
    printarr(ptr2,4);    //passsing base address of array arr (which was stored in pointer ptr2) as parameters

    //for char array
    char arr2[6]="sujal";
    printchar(arr2);    //passing array name as base address
    char *ch= arr2;
    printchar(ch);      //passing a pointer (which is storing base address of array)
    

    
    return 0;
}