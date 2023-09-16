#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string mapping(char a)
{
    switch (a)
    {
        case '0': return "";
        case '1': return "";
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        default : return "wxyz";

    }
}

void BS_recur(string& digit,string output, int index, vector<string>& ans)
{   
    //base case
    if(index >= digit.length()) 
    {
        ans.push_back(output);  //when there's no more characters(numbers) in digit to mapp with push final string value in 'output' to 'ans' 
        return;
    }

    string value = mapping(digit[index]);   //get mapping to corresponding number in digit (which is in string form)
    for(int i=0; i< value.length(); i++)    //now mapp for each character in string value (i.e for 2 = abc go for 'a' then ' b' and 'c')
    {
        output.push_back(value[i]);     
        //for ex: for digit: 23 ; "value" have abc (mapped from '2'), and now store 'a' in output and 
        //NOW for 'a' make a recursive call to map characters of '3' with 'a' .i.e --> ad, ae,af then on next loop map for 'b' of '2'..and so on
        BS_recur(digit,output,index+1,ans);
        output.pop_back();
    }

}
//using same inlcude exclude logic of subsets
vector<string> phone(string digit)
{
    vector<string> ans;   

                                 

    string output;                  //same concept as of subsets
    int index = 0;
    BS_recur(digit, output,index,ans);
    return ans;
    
}
int main()
{   
    system("cls");
    string digits="4";
    
    vector<string> vec=phone(digits);
    for(int i=0; i< vec.size();i++)
        cout<<vec.at(i)<<" ";
    cout<<endl;

    
    return 0;
}