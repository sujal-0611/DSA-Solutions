//CODESTUDIO replace spaces
#include<iostream>
using namespace std;

//using extra space(extra string object
string rep1(string &sa)
{
    string s;
    for(int i=0; i< sa.length(); i++)
    {
        if( int(sa[i]) != 32 ) 
            s.push_back(sa[i]);
        else
        {   
            s.push_back('@');
            s.push_back('4');
            s.push_back('0');
        }          
    }
    return s;
}

string rep2(string &sa)
{
    for(int i=0; i<sa.length(); i++)
    {   
        if(sa[i] == ' ')
        {
            sa.erase(sa.begin()+i);
            sa.insert(i,"@40");
        }
    }
    return sa;
}
int main()
{   
    system("cls");
    string s("coding ninjas is a coding platform");

    cout<<"ORiginal String\n"<<s<<endl;
    
    //cout<<"\nafter Replacing it with @40\n"<<rep1(s);
    cout<<"\nafter Replacing it with @40\n"<<rep2(s);
    return 0;
}