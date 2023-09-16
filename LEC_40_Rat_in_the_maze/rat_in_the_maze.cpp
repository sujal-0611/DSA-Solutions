#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool right_step(vector<vector<int>> vec, int x, int y, vector<vector<int>> visited)
{   
    //we need to satisfy 3 conditions to successfully take step to next block
    //1. if the x and y are inside of 2d vector 
    //2. the element(block) we are is visiting is 1 (i.e open path)
    //3. x and y coordinates are not already visited (i.e false)
    if( ( x>=0 && x < vec.size() ) && ( y>=0 && y < vec[0].size()) && vec[x][y] == 1 && visited[x][y] == 0 )
        return true;
    
    return false;
}
void Recur_func(vector<vector<int>> vec, int x, int y, vector<string>& ans,vector<vector<int>> visited,string path)
{
    //Base case
    if( x == vec.size()-1 and y == vec.size()-1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] =1;   //i.e we successfully reached x and y coordinate of vec so mark it as true(visited) in visited 2d vector

    //down_step
    int new_x= x+1;
    int new_y= y;
    if(right_step(vec,new_x,new_y,visited))
    {   
        path.push_back('D');
        Recur_func(vec, new_x, new_y, ans,visited,path);
        path.pop_back();    //while backtracking pop whats in the path
    }
    
    //left step
    new_x =x;
    new_y =y-1;
    if(right_step(vec,new_x,new_y,visited))
    {  
        path.push_back('L');
        Recur_func(vec, new_x, new_y, ans,visited,path);
        path.pop_back();    //while backtracking pop whats in the path
    }
    
    //right step
    new_x =x;
    new_y =y+1;
    if(right_step(vec,new_x,new_y,visited))
    {
        path.push_back('R');
        Recur_func(vec, new_x, new_y, ans,visited,path);
        path.pop_back();    //while backtracking pop whats in the path
    }
    //up_step
    new_x =x-1;
    new_y =y  ;
    if(right_step(vec,new_x,new_y,visited))
    {
        path.push_back('U');
        Recur_func(vec, new_x, new_y, ans,visited,path);
        path.pop_back();    //while backtracking pop whats in the path
    }

    visited[x][y] =  0;   //making it zero (program control come here while on backtracking)
                        //so that we can find different path

}
vector<string> RatInMaze(vector<vector<int>> vec)
{
    vector<string> ans;
    int x=0,y=0;

    //base case
    if(vec[0][0]==0)    //if rat cant even start
        return ans;
    

    vector<vector<int>> visited =vec;

    for(int i=0; i<vec.size();i++)
        for(int j=0; j<vec[i].size(); j++)
            visited[i][j] = 0;
    
    string path="";
    Recur_func(vec,x,y,ans,visited,path);
    
    sort(ans.begin(),ans.end());
    return ans;

}
int main()
{   
    system("cls");
    vector<vector<int>> vec={ {1,0,0,0},
                              {1,1,0,1},
                              {1,1,0,0},
                              {0,1,1,1} };
    
    
    vector<string> ans = RatInMaze(vec);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}