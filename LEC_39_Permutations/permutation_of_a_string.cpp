//Permutations in a string - leetcode , GFG
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
//aprroach 1
void Recur_func1(string str, string output,int index, vector<string>& ans)
{   
    //Base case
    if(index >= str.length()) 
    {
        ans.push_back(output);
        return;
    }

    for(int i =index; i< str.length();i++)  //loop to iterate over each alphabet in given string 'str'
    {
        swap(output[i],output[index]);      //initial input in 'output' is 'str' (line 26)
        Recur_func1(str,output,index+1,ans); 
    }

}
//Approach 2: w/o using extra space , directly manipulating original string ,and backtracking
void Recur_func2(string str,int index, vector<string>& ans)
{
    //Base case
    if(index >= str.length()) 
    {
        ans.push_back(str);
        return;
    }

    for(int i =index; i< str.length();i++)  //loop to iterate over each alphabet in given string 'str'
    {
        swap(str[i],str[index]);      //initial input in 'output' is 'str' (line 26)
        Recur_func2(str,index+1,ans); 
    }

}
//approach 1 using extra space for vector 'output'
vector<string> permute(string str)
{
    vector<string> ans;
    int index=0;
    string output=str;  //initial input for 'output' 
    //Recur_func1(str,output,index,ans);    //Apprach 1 : using exta space vector " output"
    Recur_func2(str,0,ans);     //appraoch 2: w/o using extra space , manipulating original vector only(backtracking)
    /*  //for GFG variant

    unordered_set<string> st;
    for(int i=0; i<ans.size();i++)
    {
        st.insert(ans[i]);
    }
    for(auto i:st)
        cout<<i<<" ";
    cout<<endl;
    */
    return ans;
}
int main()
{   
    system("cls");
    string str="abc";
    
    vector<string> vec= permute(str);
    for(int i=0; i<vec.size();i++)
        cout<<" \""<<vec[i]<<" \"";
    return 0;
}