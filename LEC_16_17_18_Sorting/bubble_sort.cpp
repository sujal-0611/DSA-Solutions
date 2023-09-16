#include<iostream>
#include<vector>
using namespace std;

void printarr(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;  
}

void bubble_sort(vector<int> &vec)
{
    int n= vec.size();
    //OPTIMIZED SOLution
    for (int i = 0; i < n-1; i++)       //for round 1 to n-1
    {
        bool swapped= false; //to check if all elements are already sorted or not if sorted then inner loop will run only one time
                            // and  swapped will remain false , in this case time Complex. is O(n)

        for(int j= 0 ; j< n - i-1 ; j++)  //as for ith round ith larget is placed as in next round we dont need to check for it ,so we reduce our range
        {       //we subtract 1 bcz if for last value i.e j= n th condition vec[j] > vec[j+1] ...there is no element at j+1, so we subtract 1
            
            if(vec[j] > vec[j+1])
            {   vec[j] = vec[j+1] +vec[j] - (vec[j+1] = vec[j]);    //another way to swap
                //swap(vec[j],vec[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;

    }
    
}
int main()
{   
    system("cls");
    
    vector<int> vec={6, 2 ,8, 4, 10};

    cout<<"Unsorted array :";
    printarr(vec);

    bubble_sort(vec);   // Bubble Sort
    cout<<"Sorted array : "; 
    printarr(vec);
    return 0;
}