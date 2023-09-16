#include<iostream>
using namespace std;
//variables can be used by all pat functions
int row=1,col=1;
int n=3;

//PATTERN 7
void pat7()
{
    row=1,n=3;

    while (row<=n)            //Pat 7 : A A A
    {                       //          B B B
        col=1;                //        C C C
        while(col<=n)
        {
            cout<<char('A'+row-1)<<" ";    
            /* ('A' +row -1) will print in interger so we will do typecasting i.e will do explicit conversion by 
            writing char('A'+row-1), also ('A'-row-1) is formula we generated to print a alphabet for 3 time for a particular row  */
            col++;
        }
      
        row++;
        cout<<endl;
    } 
}

//PATTERN 8
void pat8()
{
    row=1,n=3;
    int count=0;  //temp var to iterate all eleemnts and all aplhabets till n

    while(row<=n)                 //Pat 8:  A B C       PAT 8.2  A B C      pat 8.3  A B C
    {                             //        A B C                D E F               B C D
        col=1;                    //        A B C                G H I               C D E
        while (col<=n)        
        {
            //pat8.1
            //cout<<char('A'+col-1)<<" ";   
            //pat 8.2
            //cout<<char('A'+(++count)-1)<<" ";
            //pat 8.3
            cout<<char('A'+ (row+col-1)-1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
        
    }
}

//PATTERN 9
void pat9()
{
    row=1,n=4;
    int count=0;
    while (row<=n)              //PAT 9.1   A               PAT 9.2   A            PAT 9.3  A
    {                           //          B B                       B C                   B C
        col=1;                  //          C C C                     D E F                 C D E
        while(col<=row)         //          D D D D                   G H I J               D E F G
        {
            //pat 9.1
            //cout<<char('A'+row-1)<<" "; 
            //pat 9.2
            //cout<<char('A'+ (++count)-1 )<<" ";
            //pat 9.3
            cout<<char('A'+(row +col -1)-1)<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }    
}

//PATTERN 10
void pat10()
{
    row=1,n=4;
    int temp=n;
    while (row<=n)                  //PAT 10 : D
    {                               //         C D        
        col=1;  //temp=n;           //         B C D 
        while (col<=row)            //         A B C D    
        {
            //with temp variable
            //cout<<char('A'+(temp-row))<<" ";     
            /* here we are incrementing tp variable ex tp=4 and row 2 then a+ 4-2 will be a+2 -> c and then 
            increment tp which become 5 then a+5-2 -> a+3 -> d, hence we printed c d on 2nd row */

            //stemp++;
            //without temp varable
            cout<<char('A'+((n-row)+col)-1)<<" ";  
            /*here instead of increamenting tp we will add col which also act as a incremention to n(which we cant increment
                sins n is also used in loops so we are adding col will act as temporary incremention to n ) */
            
            col++;
        }
        row++; cout<<endl;
    }
    
}
int main()
{   
    system("cls");
    
    //pat7();
    //pat8();
    //pat9();
    pat10();
    return 0;
}