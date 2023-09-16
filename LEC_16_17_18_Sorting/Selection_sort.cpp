//Selection Sort
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void printarr(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;  
}

//SELECTION SORT with O(n^2)
void select_sort(vector<int> &vec)
{
    for(int i =0; i < vec.size()-1; i++ )
    {
        int pos=i ;    //currently treating ith element as shortest 
        for(int j= i+1; j< vec.size(); j++)     //since we are taking ith element as shortest ,we gonna run loop from i+1 to compare other element with pos(current-smallest)
        {
            if(vec[pos] > vec[j])
            {
                pos=j;
            }       
        }
        swap(vec[i], vec[pos]);
        
    }
   
}
int main()
{   
    system("cls");
    vector<int> vec={6, 2 ,8, 4, 10};

    cout<<"Unsorted array :";
    printarr(vec);

    select_sort(vec);   // selection sort 
    cout<<"Sorted array : "; 
    printarr(vec);
    
    return 0;
}