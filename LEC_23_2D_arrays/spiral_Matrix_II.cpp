#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> spiral(int n)
{   
        vector<vector<int>> vec(n, vector<int>(n,0));
        /*We create a 2D vector containing "n"elements each having the value "vector<int> (m, 0)".
            "vector<int> (m, 0)" means a vector having "m"  elements each of value "0".*/
       

        int i=0 ;   //start row
        int k=n-1;  //end row
        int l=0;    //start col
        int j=n-1;  // end col
        
        int count=0;
        int value=1;
        int total=n*n;
        
        while( count < total )  //till whole matrix is traversed
        {
            //starting row
            for(int index= l; index <= j and count<total ; index++)
            {
                vec[i][index]=value;
                value++;
                count++;
            }
            i++; //increment starting row(i.e make next row as starting row)
            
            //ending column
            for( int index= i; index <= k and count<total; index++)
            {
                vec[index][j]=value;
                value++;
                count++;
            }
            j--; //make previous Column as new Ending col
            
            //ending row
            for(int index= j; index >= l and count<total; index--)
            {
                vec[k][index]=value;
                value++;
                count++;
            }
            k--;    //make previous row as new ending Row
            
            //starting column
            for(int index = k ; index >= i and count<total; index--)
            {
                vec[index][l]=value;
                value++;
                count++;
            }
            l++;    //make next Column as new starting column
        }
        return vec;
}
int main()
{   
    system("cls");
    vector<vector<int>> vec=spiral(3);

    int i=0,j=0;
    while(i<3)
    {
        j=0;
        while(j<3)
        {
            cout<<vec[i][j]<<" ";
            j++;
        }
        i++;
        cout<<endl;
    }
    return 0;
}