#include<iostream>
using namespace std;
//variables can be used by all pat functions
int row=1,col=1;
int n=3;

//PAT 11
void pat11()
{
    /* this one is index manipulating

    row=1,n=4;              //PAT 11      _ _ _ *       ( '_' here representing space)(including diagonals)
                            //            _ _ * * 
    while (row<=n)          //            _ * * *  
    {                       //            * * * *
        col=1;
        while(col<=n)
        {
            if()
            cout<<"* ";
            col --;
        }
        row++;
        cout<<endl;
    }   
    */


   /*printing is done as follow  :  first print content of 1st nested loop(for that particluar row) on  a particluar line
            (ex for row 1 line is 1st) then print content of 2nd nested loop (for same particular row) on same line ,then same for 
            3rd nested loop on same line(for same particular row) and so on, here there are 2 nested while loops */

     row=1,n=4; 
    //another logic
    int space;
    while (row<=n)
    {
        space=n-row;
        //now first print space 
        while(space)
        {
            cout<<"  ";
            space--;
        }
        //after printing space then print star(on same line )
        col=1;
        while(col<=row)
        {
            cout<<"* ";
            col++;
        }
        row++; cout<<endl;
    }
}

//PATTERN 12
void pat12()
{
    row=1,n=4;
    while(row<=n)                 //  PAT 12 : * * * *  (including diagonals)
    {                             //           * * *  
        col=1;                    //           * *
        while (col<=(n-row+1))    //           *   
        {
            cout<<"* ";
            col++;
        }
        row++;
        cout<<endl;
    }
}

//PATTERN 13
void pat13()
{
    row=1,n=4; 
    int space,temp=n;             //PAT 13 :  * * * *     (including diagonals)
    while (row<=n)                //            * * *  
    {                             //              * *
        //for spaces              //                *
        space = n-temp ;              
        while(space)
        {
            cout<<"  ";
            space--;
        }
        temp--;

        //for stars
        col=1;
        while (col<=(n-row+1))  //n-row+1 : condition 
        {
            cout<<"* ";
            col++;
        }
        row++;
        cout<<endl;
    }  
}

//PATTERN 14 ,  same as Pattern 13 ,now with Numbers! 
void pat14()
{
    row=1,n=4;                  
    int space,temp=n;
    while (row<=n)
    {
        //printing spaces
        space=n-temp;
        while(space)    
        {   
            cout<<"  ";             // PAT 14.1 : 1 1 1 1       PAT 14.2 : 1 2 3 4
            space--;                //              2 2 2                    2 3 4 
        }                           //                3 3                      3 4
        temp--;                     //                  4                        4

        //now numbers
        col=1;
        while (col<=( n-row+1 ) )
        {
            //pat 14.1
            //cout<<row<<" ";

            //pat 14.2
            cout<<( row + col - 1 ) <<" ";
            col++;
        }
        row++;
        cout<<endl;     
    }   
}

//PATTERN 15 same as Pattern 11
void pat15()
{
    row=1,n=4;
    int space;
    int count=1;
    while(row<=n)               //PAT 15.1:     1       PAT 15.2      1
    {                           //            2 2                   2 3  
        //printing space        //          3 3 3                 4 5 6 
        space=n-row;            //        4 4 4 4               7 8 9 10
        while (space)
        {
            cout<<"  ";
            space--;
        }

        //printing numbers
        col=1;
        
        while(col<=row)
        {
            //Pat 15.1
            //cout<<row<<" ";

            //Pat 15.2
            cout<<count++<<" ";
            //count++;
            col++;
        }
        row++;
        cout<<endl;    
    }
}

//PATTERN 16 *****  //solution here is complex simpler one is to write 3rd nested while loop on 4th video of love babber
void pat16()
{
    row=1;
    int nr=5;   //nr = no of rows
    int space=0,temp=0;

    int nc=(nr*2)-1;  /*no of columns generated on the basis of no of rows , 
            formula specifically generate for this pattern wit relation of for every addition of row, 
            the no. column increase by 2   for example ; for row=1 no of col =1*2 -1= 1, for row=2 ,col=2*2 -1=3 and so on.... */

    while (row<=nr)
    {
        //this part print spaces
    
        space= nr-row;          //PAT 16 :   - - - 1             ('-' is showing its blank space)
        while(space)            //           - - 1 2 1 
        {                       //           - 1 2 3 2 1
            cout<<"  ";         //           1 2 3 4 3 2 1
            space--;
        }

        //now printing the numbers in pyamid
        col=1;
          temp=row-1;   //temporary variable used when col > row(so that we can start printing in reverse order )

        while (col<=((row*2)-1) )
        {
            
            if(col<=row)
                cout<<col<<" ";
            if(col>row)
                cout<<( (temp--) )<<" ";
                    
            col++;
        }
        row++; cout<<endl;
    }
    
}

void pat17()
{
    //SPILTING PATTERN INTO # TRIANGLES
    row=1,n=5;
    int temp=0;
    while (row<=n)
    {   
        /*printing is done as follow  :  first print content of 1st nested loop(for that particluar row) on  a particluar line
            (ex for row 1 line is 1st) then print content of 2nd nested loop (for same particular row) on same line ,then same for 
            3rd nested loop on same line(for same particular triangle)    */

        //printing for 1st triangle lines(for row 1 line 1 then print )
        col=1;
        while(col<=(n-row+1))
        {    cout<<col<<" ";
             col++;
        }

        //printing 2nd triangle

/*
        
        while (col<=((row*2)-1) )
        {
            
            if(col<=row)
                cout<<"* ";
            if(col>row)
                cout<<"* ";
                    
            col++;                                              
        }   
        */                                              
                                                
        ///if(row>1)                               
       // {
            col=1;
            while(col<=row)
            {
                cout<<"* ";
                 col++;
            }
            
            col=1;
            while(col<=row)
            {
                cout<<"* ";
                col++;
            }
      //  }
        
                

        //printing for 3rd triangle 
        col=1;
        int temp=n-row+1;
        while(col<= (n-row+1) )
        {
            cout<<(temp--)<<" ";
            col++;
        }


      

        row++; cout<<endl;
    }
    
}
int main()
{   
    system("cls");
    
/* **** all these questions can be done by index manipulation but
                         we havent done them here, check them in C Codes**** */ 

    //pat11();
    //pat12();
    //pat13();
    //pat14();
    //pat15();
    //pat16();
    pat17();


    return 0;
}