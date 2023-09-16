#include<iostream>
using namespace std;
void print_arr(int* arr,int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

//to place pivot in its place, then rearrange elements like smaller ele < pivot < larger ele, and then return pivot_index
int partition(int* arr,int s,int e)
{
    int pivot = arr[s];
    int count=0;
    for(int i=s+1; i <=e ;i++)  //for range s to e
    {
        if(arr[i]<=pivot)   //count all the elements that are smaller than pivot
            count++;
    }

    int pivot_index=s+count;

    //now position pivot accordingly
    swap(arr[s],arr[pivot_index]);  //as arr[s] was our pivot
    

    //now rearrange elements such that all elements to the left of pivot are smaller than pivot and
    //all elements to the right of pivot are larger than pivot
    // i.e smaller elements < pivot < larger elements

    int i =s, j=e;
    while(i < pivot_index and j > pivot_index )
    {
        while( arr[i] <= pivot) //if that particular element is smaller than pivot 
            i++;
        while(arr[j] > pivot)   //if that particular element is larger than pivot
            j--;
        
        //now even after two inner loops , it means there are elements in wrong place so swap them
        if(i < pivot_index and j > pivot_index)
            swap(arr[i++],arr[j--]);
    }

    return pivot_index; //returning index of pivot, so that partition can be made accordingly
}

//recursive function to sort array 
void sort(int* arr,int s,int e)
{
    if(s>=e) return;    //BC

    int pivot_index = partition(arr,s,e);   //getting where partition is happened

    sort(arr,s,pivot_index-1);  //then do the same(i.e sort) for left side and 
    sort(arr,pivot_index+1,e);  //and right ide
}

void quick_sort(int* arr,int n)
{
    sort(arr,0,n-1);    //call to recursive function
}
int main()
{   
    system("cls");
    int arr[]={6, 6 ,-6 ,-2 ,-4, -6, 2, -6 };
    int n=sizeof(arr)/sizeof(arr[0]);

    print_arr(arr,n);
    quick_sort(arr,n);
    print_arr(arr,n);
    return 0;
}