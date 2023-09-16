#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<climits>
using namespace std;

void printarr(vector<int> &arr)
{
    cout<<endl;
    int b=0;
    int sizee = arr.size();
    while(b<sizee)
    {
        cout<<arr[b]<<" ";
        ++b;   
    }
    cout<<endl;
}
void uni(vector<int> arr,int size)
{
//Brute Force
/*
 {
    for(int i=0; i<size; i++)
    {   
        int count=1;
        for(int j=0; j<size; j++) //5 3 1 5 1 3 4 7 4 8 8 
        {
            if(arr[i] == arr[j] && i!=j)
            {    
                count=0;
                break;
            }
        }
        if(count == 1)
        {    cout<<"unique ele is: "<<arr[i];
            break;
        }
    }
 }
 */
       
//optimized 
/*
    unordered_map<int,int> mp;
    for(int i=0 ;i<size; i++)
    {
        mp[arr[i]]++;
    }

    for(auto it:mp)
    {
        if(it.second == 1)
        cout<<it.first;
    }
*/


    //Best (Xor solution)
    int b=arr[0];
    for(int i=1; i<size; i++)
    {
        b=b^arr[i];
    }
    cout<<b;

}

void dup(vector<int> &vec)
{
    int n=vec.size();
    int a=0;
    for(int i=0;i<n;i++)
    {
        a=i^vec[i];
    }
    cout<<a;

}

void dup_all(vector<int> &vec)      // 1 2 1 3 4 2
{
    vector<int> vec2(vec.size()+1,0);
    vector<int> vec3;
    //good way
    /*
    unordered_map<int,int> mp;

    for (int i = 0; i < vec.size(); i++)
    {
        mp[vec[i]]++;
    }

    for(int i=1; i <= mp.size(); i++)
    {
        if(mp[i] > 1)
        {
            vec2.push_back(i);
        }
    } */

    //best solution
    for (int  i= 0;  i< vec.size(); i++)
    {
        if(vec2[vec[i]])
        {
            vec3.push_back(vec[i]);
        }
        else
            vec2[vec[i]]=1;
    }
    
    printarr(vec3);
    
}

void intersect()
{
    //Two pointer approach
    vector<int> vec={1,2,3,4,5};
    vector<int> vec2={3,4,5,6};
    vector<int> ans;

    int a=vec.size();
    int b=vec2.size();
   
    int i=0,j=0;
    while( (i < a) || (j< b) )
    {
        if(vec[i] <=vec2[j])                //1,2,3,4,5
        {                                   //4,5,6
            if(vec[i] == vec2[j])
            {
                ans.push_back(vec[i]);
                vec2[j]=INT_MIN;
                i++;
                j++;          
            }
            else
                i++;
        }
        else
            j++;
    }
    printarr(ans);
    printarr(vec);
    printarr(vec2);
}

void pair_sum()
{   
    //dont work
    vector<int> vec={2, -3, 3, 3, -2 };     //-3 -2 2 3 3
    int s=0;
    vector<vector<int>> vec2;

    int i=0,j=vec.size()-1;
    while(i<j)
    {
        if(vec[i]+vec[j] == s)
        {
            vector<int> temp;
            temp.push_back(min(vec[i], vec[j]));
            temp.push_back(max(vec[i], vec[j]));
            vec2.push_back(temp); 
            i++;
            j--;
        }
        else if(vec[i]+vec[j] > s)
            j--;
        else
            i++;
    }

    for(int i=0;i<vec2.size();i++)
    {
        for(int j=0; j< vec2[i].size();j++)
        {
            cout<<vec2[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sort_012()
{
    vector<int> vec={2,1,0,1,2,1,0,0,2,1};

    int f=0,m,e=vec.size()-1;
   
    while(m<e)
    {
         m=f+e/2;
        if (vec[m] > vec[e])
        {   
            swap(vec[m],vec[e]);
            if(vec[f] > vec[m])
                swap(vec[f],vec[m]);

            f++;
            e--;
        }
        else if (vec[f] > vec[m])
        {   
            swap(vec[f],vec[m]);
            if(vec[m] > vec[e])
                swap(vec[f],vec[m]);

            f++;
            e--;
        }
        else  if (vec[f] > vec[e])
        {   
            swap(vec[f],vec[e]);
            if(vec[f] > vec[m])
                swap(vec[f],vec[m]);

            f++;
            e--;
        }
    }
    printarr(vec);
}

void bin()
{
    vector<int> vec={2,3,6,7,9,11,67,89};
    int s,e,m;
    int key=3;
    s=0;
    e=vec.size();
    int count =0;
    while(s<=e)
    {
        m= (s+e)/2;
        if(vec[m] == key)
        {
            count = 1;
            break;
        }
        else if (vec[m] > key)
            e = m-1;
        else
            s=m+1;
    }

    if (count ==1)
        cout<<"element found at :"<<m<<" index";
    else 
        cout<<"element is not present in the array";
}

void first_last()
{
    vector<int> vec={0 ,0 ,1 ,1 ,2 ,2 ,2 ,2};
    int s,e,m,k=2,ans1,ans2;
    s=0;e=vec.size();

    while(s<=e) //for left most occurence
    {
        m=s+((e-s) /2);
        if(vec[m] == k)
        {
            ans1=m;
            e=m-1;
        }
        else if(k< vec[m])
            e= m-1;
        else
            s=m+1;
    }
    cout<<"left most occurence of "<<k<<" is "<<ans1;

    s=0; e=vec.size(); 
     while(s<=e) //for right most occurence
    {
        m=s+((e-s) /2);
        if(vec[m] == k)
        {
            ans2=m;
            s= m+1;
        }
        else if(k< vec[m])
            e= m-1;
        else
            s=m+1;
    }
    cout<<endl<<"right most occurence of "<<k<<" is "<<ans2;
}

void peak()
{
    vector<int> vec={0,1,0};

    int s=0,e=vec.size(),m;
    int peak=0;
    while(s<e)
    {
        m=s+ ((e-s)/2);

        if(vec[m-1] < vec[m]) //i.e on left slope increasing line of mountain
        {    if(vec[m] > vec[m+1])
                peak=m;
            s=m+1;
        }
        else if(vec[m]> vec[m+1])   // i.e on right slope , decreasing order of the mountain
        {   if(vec[m-1] <  vec[m])
                peak=m;

            e=m;  
        }
    }
    cout<<"peak is at  index : "<<peak;
}
int main()
{  
    system("cls");
    vector<int> vec={0,1,0};
    //int size=*(&a+1)-a;
    //cout<<size;
    
    //cout<<"Unswapped array : ";
    //printarr(a,size);

    //cout<<endl<<"duplicate element : ";
    //uni(a,size);
    //dup(vec);
    //dup_all(vec);
    //intersect();
    //pair_sum();
    //sort_012();
    //bin();
    //first_last();
    //peak();

    string p="sujal";
    string q="lsuja";
    int count=0;
    string c=p;
    int a=p.size()-1;
 
    for(int i=0; i<p.size()-1; i++)
    {
        if (p == q)
        {
            if (c[a] == q[a])
            {    count =1;
                break;
            }
        }
        c[a] = p[a-1];

    }
    cout<<p<<" "<<count;
    return 0;
}