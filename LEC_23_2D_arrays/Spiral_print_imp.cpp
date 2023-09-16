//IMPORTANT QUESTION
//leetcode: spiral print
//GFG: Spirally traversing a matrix
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral(vector<vector<int>>& matrix)
{   
        int n=matrix.size(); //to find no of rows
        int m=matrix[0].size();    //to find no of columns

        int i=0 ;   //start row
        int k=n-1;  //end row
        int l=0;    //start col
        int j=m-1;  // end col
        
        vector<int> vec;
        int count=0,total=n*m;
        
        while( count < total )  //till whole matrix is traversed
        {
            //starting row
            for(int index= l; index <= j and count<total ; index++)
            {
                vec.push_back(matrix[i][index]);
                count++;
            }
            i++; //increment starting row(i.e make next row as starting row)
            
            //ending column
            for( int index= i; index <= k and count<total; index++)
            {
                vec.push_back(matrix[index][j]);
                count++;
            }
            j--; //make previous Column as new Ending col
            
            //ending row
            for(int index= j; index >= l and count<total; index--)
            {
                vec.push_back(matrix[k][index]);
                count++;
            }
            k--;    //make previous row as new ending Row
            
            //starting column
            for(int index = k ; index >= i and count<total; index--)
            {
                vec.push_back(matrix[index][l]);
                count++;
            }
            l++;    //make next Column as new starting column
        }
        return vec;

}
int main()
{   
    system("cls");
    vector<vector<int>> vec={ {1,2,3},
                              {4,5,6},
                              {7,8,9} };

    vector<int> vec2=spiral(vec);
    cout<<"Spiral Print: "<<endl;
    for(auto i:vec2)
        cout<<i<<" ";                       
    
    return 0;
}