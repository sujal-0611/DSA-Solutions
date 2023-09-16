//Insertion Sort
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

void insert_sort1(vector<int> &vec)
{
    int n= vec.size();

     // I am not starting with 0th index into account as well ,as we can treat 0th index sorted , so  we can also start 
     //for loop as : for(int i = 0 ; i< n ; i++) ...starting from 0th index for comparisions
    for (int i = 1; i < n; i++)   //for n rounds
    {
        int temp = vec[i];
        int j=i-1;
        for ( ; j >=0; --j)
        {
            // for ex: for 2nd index of i then j=i-1 i.e  j=1 -: temp < vec[1] i.e 11<12
           
            if(temp < vec[j])    
            {    vec[j+1] = vec[j];   //  11< 12 then push vec[1](12) to vec[2](11) (as  vec[2] temporarily stored in temp)
                // pushing elements (i.e pushing 12 to 11's index and if on next iteration of j i.e j =0 
                // temp < vec[0] : 11 < 13 - again true then push 13 as well (push 13 to next index )
            }
            else  
            {   
                //i.e as left side is sorted. if ith element is not smaller than jth element then 
                //its obvious it will be not smaller than elements before j (j-1, j-2....0) , so break it
                break;
            }    
        }   
        //after placing all elements till ith index, place value stored in temp  to the last value of j+1
        //(as j has index of the place last time condition of if statement was true in inner loop )
        vec[j+1] = temp;
    }   
}

void insert_sort2(vector<int> &vec)
{
    int n = vec.size();
    int i=1;

    while(i <n)
    {
        int temp=vec[i];
        int j= i-1;
        while(j>=0)
        {
            if(temp < vec[j])
                vec[j+1] = vec[j];
            else
                break;
                
            --j;
        }
        vec[j+1]= temp;
        ++i;
    }
}
int main()
{   
    system("cls");
    vector<int> vec={13,12,11,20,2,6};

    cout<<"Unsorted array :";
    printarr(vec);

    //insert_sort1(vec);   // insertion Sort with for loop ( bad practice)
    insert_sort2(vec);  //insertion sort with while loop (good practice)
    cout<<"Sorted array : "; 
    printarr(vec);
    
    return 0;
}