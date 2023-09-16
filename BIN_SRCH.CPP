//BINARY SEARCH Lec 12 and 13
//Ques 1.Code studio First and Last Position of an Element In Sorted Array
//Ques 2. 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//concept of binary
void bin()
{
    int arr[]={1,3,5,6,7,9,78,244};
    int n=sizeof(arr)/sizeof(*arr); //size
    
    cout<<"ENter the no to search for \n";
    int a;
    cin>>a;

    int s=0,e=n-1,m=0;
    int pos=0;
    
    while(s <= e)
    {
        m=e-((e-s)/2);  //or m=s+ ((e-s)/2)
        if(a==arr[m])
        {
            cout<<"Number found at "<<m+1;
            pos=1;
            break;
        }
        else if(a>arr[m])
            s=m+1;
        else
            e=m-1;
    }
    if(pos==0)
        cout<<"Number is not present in given array";
}

//Ques 1.
int bin_srch(vector<int> &,int ,string);   //function prototype to used for question 1 inside first_and_last() function
void first_and_last()
{
    vector<int> vec={4,8};
    int first=0,last=0;
    int target=4;

    //brute force approach
    /*
    int temp=vec.size()-1;
    int count=0,count2=0;;

    while(temp>=0)       //fist count total occurences
    {
        if(target==vec[temp])
        {
            count++;
        }
        temp--;
    }
    
    cout<<count<<endl;
    for(int i=0; i< vec.size(); i++)    //now finding first and last occurences
    {
        if(target == vec[i] )
        {   count2++;
            if(count2==1)
                first=i;

            else if(count2==count)
                last=i;
            
        }
    }
    if(count==1)    //if there is single element then both first and last will point to same
        last=first; //as at 1st first will get the location

    cout<<"index of first target is "<<first<<" and index of last target is "<<last;
    */

   // more optimised approach (2 pointer approach)
   /*  start from starting point and start from ending point as well the moment we encounter our target from both end , terminate loop and print or return the answer
   int count1=0,count2=0;   //count for overall target count in array
   int i=0,j=vec.size()-1;

    for(int i=0, j=vec.size()-1; i<vec.size(), j>=0; i++, j--)
    {
        if(vec[i]==target && count1==0)
        {
            first=i;
            count1++;
        }
        
        if(vec[j]==target && count2==0 )
        {   
            last=j;
            count2++;
        }

        if(count1 !=0 && count2 !=0)
            break;
    }
     cout<<"index of first target is "<<first<<" and index of last target is "<<last;

*/

    //BINARY SEARCH APPROACH

    first=bin_srch(vec,target,"first"); //called to find first occurence
    last=bin_srch(vec,target,"last");   //called to find last occurence

    cout<<"index of first target is "<<first<<" and index of last target is "<<last;

    // pair<int,int> p;     for question in leetcode where we need to return pair
    //p.first=bin_srch(vec,target);   // 1st will be called to find first occurence
    //p.second=bin_srch(vec,target);  // 2nd will be called to find last occurence
    //return p;    /returning a pair object
   
}
//binary search function for use in Question 1 of codestudio /leetcode
int bin_srch(vector<int> &vec,int target,string str)
{
    int ans=-1;
    int start,mid,end;
    start=0; end=vec.size()-1;
    mid=start+((end-start)/2);

    while (start <= end)
    {   
        mid=start+((end-start)/2);

        if(vec[mid] == target)
        {
            ans=mid;
            if(str =="first")   //we need to functions to write one for first occ, second one for last occ , but instead of doing that
                end= mid-1;     // i also passed string ,so if fucntion is for first the conditon will be this else.....
            else if(str == "last")   
                start=mid+1;    //....if the fucntion is for last occ. then condtion will be this
        }
        else if(target > vec[mid])
            start=mid+1;

        else      //  target < vec[mid] 
            end=mid -1;     
    }       
    return ans;  
}

//Ques 2.
void peak_index()
{
    int arr[]={1,2,4,3,0};
    int ans;
    int n=sizeof(arr)/sizeof(*arr);

    //Linear approach
    /*
    int i=0,index;
    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {   
            index= i;
            break;
        }
        i++;
    }
    cout<<index;
    */

   //Binary search approach
   int s=0,e=n-1,mid=s+(e-s)/2;

   while(s<e)
   {                                        //dry run 
        mid=s+(e-s)/2;                     // arr[] = { 7,8,9,10,5,4,3}    n=7   if(10 >5)  e=4; m=1  if(8<9) s= 2 ; m= 2 if(9<10) s=3 ; m=3 if(10>5) e=3; s<e= false(s=3,e=3)
        if(arr[mid]<arr[mid+1])             //hence s/e/mid has index of largest number .
            s=mid+1;
        
        else    //of arr[mid]> arr[mid+1]
            e=mid;
   }
   cout<<"index of PEAK OF MOUNTAIN IS "<<s;    //preferring to use 's'
}


int main()
{   
    system("cls");
    //bin();
    //first_and_last();
    //peak_index();
    
    return 0;
}