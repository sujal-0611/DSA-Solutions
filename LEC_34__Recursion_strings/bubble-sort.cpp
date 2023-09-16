//bubble sort,selection sort,insertion sort - Recursively
#include<iostream>
#include<vector>
using namespace std;
void print_arr(vector<int> vec)
{
    for(int i:vec)
        cout<<i<<" ";
    cout<<endl;
}

void print_arr2(int* arr,int N)
{
    for(int i =0; i<N;i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}
//void bubble_sort(int *arr,int n)  //for static arrays and its size 'n'
void bubble_sort(vector<int>& vec,int i)
{
    if(i > vec.size()-1)    //Base case for vectors (when vector and i=0 is passed for first time)
        return;
    //if(n==0 ||n == 1)    //base case for arrays Not vectors(static array and its size is passed)
       // return;

    bool swapped =false;

    //for(int j=0; j< n-1;j++)  //****for static arrays (when static array and its size 'n' is passed)

    for( int j =0; j< vec.size()-i-1; j++)  //solving 1 case putting largest element in its place
    {
        if( vec[j] > vec[j+1])
        {
            swapped = true;
            swap(vec[j] , vec[j+1]);
        }
    }
    if( swapped == false)   //if array is already sorted then instead of recursive call simply go back to main()
        return ;
    
    //bubble_sort(arr,n-1);   //for static arrays (when static array and its size 'n' is passed), after placing largest in last place reduce 'n' by 1 
    bubble_sort(vec,i+1);   //let recursion handle rest cases(rounds)
}

void selection_sort(int* arr,int i,int n)
{
    if(i > n)    //base case - sorted( size is reduced to 0 or 1 i.e sorting is finished)
        return;
    
    int pos =i;
    for(int j = i+1; j< n;j++)      //solving 1 case(round)
        if( arr[pos] > arr[j] )
            pos =j;
        
    swap(arr[pos],arr[i]);

    selection_sort(arr,i+1,n);      //let recursion handle rest of the cases(rounds)
    
}

void insertion_sort(int *arr,int i , int n)
{
    if ( i >n)  return;

    int temp = arr[i];
    int j=i-1;
    for( ;j>=0;j--)        //from line 66 to 75 : solving for 1 case(round)
    {
        if( arr[j] > temp)
            arr[j+1] = arr[j];
        else
            break;
    }
    arr[j+1] = temp;

    insertion_sort(arr,i+1,n);  //let recursion handle rest of cases(rounds)

}
int main()
{   
    system("cls");
    vector<int> vec = {10,0,7,6,14,9};
    int arr[] = {10,0,7,6,14,9};
    int N = *(&arr+1)-arr;

    
    print_arr2(arr,N);
    //bubble_sort(vec,0);
    //bubble_sort(arr,N);
    //selection_sort(arr,0,N);
    insertion_sort(arr,0,N);
    print_arr2(arr,N);
    return 0;
}