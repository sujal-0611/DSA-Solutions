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

void mov1(vector<int> &vec)
{
    //brute force- using swap logic
    int n=vec.size();
    int count =0;
    for(int i=0;i<n ;i++)   //first counting no. of zeros
    {
        if(vec[i]==0)
            count++;
    }

//what we are doing here is if at some index zero is found then swap it with next element , and keep 
// doing so  that the zero will be eventually placed at last index
//and if there are multiple zeros then run that process(loop) for than no of zeros
//for ex: v-> 1,0,3,4 ... for i=0 if(1 == 0) then swap here if condtion is false
// for i=1 if(0 == 0)..its true then swap it with next element, the vector is now v->1,3,0,4
//for i =2 if(0 == 0)...again true (bASIcally once we found a zero we are swapping it with next element
//  so on next iteration we will find zero for sure, untill loop ends)....and so on till count(no of zeros)

    for(int j=0;j<count; j++)
    {
        for(int i=0;i< n-1 ;i++)    
        {
            if(vec[i] == 0)
            {
                swap(vec[i],vec[i+1]);
            }        
        }
    }
    
}

void mov2(vector<int>& vec)
{
    int i=0,j=0;

    while(i < vec.size())
    {
        if(vec[i] != 0)
        {
            swap(vec[i],vec[j]);
            i++;
            j++;            
        }
        else    //if vec[i] is zero then just iterate i only keep j on that zero 
            i++;
    }
}
int main()
{   
    system("cls");
    vector<int> vec={2,0,1,0,3,12};

    cout<<"original array: ";
    print_arr(vec);

    //mov1(vec); //brute force
    mov2(vec); //2 pointer
    cout<<"after moving zeros: ";
    print_arr(vec);
    return 0;
}