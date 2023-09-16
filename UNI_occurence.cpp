#include<iostream>
#include<unordered_map>
using namespace std;


//MCMXCIV
 int romanToInt(string s) {

       unordered_map<char,int> mp{
                            {'I',1} ,
                            {'V',5} ,
                            {'X',10} ,
                            {'L',50} ,
                            {'C',100} ,
                            {'D',500} ,
                            {'M',100} , 
                            };
        int no=0;

       
    
       for(int i=0 ;i < s.size() ; i++){

            /*mp[ s[i] ] returns value stored at key s[i] ex: s[0] has A and in map for key 'A' the value stored is 1 
                then mp[ s[0] ] is mp['A' ] and mp['A'] will return 1  */
        
            if(mp[s[i]] < mp[s[i+1]])   //if value stored for key s[i] is smaller than value stored for key s[i+1] in map
                no-=mp[s[i]];
            else
                no+=mp[s[i]];
        }
    
        return no;
    }
int main()
{   
    system("cls");
    string str;
    cout<<"\nEnter the Roman Number"<<endl;
    getline(cin,str);
    int c =romanToInt(str);
    //int c=abc("MXVII");
    cout<<endl<<c;
   
    return 0;
}