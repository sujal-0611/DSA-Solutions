#include<iostream>
using namespace std;

int main()
{   
    system("cls");
    int num=5;
    /*
    cout<<"Address of "<<num<<" is "<<&num;

    //storing address in pointer variable
    int *ptr= &num;
    cout<<"\nAddress of "<<*ptr<<" is "<<ptr;
    cout<<"\n *ptr++ is "<<++(*ptr);
    cout<<"\n now num is "<<num;


    //Getting address of pointer variable(which hold address of variable num)
    cout<<"\n\nAddress of Pointer variable ptr is "<<&ptr;
    double p=3.2;
    double *p2=&p;
    cout<<endl<<"Size of double "<<sizeof(p)<<" size of double pointer "<< sizeof(p2);
    

    //copy pointer
    int b=5;    //normal variable b
    int *ptr1=&b;   //pointer ptr pointing to b (or pointer ptr having address of variable b)
    int *ptr2=ptr1; // (ptr2 = ptr1= &b) pointer ptr2 receiveing address of variable a which was stored in pointer ptr1 
    cout<<" b: "<<b<<" address "<<&b<<endl;
    cout<<"value of b from pointer ptr1 : "<<*ptr1<<" address "<<ptr1<<" address of pointer ptr1 "<<&ptr1<<endl;
    cout<<"after copying address(of b) from ptr1 to ptr2 : "<<*ptr2<<" address "<<ptr2<<" address of pointer ptr2 "<<&ptr2<<endl;
    

    //void pointer 
    int a=5;
    void *ptr;
    ptr =&a;
    cout<<"address of a is "<<ptr;
    
    char ch='a';
    char *ptr=&ch;
    cout<<(*ptr)<<" ";
    //ptr=ptr+1;
    cout<<++(*ptr);
    
   
   //array name is treated as a pointer pointing to the first element of the array
   int arr[4]={2,6,4,7};
   cout<<"with arr[0]\n"<<arr[0]<<endl;
   cout<<"with pointer name i.e *arr\n"<<*arr; 
   cout<<"\naddress of first element with & (address of operator) : &arr[0](adrress of first array element)\n"<<&arr[0];
   cout<<"\naddresss of first element with just array name: arr (as array name is a pointer storing address first element of array )\n"<<arr;
   cout<<"\nalso if we just treat array name as a normal variable then &arr(i.e adrress of arr) \n"<<&arr;
   cout<<"\n*arr+1 is value by derefrencing at arr and then add 1 i.e 2+1\n"<<*arr+1;
   cout<<"\n*(arr+1) is add size of pointer's basetype to arr and then derefrence it(i.e will print  2nd element in array)\n"<<*(arr+1);

   */
 
    return 0;
}