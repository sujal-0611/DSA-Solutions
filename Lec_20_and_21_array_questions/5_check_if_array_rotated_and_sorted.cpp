//Leetcode
#include<iostream>
#include<vector>
using namespace std;

bool sorted_rotated(vector<int>& vec)
{
    //here the idea is we use property of sorted array that the element is always smaller that the next element
    //( vec[i] is smaller than vec[i+1]) and only one time is that previous element is bigger than next element
    // (i.e the case is last element will be obviously bigger than next element which is first element)
    //so if only one such pair exist (Where vec[i]> vec[i+1] then that array is sorted and rotated)

    int count =0; //to keep the count of such pairs
    int n= vec.size();

   
    //we have to check last and first separately as we cant check them in loop(by loop logic) also
     // for case: if array is  sorted but not rotated(or rotated by 0 steps) 
    if(vec[n-1] > vec[0]) //then biggest element would be at last index and smallest at 0th index  
    {
        count++;    //then iterate the count , i.e record occurance of that pair 
    }

    for(int i=0; i<n-1 ; i++)   //even if  above condtion is true we still need to check more such possible pairs
    {
        if(vec[i] > vec[i+1])   //if current element is greater than next element(possible that array is not sorted)
            count++;        //then record its occurance 
        
        if(count>1)
            return false;   //if count>1 then immediately return false as for array to be sorted and rotated
                            //the count must be 1 only
    }
    //  **for case={1,1,1} the count will be  zero but array is still sorted and rotated so that is why if count is <=1 then return 1
    return true;   
}
int main()
{   
    system("cls");
    vector<int> vec={6,5,1,2,3};

  
    if(sorted_rotated(vec))
        cout<<"The given array is sorted and rotated";
    else
        cout<<"the Given array is not sorted and rotated";
       
    return 0;
}