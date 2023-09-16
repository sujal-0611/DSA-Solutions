#include<iostream>
using namespace std;

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
long long int BS_recur(long long int start,long long int  end,long long int  n)
{   
    long long mid = start + ((end - start)/2);

    if( start > end)    //BC1
        return end; //BC is bit different bcz we still need to return closest sqrt number ,even if 'n' is not a perfect square
    
    if(mid*mid == n )    //&& ((mid + 1) * (mid + 1) > n) )    //BC 2
        return mid;
    else if ( mid*mid > n)
        return BS_recur(start,mid-1,n);
    else
        return BS_recur(mid+1,end,n);

}
double  sqrtt(long long int n)
{
    int ans= BS_recur(0,n,n);
    return precision(n,3,ans);
}
int main()
{   
    system("cls");
    long long n;
    cout<<"Enter the number"<<endl;
    cin>>n;
   
    cout<<"Floor value of square root of "<<n<<" is: "<<int(sqrtt(n))<<" and full ans is: "<<sqrtt(n);
    
    return 0;
}