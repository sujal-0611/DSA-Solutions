//Exact same solution as of subsets
//substrings: codestudio
#include<iostream>
#include<vector>
using namespace std;

void BS_recur(string str,string output, int index, vector<string>& ans)
{
    //base case 
    if(index >= str.length())
    {
        if(output.length()>0) //so that empty substring(subset) dont get pushed to ans
            ans.push_back(output);  //if we reached lowest level of tree(i. no more elements to discover then  push the temp_array 'output' to ans)
        return;
    }

    //call of exclusion
    BS_recur(str,output,index+1,ans);

    //inclusion of current element to ans
    output.push_back(str[index]);      //pushing current element to output array
    BS_recur(str,output,index+1,ans);    //now recursive call to solve rest of cases
}

vector<string> substr(string str)
{
    vector<string> ans;
    string output="";
    int i=0;
    BS_recur(str,output,i,ans);
    
    return ans;

}
int main()
{   
    system("cls");
    string str = "abc";

    vector<string> vec2 = substr(str);

    cout<<"all the substrings are as follows: "<<endl;

    for(int i=0; i<vec2.size();i++)
    {   
        cout<<"["<<vec2[i]<<"]";
        cout<<endl;
    }
    
    
    return 0;
}