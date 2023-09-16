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

    //2.now create 2 temporary arrays for storing each current block's element 
    int *first = new int[len1];
    int *second = new int[len2];

    //3.now copy each block's element into temp arrays we created
    
    for(int i=0; i< len1;i++)   //1st array
        first[i] = arr[start+i];

 
    for(int i=0; i < len2 ;i++) //2nd array
        second[i] = arr[mid+1+i];

    //4. Now merge 2 temp array into main array 'arr' (merge 2 sorted arrays) 
    int i=0,j=0;
    int main_array_index = start;
    while( i< len1 and j< len2)
    {
        if(first[i] <= second[j])
            arr[main_array_index++]=first[i++];
        else
            arr[main_array_index++]=second[j++];
    }

    //5.now pushing in remaining elements left over (due to one of the conditions being failed)
    while(i<len1)
        arr[main_array_index++] = first[i++];
    while(j<len2)
        arr[main_array_index++]= second[j++];

    //so now we merged 2 sorted arrays(i.e elements for 2 blocks)

    //6.delete dynamic temp arrays we created
    delete []first;
    delete []second;
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