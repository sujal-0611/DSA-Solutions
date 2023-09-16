#include<iostream>
#include<vector>
using namespace std;

void pivot()        //this find the pivot element question (not a binary search question)
{
    vector<int> vec={2,1,-1};


    //Brute force with complexity of O(n)

    int rsum=0;
    int pivot=-2;   //can be any negative number(or INT_MIN) except -1 (also 0 cant be assigned here)
    int lsum=0; //going to use in  2nd loop to calculate relative sum 

    for(auto i:vec)     //simply going to sum of  all elements(also taking total sum as rsum for now)
    {
        rsum=rsum+i;      
    }
    
    rsum=rsum-vec[0];     /*one case : if pivot is first element , i.e to left of pivot is nothing i.e sum is 0 
                    also sum of all elements to right of first element is zero then first element is pivtot*/

    if(rsum == 0)    //checking if sum is zero (we excludes the element (on which we are checking left sum and right sum ) from total sum
    {
        pivot = 0;
        goto start; // i.e if first element is pivot then skip the following code and print the answer (or just return 0(th index ) here only
    }


    for (int i = 1; i < vec.size(); i++)  // starting from 1st index since for zero we already checked above 
    {
        //mechanishm to calculate rsum and lsum (but excluding the element on which loop currently is ,so if rum==lsum then that element )
        // can be treated as pivot )

        lsum=lsum+vec[i-1];     //getting left sum here
        rsum=rsum-vec[i];           //getting right sum by subtracting current element from overal sum
        cout<<lsum<<" "<<rsum<<endl;
        if(lsum == rsum)    //if rsum equal to lsum (excluding element on which loop currently is )
        {
            pivot=i;
            break;
        }
    }
    start:  //jump here for case in which first element is pivot
    cout<<"Pivot is at index:"<<pivot<<" and pivot element is "<<vec[pivot];

}

//find a integer in a sorted and rotated array
void rotated_arr()
{
    vector<int> vec= {10 ,1 ,2 ,5 ,6};
    int k=10, pos=-1; // pos is position of integer 'k'

    int s=0,e=vec.size()-1;
    int mid;
    int pivot=-2;

    while(s<e)     //***finding pivot in sorted and rotated array
    {
        mid= s + ((e-s)/2);

         //we are taking vec[0] bcz if mid element is greater than element at 0th index then mid  on left side of pivot 
         // and we move start index forward
        if( vec[mid] >= vec[0])     
            s = mid +1;
        
        else    // if mid element is smaller that element at 0th index then mid is on right side of pivot and we move end index back
            e = mid; 

    }
    

    pivot = s;
    //**pivot we found is inclusive to right side of pivot


    //now we will do binary search for both side of pivot to find integer 'k'
    s=0;
    e= pivot-1; // for right of pivot

    //finding whether 'k' is present in right side of pivot or not
    while(s<=e) 
    {
        mid = s+ ((e-s)/2);
        if( vec[mid] == k)
        {
            pos= mid ;
            break;
        }
        else if ( k < vec[mid])
            e= mid-1;
        else
            s= mid +1;
    }
    if( pos!=0)
    {
        cout<<" Integer "<<k<< " is found at index "<<pos;
        exit(0);
    }

    s=pivot;    // for left side of pivot
    e= vec.size();

    while(s<=e)
    {
        mid = s+ ((e-s)/2);
        if( vec[mid] == k)
        {
            pos = mid;
            break;
        }
        else if ( k < vec[mid])
            e= mid-1;
        else
            s= mid +1;  
    } 

    //return -1; //if k is not found anywhere

    cout<<" Integer "<<k<< " is found at index "<<pos;
    
}


double precision(int num, int p,int sqrt_int)
{
    double factor=1,ans= sqrt_int;

    for(int i =0; i< p ; i++)
    {
        factor = factor/10;

        for( double j = ans; j*j <= num; j= j+factor)
        {
            ans=j;
        }
    }
    return ans;
}
int sqrt()
{
    //we use binary search logic...how? as sqrt of integer n will lie between 0 to n only . i.e 0 to n is a monotonic function
    long long int n = 7;

    long long int s=0, e= n;  
  //as n is long long so to work with it we need long long type only,
  // while calculating mid ,start or end , large number can be assigned to them during calculations
    long long int mid;
    int  ans =0;
    while(s<=e)
    {
        mid = s + ((e-s)/2);
        if( (mid* mid) == n )       //if mid*mid == n then it mid is a sqrt of n 
        {
            ans = mid;
            break;
        }
        else if (mid*mid >  n ) 
            e = mid -1;
        else
        {
            ans=mid;
             s= mid +1;
        }
           
    }
     //else if perfect match is not found return closest number
    cout<<"floor value square root of "<<n<<" is "<<ans<<"\nprecise value is : "<<precision(n,3,ans);  //precision(org_no,precision point, closest number)
    //cout<<e;     //e is the closest answer when given number is not a perfect square
    
}
int main()
{   
    system("cls");
    
    //pivot();
    //rotated_arr();
    sqrt();
    return 0;
}