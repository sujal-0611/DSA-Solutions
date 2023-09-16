//leetcode: Remove the substring fro mthe string
#include<iostream>
using namespace std;

string rem1(string &sa,string part)
{
   
    int i=0;
   
    while( i< sa.length())
    {
        if(sa[i] == part[0])
        {
            int k=0,p=i;
            for( k =0; k< part.length(); k++)
            {   

                if( sa[p] != part[k])
                    break;
                p++;
            }
            if( k == part.length()) //i.e the loop we ran for substring was successfully completed(break didnt happened)
               sa.replace(i,k,"");
               
                //i = i+k;    // i.e skip that whole substring and update i to next character after subtring  
        }
        //s.push_back(sa[i++]);
        i++;
    }
    return sa;
}
int main()
{   
    system("cls");
    string s("daabcbaabcbc");
    string part("abc"); //substring
    cout<<"ORiginal String\n"<<s<<endl;
    
    cout<<"\nafter removing all \""<<part<<"\", string is\n"<<rem1(s,part);
    //cout<<"\nafter Replacing it with @40\n"<<rep2(s);
    return 0;
}