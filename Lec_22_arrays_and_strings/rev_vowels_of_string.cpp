//Leetcode- reverse the vowels of given string
#include<iostream>
#include<string>
using namespace std;

bool check_vowel(char a)
{
    switch(a)
    {
        case 'a': return 1;
        case 'e': return 1;
        case 'i': return 1;
        case 'o': return 1;
        case 'u': return 1;
        case 'A': return 1;
        case 'E': return 1;
        case 'I': return 1;
        case 'O': return 1;
        case 'U': return 1;
        
        default: return 0;
    }
}
int main()
{   
    system("cls");
    string s="hello";
    string sa;
    int st=0,e =s.length()-1;
      
        while(st<e)
        {
            if(check_vowel(s[st]))
            {
                if( check_vowel(s[e]))
                {   
                     swap(s[st],s[e]);
                     st++; e--;
                }
                else
                    e--;
            }
            else
                st++;
        }
    cout<<s;
    return 0;
}