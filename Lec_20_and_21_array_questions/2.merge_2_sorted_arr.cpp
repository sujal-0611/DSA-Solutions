//Merge 2 sorted array
#include<iostream>
#include<vector>
using namespace std;
void print_arr(vector<int>& vec)
{
    int n= vec.size();
    int i=0;
    while(i < n)
    {
        cout<<(vec[i])<<" ";
        i++;
    }
    cout<<endl;
}

void print_arr2(int *arr,int size)
{
    for(int i =0; i< size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//leetcode variant
void merge_2sort_arr(vector<int>& vec1,vector<int>& vec2)
{
    int n =1;
    int m= vec2.size();

    int k =vec1.size()-1;

    int i =n-1,j=m-1;
    while( j>=0)
    {
        if(i>=0 && vec1[i] >= vec2[j] )
        {
            vec1[k] = vec1[i];
            i--;
            k--;
        }
        else
        {
            vec1[k] = vec2[j];
            j--;
            k--;
        }
    }

   
    print_arr(vec1);
}

//gfg variant - NOT WORKING 
void merge_2sort_arr2(int *arr1,int *arr2,int n,int m)
{

    int i=n-1,j=m-1;
    int k = m+n-1;
    print_arr2(arr1,n);
    print_arr2(arr2,m);

    while (k)
    {
        if( arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            j--;
            
            k--;
        }
        else
        {
            j--;
            k--;
        }
    }
    print_arr2(arr1,n);
    print_arr2(arr2,m);

}
int main()
{   
    system("cls");
    //for leet code variant (having extra capacity and using vectors)
    vector<int> nums1= {2,0};
    vector<int> nums2= {1};

    //for GFG having static arrays and no extra capacity
    int arr1[]={1 ,3, 5 ,7};
    int arr2[]={0, 2, 6, 8, 9};
    int n= *(&arr1+1) - arr1;
    int m= *(&arr2+1) - arr2;

    merge_2sort_arr(nums1,nums2);
    //merge_2sort_arr2(arr1,arr2,n,m);
    
    return 0;
}