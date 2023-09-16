//reverse alt element
//FIND UNIQUE ELEMENT
//leetcode unique occurence of element
//leetcode find the duplicate element
//leetcode find all duplicates in array
//code studio question :  find intersection of 2 arrays
//code studio's question : pair sums
//code studio's question : triplet sums
#include<iostream>
#include<climits>
#include<unordered_map>
#include<map>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

void alt_rev()
{
     int arr[6]={1,2,3,4,5,6};
    //fill_n(arr,10,4);   //also works for vector, for vector  fill_n(vector object.begin(),size(or range), value)
    
    int size=6;
    cout<<"original array is " ;
    for (int i  = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }

    for(int i=0 ; i<size ; i=i+2)   //works for both even and odd sizes
    {
        if((i+1) >= size)   //since range is from 0 to size-1 i.e for size:5 range is 0 to 4 so check if i+1>=5 then eak
            break;
        swap(arr[i],arr[i+1]);
    }
      cout<<"\nalternatively reversed array is ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void unique()
{
    int a[]={  6,9, 2, 2,6,2,7,8,7,8};
    int k=3;
    //int size=sizeof(a)/sizeof(a[0]);
    int size= (*(&a+1)-a);  //use it when only array is passed on to function not its size
    cout<<size<<endl;
  
    /* 
    //BRUTE FORCE works completely fine
    int num=INT_MIN,count=1;
    for (int  i = 0; i < size; i++)
    {
        count=1;
        for (int j = 0; j < size; j++)
        {
            if(a[i] == a[j] && i!=j)
                count++;
        }

        if(count==1)
           num = i;   
    }
    return a[num];
    */
 
    /* //love babber solution but not working correctly
    int ans=0;
    for (int i = 0; i < size; i++)
    {
      ans=  ans^a[i];
      cout<<" "<<ans;
    } */

    
    //correct solution using unordered map
    //a[]={  6,5, 2, 2,6,2,6};
    int ans=0;
     unordered_map<int,int>mp;

        cout<<mp[2]<<" "<<mp[5]<<" "<<mp[6]<<endl;
        for(int i=0; i<size ; i++)
        {
            mp[ a[i] ]++;
        }

        //nordered_map<int,int> :: iterator itr;
        //for ( itr = mp.begin(); itr != mp.end(); itr++)
        //{
            //cout<<(*itr).first<<" "<<(*itr).second<<endl;
        //}
        
        
        for(auto it:mp)
        {
            if(it.second==1)
            {
                ans = it.first;
                break;
            }
           // if(it.second%k!=0)
            //{
              //  ans= it.first;
             //   break;
          //  }
        }
        
    
    cout<<"\nUnique Element is "<<ans;
    

}

void uni_ocur()
{   
    vector<int> vec={3,1,5,2,3,5,5,2,2,5,3};
    unordered_map<int,int> mp; 
    //map<int,int> mp;    // use map if we want to the keys in order   

    /*first step: store vector elements in map, for each vector element the value will be incremented as it appear
    // for example if vec[1] = 2 so value is 1 but if later again 2 is encountered like vec[4]=2
     then  key will be the same(since 2 is a key and we are just find aggain the same key later on ) 
      but value will increment i.e value will be 2 */
    for(int i=0; i< vec.size();i++)
    {
        mp[ vec[i] ]++;         //key is number while value is their occurences
            
    }



    
    /*
    unordered_map<int,int>:: iterator itr;
    //map<int,int> :: iterator itr;
     //efficent solution using hashset i.e unordered_set
    unordered_set<int> st;
    cout<<"element  |  its Occurence"<<endl; 
    for (itr= mp.begin() ; itr!= mp.end(); itr++)  
    {
        cout<<"   "<<(*itr).first<<"\t \t "<<(*itr).second<<endl;     //printing map elements (just for visualisation)
        st.insert( (*itr).second );
    }
    */

   //another way (NOT TO USE ITERATOR)
   unordered_set<int> st;
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        st.insert(i->second);
    }
   
    //now checking if every occurence is unique or not 
    //we will make use of property of set that it store unique elements only, if there is duplicate then it wont store it
    // here if the size of map is  equal to size of set then all occurence is unique otherwise it is not
    
    if(mp.size() == st.size() )
        cout<<"all occurences are unique";
    else
        cout<<"all occurences are not unique";

}

void duplicate()
{
    vector<int> vec={4,2,3,3,1};

    //using sum approach not work for case like vec={ 2,2,2,2}
    // i.e first find sum of all elements in vector
    // next we know that vector has n+1 element but  stores from 1 to n with one number is repeated hence
    // size is n+1 , theen we find the sum of n elements i.e 1+2+3+4....+n
    //then subtract both sums we will get our answer
    /*
    int sum=0;
    for(auto i:vec)
    {
       sum=sum+i;  
    }
    cout<<endl;
    int sum2=0;
    for(int i=1 ; i<=vec.size()-1; i++)
    {
        sum2=sum2+i;
    }
    cout<<sum<<" "<<sum2;
    */
    //sort approach 
    /*
    int ans=0;
    sort(vec.begin(),vec.end());
    
    for(int i=0; i< vec.size()-1 ;i++)
    {
        if(vec[i] == vec[i+1])
        {    ans=vec[i];
            break;
        }
    }
    cout<<"\n duplicate element is "<<ans;
    */

    //unordered map approach( but here for some reason both time and space complexity is large)
    /*
    int ans=0;    
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++)
    {
        mp[ arr[i] ]++;
        if(mp[arr[i]]>=2)
            ans=arr[i];
    }
	 return ans;
     */

    //Bit manipulation (not working)
    
    int ans=0;
    for(int i=0; i < vec.size();i++)
    {
        ans=ans^vec[i];     //phle  saare elements ko xor kr do ek dusre ke sath
    }
    for(int i=1 ; i<vec.size();i++)
    {
        ans=ans^i;   // now jo answer hoga xor krne bad usko 1-n-1 tak xor kr do
    }
    cout<<"duplicate element is "<<ans;
    

        
}

void dup_all()
{
    vector<int> nums={6,4,8,4,2,6}; // here 4 and 6 are 2 times 
    vector<int> vec; 
    
    //brute force
    /*
    int count;
    unordered_set<int> st;
     for(auto i:nums)
    {
         count=0;
        for(auto j:nums)
        {
            if(i==j )
            {
                count++;
                if(count >= 2 )
                {
                    st.insert(i);    
                }
            }
        }
    }
    cout<<endl;
    for(auto i:st)
    {
        vec.push_back(i);
    }
    cout<<"Duplicate elements are : ";
    for(auto i:vec)
    {
        cout<<i<<" ";
    }
*/

    //unordered_map approach
    /*
    unordered_map<int,int> mp;
    for(auto i:nums)
    {
        mp[i]++;
    }
    for (auto i=mp.begin(); i!=mp.end() ; i++)  //with auto we dont need to use iterators
    {
        if(i->second >=2)
            vec.push_back(i->first);
    }
    
    cout<<endl;
    for(auto i:vec)
    {
        cout<<i<<" ";
    }
    */

   //BEST SOLUTION
    vector<int> vec2(vec.size()+1,0);
    vector<int> vec3;
    for (int  i= 0;  i< nums.size(); i++)
    {
        if(vec2[nums[i]])
        {
            vec3.push_back(nums[i]);
        }
        else
            vec2[nums[i]]=1;
    }
    
    for (int i = 0; i < vec3.size(); i++)
    {
        cout<<vec3[i]<<" ";
    }
    

}

void arr_intersection()
{
    vector<int> arr1={ 1 ,2 ,2 ,2, 3, 4};
    //vector<int> arr1={ 1 ,2,3};
    vector<int> arr2={2, 2, 3, 3};
    //vector<int> arr2={3,4};
    vector<int> vec;

    /* Brute force (works, but not good) 
    for(auto i:arr1)
    {
        for(auto j=0;j<arr2.size();j++)
        {
            if(i==arr2[j])
            {
                vec.push_back(arr2[j]);
                arr2.erase(arr2.begin()+j);
                break;
            }
        }
    }
    */

    //brute force for leetcode variant (works)
    /*
     unordered_set<int> st;
    
        //brute force and used hashset since we want unique element only
     for(auto i:arr1)
    {
        for(auto j=0;j<arr2.size();j++)
        {
            if(i==arr2[j])
            {
                st.insert(arr2[j]);
                arr2.erase(arr2.begin()+j);
                break;
            }
        }
    }
    for(auto i:st)
            vec.push_back(i);
    return vec;

    */


    //2 POINTER APPROACH    
    //IN QUESTION it is given that 2 arrays are sorted , we will make use of that with 2pointer approach
    /*this approach can be used in leetcode variant too but first we need to sort given 2 
        arrays */
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]==arr2[j])
        {    
            vec.push_back(arr1[i]);
            i++;j++;
        }
        else if(arr1[i]>arr2[j])
            j++;
    }

    cout<<"INTERSECTION OF 2 ARRAYS are\n";
    for(auto i:vec)
    {
        cout<<i<<" ";
    }
}

void pair_sum()
{
    //vector<int> vec={1,2,3,4,5};
    vector<int> vec={2, -6, 2, 5, 2 };
    vector< vector<int> > vt;
    int s=4;
   
   for(int i=0;i<vec.size() ; i++)
    {
        for(int j=i+1; j<vec.size(); j++)
        {   
            
            if( ( vec[i]+vec[j]==s ))
            {
                 vector<int> temp;
                temp.push_back( min(vec[i],vec[j]) );
                temp.push_back(max(vec[i],vec[j]) );      
                vt.push_back(temp);  

            }
           
        }
       
    } 
    sort(vt.begin(),vt.end());   

    for(int i=0; i<vt.size() ; i++)
    {
        for(int j=0; j<vt[i].size();j++)
        {
            cout<<vt[i][j]<<" ";
        }
        cout<<endl;
    }
    /* 2D vector
    //****in case question ask us to return the vector then make 2 dimentional vector(like 2D array)
    
    for(auto i=mp.begin(); i!=mp.end() ; i++) 
    {
        vector<int> temp;
        temp.push_back(i->first);
        temp.push_back(i->second);      
        vt.push_back(temp);             //THAT"S HOW 2D VECTOR
    }
    */
}



int main()
{   
    system("cls");


    //alt_rev();
    //unique();
    //uni_ocur();
    //duplicate();
    //dup_all();
    //arr_intersection();
    //pair_sum();
    

    return 0;
}