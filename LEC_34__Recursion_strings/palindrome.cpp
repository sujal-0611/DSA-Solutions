#include<iostream>
using namespace std;

//for string palindrome
bool check_palin1(string& str,int i)
{   
    if( i > (str.length()-1)/2 )    //BC1
        return true;
    else if( str[i] == str[str.length()-1-i] )  //if true then ...(checking 1 case and letting recursion handle rest)
        return check_palin1(str,i+1);            //... continue checking (letting recursion handle rest)
    else    // if (str[i] != str[str.length()-1-1])
        return false;      //BC2
        
}

//for num palindrome
void check_palin2(int num,int& sum )
{
    if( num ==0)
        return ;

    sum = num%10 + sum*10;
    num = num/10;
    
    check_palin2(num,sum);
}   
int main()
{   
    system("cls");
    string str("radar");

    int num(1221);
    int sum =0;

    bool res;
    //res = check_palin1(str,0);  //for string palindrome

    check_palin2(num,sum); //for num palindrome0
    
    (num == sum) ? res = true : res = false;

    if(res)
        cout<<"It is palindrome";
    else
    cout<<"It is not a palindrome";
    return 0;
}   