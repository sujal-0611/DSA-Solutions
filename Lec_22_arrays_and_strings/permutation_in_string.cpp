//LeetCode: permutation in String 
//also works for leetcode question:"find all anagrams in a string" - but had to do some slight changes 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool check(int count1[26],int count2[26])
{
    for(int i =0; i< 26; i++)
    {
        if(count1[i]!=count2[i])
            return 0;
    }
    return 1;
}
bool permute(string &s1,string &s2)
{
   
    int count_s1[26]={0};
    for(int i=0; i< s1.length(); i++)
        count_s1[s1[i] - 97]++;   //97 is bcz all character are of lowercase so for 'a' index would be 97-97=0
     
    //window to traverse in s2 and compare that window to s1 (count wise as in permutation placing doesnt matter ,but elements have to be consecutively)
    int window = s1.length();   
    int i=0;
    int count_s2[26]={0};
    while( i < window and i < s2.length()) 
    {
        count_s2[s2[i] - 97]++;
        i++;
    }
     if (check(count_s1,count_s2))
        return 1;

    //else age processing karo kuki upar wala loop bss first window ke liye tha, aage aur bhi windows hai jinke liye 
    //looping hogi
    while( i < s2.length())
    {
        count_s2[s2[i]-97]++;           //counting for element in window 
        count_s2[s2[i-window]-97]--;    //making count for element leaving window to zero

        if(check(count_s1,count_s2))    //checking for current window 
            return 1;
        i++; 
    }
    return 0;
}

int main()
{   
    system("cls");
    string s1("ab");
    string s2("eibaaoo");
    
    int res=permute(s1,s2);
    if(res)
        cout<<"Yes s2 has a permutation of s1";
    else
        cout<<"NO";
    return 0;
}