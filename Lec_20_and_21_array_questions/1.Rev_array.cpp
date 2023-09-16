//Reverse the array
#include<iostream>
#include<vector>
using namespace std;

void print_arr(vector<int>& vec)
{
    int n= vec.size();
    int i=0;
    while(i < n)
    {
        cout<<(vec[i])<<" ";
        i++;
    }
    cout<<endl;
}
void rev_array(vector<int>& vec,int M)
{
    int n= vec.size();
    int i=M+1;  //as we gonna reverse after this position
    int j = n-1;

    while(i<=j)
    {
        swap(vec[i],vec[j]);
        i++;j--;
    }
    
}
int main()
{   
    system("cls");
    vector<int> vec= {1,2,3,4,5,6};
    int m=3; //the postion after which we have to start reversing till n-1

    cout<<"Original array: ";
    print_arr(vec);

    rev_array(vec,m);
    cout<<"array after reversing from "<<m<<"rd index is : ";
    print_arr(vec);
    
    
    return 0;
}