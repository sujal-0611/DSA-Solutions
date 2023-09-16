//BOOK ALLOCATION PROBLEM V.V. Important
#include<iostream>
#include<vector>

using namespace std;

bool isValid( vector<int>& vec,int cur_max, int stu, int no_books)
{
    int sum=0, student=1;
    for(int i=0;i<no_books ; i++)
    {
        sum = sum + vec[i];     //for 2nd index ; sum is 10+20=30 ,which is less than current mid=50 so it keep going unitl sum> cur_max
        if( sum > cur_max)      
        {
            student++;  
            sum=vec[i];     //as for next student addition take place at the index if condition became true ,so we for next student we add from ith vector element
        }
        if(student >stu)        
        {
            return false;
        }
    }
    return true;
}
int books_allocate(vector<int>& vec,int stu, int no_books)
{
    int start=-1,end=0,mid,ans=-1; 
    /*start could have been zero but its will be optimised to use max vec element as start, as for allocations that max element 
    would be assigned atleast single book, so minimum start would be books with max pages among all other books
    end is sum of all pages of books , as the max of no of pages can go is sum of all book's pages that is why end is sum
    ALSO minimum of max pages allocated to a student lies in range of start to end (as all the numbers in this range are max pages
     that can be allocated to student , we just need to find minimum among that range)
   */

    if(stu> no_books)    //if there are more students than books
        return -1;
    for(auto i:vec)
    {
        start = max(i,start);
        end = end +i;
    }
    //cout<<"max arr is "<<start<<" and sum of all arrays is "<<end<<endl;
    while( start <= end)
    {
         //mid is our current max pages to be allocated to a student, we will find if its one of the solution(i.e min of max pages)
        mid = start + ((end- start)/2);    
        if( isValid(vec,mid,stu,no_books) == true)  //if mid is one the solution then , store it and shrink the range by shifting 
        {                                           // end pointer
            ans= mid;
            end = mid -1;
        }
        else    // if mid is not enough(as max pages ) to be allocated among given no. of students(i.e more students needed)
            start = mid + 1;    //then change start ,as we need higher max. pages 
    }
    return ans;
}
int main()
{   
    system("cls");
    vector<int> pages_arr={ 10,20,30,40};
    int stu= 2;
    int no_books=pages_arr.size();

    cout<<"Minimum of maximum number of pages allocated to a student is:"<<books_allocate(pages_arr,stu,no_books) ;

    
    return 0;
}