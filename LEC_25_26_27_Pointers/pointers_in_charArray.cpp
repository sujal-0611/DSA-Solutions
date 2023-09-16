//pointers with char array
#include<iostream>
using namespace std;

int main()
{   
    system("cls");
     //now char arrays as pointers
  //they work differently from int arrays
  //cout have different implimentation for char arrays
    char arr[6]="sujal";
    cout<<"arr: "<<arr<<endl;  //instead of printing address of first element in char array , cout prints whole char array
    cout<<"*arr: "<< *arr<<endl;   //this actually print 's' only
    cout<<"&arr: "<<&arr<<endl;
    cout<<"&arr[0]: "<<&arr[0]<<endl;
    //or 
    cout<<endl;
    //char *ch=&arr;  //we cant do it with char pointers so we change it into 
    char *ch=&arr[0];   //this or
    //char *ch=arr; //this
    cout<<"ch: "<<ch<<endl; //again instead of printing address of first element in arr ,it is printing whole char array
    //this is because cout have different implimentation for char arrays, here cout start printing from adrress of 0th index till it encounter null character(\0).
    cout<<"&ch: "<<&ch<<endl;    //this prints address of char pointer variable ch ( not address of arr)
    cout<<"*ch: "<<*ch<<endl;
    
    return 0;
}