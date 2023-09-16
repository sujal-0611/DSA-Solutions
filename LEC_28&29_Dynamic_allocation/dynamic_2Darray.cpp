//dynamically creating 2d arrays in 2 ways
//read notes in diary for clear explainations
#include<iostream>
using namespace std;

//implementation of 2d array using double pointer - luv babber
void Two_D_array1()
{   
    //implimenting 2D array by array of Pointers
     int row,col;
    cout<<"enter rows and columns\n";
    cin>>row>>col;

    //to create dynamic 2d array: 2 steps
    //step 1:first create rows for 2d array
    int** arr=new int*[row];    //**arr bcz each row will have a pointer pointing for coulmn

    //step 2:now create columns for each row using pointer
    for(int i=0; i< row; i++)
    {
         //arr[i] = new int[col];    //for each row create another array of size col starting from row pointer
        //or                        //arr[i] or *(arr+i) means ith row
        *(arr+i) = new int[col];    //another way
    }
    
    cout<<"Insert values\n";
    //now insert values
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin>>arr[i][j];
        
        
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }   

    //first delete columns
    for(int i=0;i<row;i++)
        delete []arr[i];
    //then delete rows
    delete []arr; //deleting manual allocation
}

//implementation of 2d array using (i*C +j)  formula, i.e using interal interpretation of 2d arrays in memory - C++ 11th grADE BOOK
void Two_D_array2()
{
    //another way to make dynamic 2d array: 
    //Using Pointer Arithmetic
    //i.e using internal implimentation by compiler of static 2D array
    //2d aaray are actually stored as linear array but we access them in the matrix form 
    //so compiler store 2d array elements in linear array with formula of i*c +j
    //where i is curent row , j is current column and c is total number of row 
    // this is also a reason why we can skip row size  but not column while declaring 2d arrays(static)
    //here we use i*c+j formula to use linear array as 2d array

    int row,col;
    cout<<"enter rows and columns\n";
    cin>>row>>col;

    int *arr = new int[row*col]; 


    //now taking input in 2d array(linearly implemented) using i*Col +j formula
    cout<<"Enter values\n";
    for(int i=0; i<row;i++)     //for ith row
        for(int j=0; j < col; j++)      //for jth col
            cin>>arr[i*col + j];    //enter element for ith row and jth col of matrix arr

    //now printing 
     for(int i=0; i<row;i++)
    {
        for(int j=0; j < col; j++)
        {
            cout<<arr[i*col + j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{   
    system("cls");
    
    Two_D_array1();   //double pointer approach
    Two_D_array2();      //i*C+j approach 
    return 0;
}