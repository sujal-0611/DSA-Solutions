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

//O(n) solution but using extra space
void rotate1(vector<int>& vec,int k)    
{
    int n=vec.size();
    vector<int> vec2(n);

    for(int i=0; i< n ;i++)
    {
        vec2[(i+k)%n]= vec[i];
    }
    vec=vec2;

    
}

//Using Reverse logic - no extra space
void rev(vector<int>& vec, int start, int end)
{   
    while(start <=end)
    {
            vec[start] = vec[end] + vec[start] - ( vec[end] = vec[start]);  //swapping of two numbers

            start++;
            end--;
        }
}
void rotate2(vector<int>& vec, int k)
{
    int n=vec.size();
    
    rev(vec,0,n-1);   //first reverse whole array

    //now divide array between 2 subarray and breaking point will k
    //and re-reverse them separately
    rev(vec, 0,k-1);  //from 0th index to k-1th index
    rev(vec,k,n-1);    // from kth index to n-1th index   
    
}
int main()
{   
    system("cls");
    vector<int> vec={1,2,3,4,5,6,7,8};
    int k=3;
    
    cout<<"Original array: ";
    print_arr(vec);

    //rotate1(vec,k);   //Using extra space
    rotate2(vec,k);
    cout<<"after rotated to right by "<<k<<" is: ";
    print_arr(vec);
    return 0;
}