//****IMP - MERGE SORT - RECURSIVELY - Codestudio
#include<iostream>
using namespace std;

void print_arr(int* arr,int N)
{
    for(int i =0; i<N;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}

//storing elements from 2 blocks int arrays then merging those 2 arrays into main array
void merge(int *arr,int start,int end)
{ 
    int mid = start +((end-start)/2);

    //1.first get length for each current block
    int len1 = mid-start +1;
    int len2 = end-mid;

    int i = mid-1, j =end;
    while( i>start && j>mid)
    {
        if(arr[i] >=arr[j])
            swap(arr[j--],arr[i--]);
    }
}

//Recursive function to generate blocks of elements and then merge then into sorted manner
void sort(int* arr,int start, int end)
{
    int mid = start + (end-start)/2;    //divide current array into 2 parts (array from start index to end index)
    
    if( start >= end)    //Base case
        return ;    
    
    //expand(divide) left part of array(like tree)
    sort( arr,start,mid);

    //after expanding(getting) left side fully ,now expand on to right side of array( like right child of tree)
    sort(arr,mid+1,end);


    //after getting both left and right side of arrays separately, now merge 2 blocks (as at first a(fter dividing till theres nothing left to divide)
    //there's a individual element only on each block) like we merge 2 sorted arrays(we need temporary arrays to do that)
    //**for first merge even block is individual element so every block  is sorted(single element block is always sorted)
    //**we just keep on merging 2 sorted blocks( blocks we get from previous recusrive call in stack)
 
    merge(arr,start,end);  
    
}

void merge_sort(int* arr,int n)
{
    sort(arr,0,n-1);    //call to recusrsive function 
}

int main()
{   
    system("cls");
    int arr[]= {4,1,2,9,8,3};
    int n= sizeof(arr)/sizeof(arr[0]);

    print_arr(arr,n);
    merge_sort(arr,n);
    print_arr(arr,n);
    return 0;
}