#include<iostream>
#include<vector>
using namespace std;

void compress(vector<char> &vec)
{
    string s;
    int i=0,j=1;
    int n=vec.size();
    int count=0;

    while( j< n)
    {
        if( vec[i] == vec[j])
        {
            count++;
            j++;
        }
        else
        {
            s.push_back(vec[i]);
            s.push_back(char(count));
            i=j;
            j++;
            count = 0;
        }
        for(int i=0; i< s.length(); i++)
            cout<< s[i]<< " ";
    }
}
int main()
{   
    system("cls");
    vector<char> vec={'a','a','b','b','c','c','c'};

    compress(vec);

   
    
    return 0;
}