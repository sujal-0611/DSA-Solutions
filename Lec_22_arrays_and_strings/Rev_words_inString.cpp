//leetcode Reverse the words in a string
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//GFG varaint solution
void rev_words1(string &s)
{
    int n=s.size();
    reverse(s.begin(),s.end());

    int i =0, j=0;
    while( i<n && j<n)
    {
        if( s[j+1] == ' ' || j+1 == n)  //i checked for if j+1 is ' ', because then i can check for condition if j+1 == n 
        {
            reverse( s.begin()+i,s.begin()+j+1);
            i=j+2;  //update 'i' so that it point to character after blank space
            //had to modify i in this way- , i= j+2 because in if condition we are checking for j+1
            // if the condition was j = ' ' then it would be i=j+1
        }
        j++;    //now both i and j point to character right after blank space
    }
}

void rem_ex_space(string &s)
{
    int n=s.length();
    

    int z=0;
    while(!z)   //Loop to delete space in begining of string
    {
        if(s.front() == ' ')    //if there is a space in the begining
        {
            s.erase(s.begin());     //then erase that space
        }
        else    
            z++;    //run till there are spaces in the begining of string
    }

   int k=0; 
   while(!k)    //loop to delete spaces at the end of string
   {
        if(s.back() == ' ') //if there's a space in the end of string 
            s.pop_back();       //then pop(delete) that string 
        else
            k++;    //run till there are spaces in the begining of string
   }

    int i=0,j=0;
    while(i < n )   //To remove internal extra spaces
    {
        if( s[i] == ' ')
            j++;    //t count no of space 
        else
            j=0;
        if(j >=2 )     // if space count is more than 1 then remove it 
        {    s.erase(s.begin()+i);
            n--;
            //j--;
        }
        else
            i++; 
   }
    cout<<endl<<s<<endl;
    
}
void rev_words2(string &s)
{
    //Function to remove extra spaces in a string
    rem_ex_space(s);

    //first reverse whole string
    reverse(s.begin(),s.end());

    int i =0, j=0;
    int n=s.length();

    //loop to rereverse the each word
    while( i<n && j<n)
    {
        if( s[j+1] == ' ' || j+1 == n)  //i checked for if j+1 is ' ', because then i can check for condition if j+1 == n 
        {
            reverse( s.begin()+i,s.begin()+j+1);
            i=j+2;  //update 'i' so that it point to character after blank space
            //had to modify i in this way- , i= j+2 because in if condition we are checking for j+1
            // if the condition was j = ' ' then it would be i=j+1
        }
        j++;    //now both i and j point to character right after blank space
    } 
   
}
int main()
{   
    system("cls");
    string s1("the sky is blue");
    string s2("a good   example");

    //cout<<"Original String: "<<endl<<s1;
    cout<<"Original String: "<<endl<<s2;

    //rev_words1(s1);   //solution for gfg variant
    //cout<<endl<<"After Reversing the words in String: "<<endl<<s1;

    rev_words2(s2);     //solution for leetcode variant
    cout<<endl<<"After Reversing the words in String: "<<endl<<s2;
    return 0;
}