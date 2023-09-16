//Leetcode- Valid Palindrome 2
#include<iostream>
#include<string>
using namespace std;

void print_arr(string &s)
{
    for(int i=0;i<s.length();i++)
        cout<<s[i]<<" ";
    cout<<endl;
}

//Solution is correct but it is showing TLE in leetcode
bool check1(string s)
{
    /*WHAT WE ARE DOING her is we will run a loop for n times (n is length of string) and inside the loop
    we will create a temporary string into which we will copy all the elements of 
    original string and also **we will remove one character every iteration(by using erase function) because 
    that's what is asked in leetcode question and then!!! 
    we will check if that temporary string(modified by erase() ) is palindrome or not,
    if not then then count will be zero and break out of the inner loop(the loop which is checking for palindrome) and
     move onto next iteration of outer loop (i.e again same whole process of creating temp string etc....)
    AND if temp string is palindrome then the inner loop never breaks,hence count remains 1
    then we check if count is 1 (ie same what written in above line, if count is 1 then return 1)
    else if whole iteration of outer loop is finished that means we never able to return 1 and given string is not a palindrome
      hence return 0
    */
   /*
   int count=1;
    int st=0, e= s.length()-1 ;
    while(st < e)       //for case if string has no need to delete any cgaracter and is palindrome (this case is also considered in below loop)
    {
        if(s[st++] != s[e--])
        {
            count=0;
            break;
         }
    }
    if(count ==1)
        return 1;
        */
    for(int i=0; i<= s.length(); i++)
        {
            string sa(s);   //coopy through constructor
            int count =1;
            
            if(i>=1)
                sa.erase(sa.begin()+i-1);

            int st=0, e= sa.length()-1 ;
            while(st < e)
            {
                if(sa[st++] != sa[e--])
                {
                    count=0;
                    break;
                }
            }
            if(count == 1)
                return 1;
        }   
        return 0;     
}


bool ispal(string &s,int start,int end)
{
    while(start < end)
    {
        if(s[start++] != s[end--])
        {
            return 0;
        }
    }
    return true;
}
//Optimized Solution
bool check2(string s)
{
    int start=0, end= s.size()-1;
    while(start <= end)
    {
        if( s[start] == s[end])
        {
            start++; end--;
        }
        else
            if( ispal(s,start+1,end) || ispal(s,start,end-1))
                return 1;
            else 
                return 0;
    }
    return 1;
}
int main()
{   
    system("cls");
   
    string s="abc";
    int res;
    //res=check1(s);      //brute force
    res = check2(s);    //optimized solution
    if(res)
        cout<<"palindrome";
    else
    cout<<"Not palindrome";
    
    return 0;
}