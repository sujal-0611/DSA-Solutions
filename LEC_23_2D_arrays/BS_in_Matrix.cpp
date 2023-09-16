//USING BINARY SEARCH IN 2D MATRIX I - leetcode
//USING BINARY SEARCH IN 2D MATRIX II - leetcode

#include<iostream>
#include<vector>
using namespace std;
bool Binary_Search(vector<int> vec,int start,int end,int a)
{   
    int mid;
    while(start<=end)
    {
        mid = start + ((end-start)/2);
        if( vec[mid] == a)
            return true;
        else if ( vec[mid] > a )
            end =mid-1;
        else    
            start= mid+1;
    }
    return 0;
}
//good solution
bool BS_search1(vector<vector<int>> &vec,int a)
{
    int n=vec.size();
    int m=vec[0].size();

    int i=0;
    while( i< n )
    {
        bool res =  Binary_Search(vec[i++],0,m-1,a);
        if(res)
            return true;
    }
    return false;
}

//better solution
bool BS_search2(vector<vector<int>> &matrix,int a)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int start=0;int end= n*m-1;
        int mid;
        while(start<=end)
        {
            mid = start + ((end-start)/2);
            int row=mid/m;  //finding current row from mid(as mid( mid is index when we talk about 2d array in linear form) 
            int col=mid%m;  //is row*m +col where m is total no of columns and row is current row and col is current column )

            if( matrix[row][col] == a)
                return true;
            else if ( matrix[row][col] > a )
                end =mid-1;
            else    
                start= mid+1;
        }
        return false;
}

//more optimized solution (best among 3 solution)
bool BS_search3(vector<vector<int>> &matrix,int target)
{
    int n=matrix.size();
    int m=matrix[0].size();

    int row=0,col= m-1;
    while( (row < n) and (col >= 0) )
    {
        if( matrix[row][col] == target)
            return true;
        else if( matrix[row][col] < target)
            row++;
        else    //if 
            col--;
    }
    return false; //if element is not found
}
int main()
{   
    system("cls");
    vector<vector<int>> vec={ {1,3,5,7},
                              {10,11,16,20},
                              {23,30,34,60} };
    int a=11;
    bool res;
    //res= BS_search1(vec,a); //using binary search in every row
    //res= BS_search2(vec,a); //using binary search in whole matrix   
    res = BS_search3(vec,a);    //Best among three 
    if(res)
        cout<<"element: "<<a<<" is present in matrix";
    else
        cout<<"element is not found";
    
    return 0;
}