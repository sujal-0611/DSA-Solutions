//leetcode: Remove the substring fro mthe string
#include<iostream>
using namespace std;

string rem1(string &sa,string part)
{   
    //finding if part is in string sa by using find(), if found then erase it then look again ,
    // loop goes till the string 'part' is completely removed from string sa
    while( sa.find(part) != string::npos)   
    {
        sa.erase(sa.find(part), part.length());     //find function return the starting point of sub string (if found in main string)
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