//Jaggered Array
#include<iostream>
using namespace std;

void static_jagged()
{
    //create 3 row arrays having different sizes( no of columns)
    int row1[]={1,2,3,4};
    int row2[]={5,6};
    int row3[]={7,8,9};

    int *jagged[]={row1,row2,row3}; //array of pointers, storing base address of each row array

    int  sizes[]={4,2,3};

    for(int i=0; i < 3; i++)    //for each row
    {   
        int *ptr=jagged[i]; //getting current(ith) row

        for(int j=0; j<sizes[i]; j++)    //for ith row having sizes[i] no. of columns 
        {
            cout<<*(ptr+j)<<" ";    // *ptr have base address 
                                    //adding j means access jth element for particular(ith) row   
        }
        cout<<endl;
    }
}

void dynamic_jagged()
{
    int row,col;
    int colsum=0;   //to get total number of elements in jaggered matrix(array)

    cout<<"Enter number of rows"<<endl;
    cin>>row;

    //Create Row Array
    int** arr=new int*[row];    
    int *colrec= new int[row];  //to record column size for each row


    //Create Column(of different size) for each Row (array of pointer)
    cout<<"Enter the size of column for each row"<<endl;
    for(int i=0; i<row; i++)
    {
        cin>>col;
        colsum=colsum+col;
        colrec[i]=col;              //storing col size for each row in another array(this array will be used when accessing elements)
        *(arr+i) = new int[col];    //creating column for each row
    }
    cout<<"Enter the elements( elements limit: "<<colsum<<")"<<endl;
    for(int i=0; i<row; i++)
        for(int j=0; j < colrec[i] ; j++)
            cin>>arr[i][j];
    
    cout<<"elements in matrix form as follow"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j < colrec[i] ; j++)
            cout<<arr[i][j]<<" ";
        
        cout<<endl;
    }
}
int main()
{   
    system("cls");
    cout<<"Static Jagged"<<endl;
    static_jagged();
    cout<<"dynamic jagged:"<<endl;
    dynamic_jagged();
    
    
    return 0;
}