//check if given string is palindrome or not - codestudio
//same solution for "valid palindrome" of leetcode
//same solution for "sentence palindrome" of GFG
#include<iostream>
using namespace std;

//Solution using extra space
bool check_palindrome1(string &st)
{
    string sa;
    for(int i =0; i<st.length() ; i++)
    {   
        int ch=st[i];   //storing ASCII 
        if(ch >= 65   and ch <= 90) // or st[i] >= 'A' && st[i] <= 'Z'
            sa.push_back(ch);
        else if ( ch >= 97 && ch <=122)
            sa.push_back(ch);
        else if( ch >= 48 && ch <= 57)
            sa.push_back(ch);
    }
    //for uppercase to lowercase
    for(int i=0; i< sa.length(); i++)
    {
        int ch =sa[i];
        if(ch >=65 && ch<=90)   //if upercase
            sa[i] = ch+32;  //then convert to lowercase
    }

    int s=0, e= sa.length()-1 ;
    while(s < e)
    {
        if(sa[s++] != sa[e--])
            return 0;
    }
    
    return 1;
}

bool check_palindrome2(string &s)
{
     //Bit complex to read but  without using extra space
    int st=0, e= s.length()-1 ;
    while(st < e)
    {   if(isalnum(s[st])==0) //i.e if that character is neither alphabet nor number
            st++;   //then move on to next
        else if(isalnum(s[e])==0) //same reason as above
            e--;    //move on to previous one
        else 
        {
          //first convert to lowercase then compare
        int ch =s[st];
        if(ch >=65 && ch<=90)   //if element at start index is uppercase
            s[st] = ch+32;  //then convert to lowercase
         ch =s[e];
        if(ch >=65 && ch<=90)   //if element at end index is uppercase
            s[e] = ch+32;  //then convert to lowercase
        
        if(s[st]!=s[e])
            return 0;

          st++; e--;
        }
        
    }
    
    return 1;
}
int main()
{   
    system("cls");

    string s="N2 i&nJA?a& jnI2n";

    int result;
    //result= check_palindrome1(s); //using extra space
    result= check_palindrome2(s);   //without using extraspace
    if(result)
        cout<<endl<<"Palindrome";
    else
        cout<<"Not a Palindrome";
    
    return 0;
}