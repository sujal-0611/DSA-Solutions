//CodeStudio: print like a wave
#include<iostream>
using namespace std;

void print_wave(int arr[][4])
{
    int row=0,col=0;
    while( col <4 )
    {
        if(col%2 == 0 )
        {   
            row=0; 
            while( row < 3 )
            {
                cout<<arr[row][col]<<" ";
                row++;
            }
        }
        else
        {
            row=2;
            while(row >= 0)
            {
                cout<<arr[row][col]<<" ";
                row--;
            }
        }
        col++;
    }
}
int main()
{   
    system("cls");
    int arr[3][4]={ {1 ,2 ,3 ,4},
                    {5 ,6 ,7 ,8}, 
                    {9 ,10 ,11 ,12} };

    int i=0,j=0;
    /*
    while(i<3)
    {
        j=0;
        while(j<4)
        {
            cout<<arr[i][j]<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    */

    cout<<" wave : ";
    print_wave(arr);
    return 0;
}