#include<iostream>
using namespace std;

class op_overload
{
private: int a;

public:
    int getno(){  return a; }
    void setno(int a){ this->a = a; }
    
    //this one called by using single object
    //First Way
    int operator+ (op_overload& obj)   //'obj' is input parameter , while 'this' is a current object for which operator function is called 
    {   int val1 = this->a;
        int val2 = obj.a;

        return val1-val2;   //returning subtraction
    }   
};

//this one is called using 2 objects 
//2nd Way
op_overload operator+(  op_overload& obj2,  op_overload& obj1){
    op_overload obj3;
    int val1,val2;

    obj3.setno(obj1.getno() * obj2.getno());    //returning product
    return obj3;
}

int main(){  
    system("cls");
    op_overload obj_a,obj_b;

    obj_a.setno(10);
    obj_b.setno(20);

    //FIRST WAY
    // ('obj_a' as object for which we call operator function and 'obj_b' as input parameter)
    cout<<"using first way " << (obj_a + obj_b) <<endl;

    //SECOND WAY
    op_overload obj_c = obj_a + obj_b;
    // in this both 'obj_a' and 'obj_b' are input parameters and return type is object as well
    cout<<obj_c.getno();
    
    return 0;
}