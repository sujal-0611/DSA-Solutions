#include<iostream>
using namespace std;
//variables can be used by all pat functions
int i=1,j=1;
int n=3;

// PATTERN 1
void pat1()
{
     i=1,j=1;
     n=3;
    while (i<=n)
    {                                               // pat1: 1 1 1 
        j=1;                                        //       2 2 2
        while(j<=n)                                 //       3 3 3
        {
            cout<< i<<" ";
            j++;
        }
        cout<<endl;
        i++;    
    }  
}

//PATTERN 2
void pat2_1()
{
    i=1,j=1,n=4;
    while (i<=4)
    {
        j=1;
        while(j<=4)                   //PAT 2:  1 2 3 4 
        {                             //        1 2 3 4   
            cout<<j<<" ";             //        1 2 3 4 
            j++;                      //        1 2 3 4
        }                               
        i++;
        cout<<endl;
    }
}

//PATTERN 2.2
void pat2_2()
{
    int i=1,n=4;
    while(i<=n)                     //PAT 2.1 : 4 3 2 1
    {                               //          4 3 2 1
        j=1;                        //          4 3 2 1
        while(j<=n)                 //          4 3 2 1
        {
            cout<<( n -j + 1 )<<" ";      //we add 1 also because we started indexing from 1 , if we start form 0 then we dont need to add 1
            j++;
        }
        i++;
        cout<<endl;
    }

}

//PATTERN 3
void pat3()
{
    i=1,n=3;
    int count=0;                    //PAT 3: 1 2 3 
    while(i<=n)                     //       4 5 6   
    {                               //       7 8 9
        j=1;
        while(j<=n)
        {
            cout<<++count<<" ";    //cant think of formula but since it printing counting only from 1-9 we took a variable and
            j++;                        //and print it from 1-9
        }
        i++;
        cout<<endl;
    }
}

//PATTERN 4.1 : 
void pat4()
{
    i=1,n=4;
    while (i<=n)            //PAT 4.1 : *           Pat4.2 :  1
    {                       //          * *                   2 2 
        j=1;                //          * * *                 3 3 3  
        while(j<=i)         //          * * * *               4 4 4 4  
        {
            //cout<<"* ";     // PAT 4.1
            cout<<i<<" ";   // PAT 4.2
            j++;
        }
        i++;
        cout<<endl;
    }
    
}

//PATTERN 5
void pat5()
{
    
    i=1, n=4;

     //   WITHOUT HELP OF another variable
     while (i<=n)
     {
        j=1;
        while(j<=i)
        {   //-1 bcz indexing is from 1     //PAT 5 :   1
            cout<<i+j-1 <<" ";              //          2 3 
            j++;                            //          3 4 5
        }                                   //          4 5 6 7
        i++;
        cout<<endl;
     }
     
    /*      WITH THE HELP of another variable
    int value=i;    
    while (i<=n)
    {
        j=1; value=i;   // so that value start again but with new ROW.th no. as value
        while(j<=i)
        {                           //PAT 5 :  1
            cout<<value<<" ";       //         2 3 
            value++;                //         3 4 5
            j++;                    //         4 5 6 7
        }
        i++;
        cout<<endl;
    }
    */   
}

//PATTERN 6
void pat6()
{
   i=1, n=4;
   while(i<=n)                          //PAT 6:  1
   {                                    //        2 1   
        j=1;                            //        3 2 1
        while(j<=i)                     //        4 3 2 1
        {
            cout<<( i- j + 1 )<<" ";
            j++;
        }
        i++;
        cout<<endl;
   } 
}
int main()
{   
    system("cls");
    
    //pat1();
    //pat2_1();
    //pat2_2();
    //pat3();
    //pat4();
    //pat5();
    pat6();
    return 0;
}