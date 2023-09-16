//count(product) of primes in L,R range
//we wiill use segmented sieve approach
//code is working but showing TLE on GFG- Product of prime
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> gen_primeR(int R)
{
    //Sieve of eratosthenes
    vector<bool> prime(R+1,true);
    prime[0]=prime[1]=false;

    for(int i=1; i*i<=R; i++)   //till sqrt(R)
        if(prime[i])
            for(int j=i*i; j<=R;j=j+i)
                prime[j] = false;

    vector<int> vec;    
    for(int i=0; i<R; i++)
        if(prime[i])
            vec.push_back(i);

    return vec;

}
int main()
{   
    system("cls");
    int t;  //testcases
    cin>>t; 
    long long L,R;
    while(t--)
    {
        cin>>L>>R;
        //STEP 1. generate prime numbers till R (loop run till sqrt(R))
        vector<int> primes= gen_primeR(R);
        
        //from here on we are working on segment  but applying seive only that is why whole approach is called "segmented sieve"
        //STEP 2: create a dummy vector of size R-L+1 and mark all true 
        vector<bool> dummy(R-L+1,true);

        //STEP 3: mark multiples of primes( generated in step 1) as false
        for( auto pr:primes)   //for each prime no. stored in primes vector (step 1)
        {  
            int firstmultiple= ( (L/pr) * pr);   //to get First multiple for current prime number in range L,R

            if(firstmultiple < L)
                firstmultiple += pr;

            for( int j = max(firstmultiple, pr*pr); j<=R; j=j+pr)  //now just marking mulitples of each prime as false(note here we are working based on number not index)
                dummy[j-L] = false;    //j-L to map the number to index i.e for prime number 'j',  mark j-Lth index in dummy vector as false                         
        }

        if( L==0)       //base case if Lower limit is 1
            dummy[0]=dummy[1]= false;
        else if( L ==1)     //base case if lower limit is 0
            dummy[0]= false;

        int count=0;
        long long product=1;
        for(auto i:dummy)
            cout<<i<<" ";
        cout<<endl;
        //STEP 4: get all prime numbers in range L,R from dummy vector
        //(as now only those elements would be remained true that were mapped to prime numbers in range L,R )
        for(int i=L; i<=R;i++)
        {
            if(dummy[i-L] == true)  //mapping for indexes ex: for i=L dummy[i-L] would be dummy[L-L] = dummy[0], so L is mapped with index 0
            {
                count++;        //counting no of prime numbers
                cout<<i<<" ";   //printing prime numbers in range L,R
                product*=i;     //finding product of all prime numbers- GFG Question
            }
        }

     cout<<"\ncount is "<< count<<endl<<"and product of all primes is "<<product;
    }
    
    return 0;
}