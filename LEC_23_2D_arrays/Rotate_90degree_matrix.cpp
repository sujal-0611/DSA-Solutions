//Leetcode: Rotate 90 degree a matrix
#include<iostream>
#include<vector>
using namespace std;

void print_2darr(vector<vector<int>> vec)
{
    int i=0,j=0;
    int n=vec.size();
    int m=vec[0].size();

    while(i<n)
    {
        j=0;
        while(j<m)
        {
            cout<<vec[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    cout<<endl;
}

void rev(vector<int> &col,int start,int end)
{
    //reversing each vector inside vector
    while(start<=end)
    {
        swap(col[start++],col[end--]);
    } 
}
void rotate1(vector<vector<int>> &vec)
{
    //LOGIC: simple first rotating it to 90 degree is - first access each element column wise(i.e first loop is for col and inner loop for row)
    // and store as well them in another vector , after that the elements in another are reverse of final 
    //so  we need so we apply reverse function on each row of another 
    //USE EXTRA SPACE
    int i=0,j=0;
    int n=vec.size();
    int m=vec[0].size();
    vector<vector<int>> vec2(n,vector<int>(m,0));

    while(j<m)
    {
        i=0;
        while(i<n)
        {
            vec2[j][i]=vec[i][j];  //access element from vec column wise, but store them in vec2[j][i] row wise 
            i++;
        }
        j++;
    }

    //after loop we got our elements in vec2 but still each row need to be reversed to get final anwser,so we will reverse each row
    i=0; 
    while(i<n)
    {
        rev(vec2[i],0,n-1);
        i++;
    }
    vec=vec2;
}

void rotate2(vector<vector<int>> &vec)
{
   
    int n=vec.size();
    int m=vec[0].size();
 
    int i=0,j=0;
    //first swap all elements i.e change their positons for row wise to column wise(not access but actually rearrangeing them )
    while( i < n )
    {
        j=0;
        while( j<i)     //to prevent reswapping 
        {
            swap(vec[i][j], vec[j][i]);
            j++;
        }
        i++;
    }
    i=0;
    while( i < n )  //reverse row wise 
    {
        rev(vec[i],0,m-1);
        i++;
    }
}
 
 int main()
{   
    system("cls");
    vector<vector<int>> vec={ {1,2,3},
                              {4,5,6},
                              {7,8,9} };
    cout<<"original Matrix:"<<endl;
    print_2darr(vec);

    //rotate1(vec);   //use extra space - access of elements column wise
    rotate2(vec); //without using extra space using swap and reverse functions
    cout<<"Rotated matrix (rotated by 90 degree):"<<endl;
    print_2darr(vec);

    
    return 0;
}