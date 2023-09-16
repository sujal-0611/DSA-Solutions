//Books Allocation using Binary Search Recursion
//Exact same solution for problem: Painter's problem
//
//for logic in Book allocation watch lec 15 of lubv baabber or aditya's video
#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>& books,int cur_max,int stu)
{
    int sum =0, no_of_student =1;
    int no_of_books=books.size();

    for(int i=0; i< no_of_books; i++)
    {
        sum = sum+ books.at(i);
        if( sum > cur_max)
        {
            no_of_student++;
            sum = books.at(i);
        }
        if(no_of_student > stu)
            return false;
    }
    return true;
}

int BS_recur(vector<int>& books,int stu, int start, int end, int ans)
{
    int mid = start + ((end-start)/2);
 
    //BC1 
    if(start > end ) return ans;  //returning ans as we also update ans below and if ans is never updated then default -1 will returned(no permutation is found)


    if( isValid(books,mid,stu))
    {
        ans = mid;
        return BS_recur(books,stu,start,mid-1,ans);
    }
    else
        return BS_recur(books,stu,mid+1,end,ans);

 }

int book_allocate(vector<int>& books, int students,int no_of_books)
{   
    if ( students > no_of_books)    //base case, if no of students are greater than available books then we cant allocate
        return -1;

        
    int start =-1,end=0;

    for(auto i:books)
    {
        start = max(start,i);   //optimized approach having searcg space from max element to sum of all pages of all books
        end = end+i;            //sum of pages of all books
    }

    return BS_recur(books,students,start,end,-1);
}
int main()
{   
    system("cls");
    vector<int> books = { 12, 34 ,67 ,90};
    int no_of_book = 4;
    int stu = 2;

    cout<<"Books allocated as follows : "<<book_allocate(books,stu,no_of_book);
    
    return 0;
}