//REVERSE The STRING USING RECURSION
#include<iostream>
using namespace std;

//RECURSVIE FUNCTION (Optimized i.e using 1 pointer only)
void rev_recur(string& str,int sizee)   //passing by reference so that changes made here will reflect on original string
{   
    
    if( sizee > (str.length()-1)/2 )  return ;  //BC
    
    swap( str[sizee], str[str.length()-sizee-1]);   //Processing
    //I sovled 1 case then..

    //...let recursion handle rest of cases
    rev_recur(str,sizee+1); //R.R
}
int main()
{   
    system("cls");
    string str = "abcdefg";

    cout<<"Original String: "<<str<<endl;

    rev_recur(str,0);
    cout<<"Reversed String: "<<str<<endl;

    
    return 0;
}