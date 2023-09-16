//Subsets : leetcode BACKTRACKING APPROACH
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
}

void BS_recur(vector<int>& arr,vector<int> output, int index, vector<vector<int>>& ans)
{
    //base case 
    if(index >= arr.size())
    {
        ans.push_back(output);  //if we reached lowest level of tree(i. no more elements to discover then  push the temp_array 'output' to ans)
        return;
    }

    //call of exclusion
    BS_recur(arr,output,index+1,ans);

    //inclusion of current element to ans
    output.push_back(arr[index]);      //pushing current element to output array
    BS_recur(arr,output,index+1,ans);    //now recursive call to solve rest of cases
}
vector<vector<int>>subset(vector<int> arr)
{
    vector<vector<int>>ans;
    vector<int> output;
    int index=0;
    BS_recur(arr,output,index,ans);
    return ans;

}
int main()
{   
    system("cls");
    vector<int> vec= { 1,2,3};

    vector<vector<int>> vec2 = subset(vec);

    cout<<"all the subsets are as follows: "<<endl;
    for(int i=0; i<vec2.size();i++)
    {   
        cout<<"[";
        print(vec2[i]);
        cout<<"]";
        cout<<endl;
    }
    
    
    return 0;
}