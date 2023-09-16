#include<iostream>
using namespace std;
class abc {
    private:
        int a;
        int b;
        int d;
        int e;
        char c;
    public:
    abc();

    abc(int a,char c){
        this->a=a;
        this->c =c;
        cout<<this->a<<" "<<this->c;
    }
}; 


int main()
{   
    system("cls");
    int a=10;
    char b='a';
    //static allocation 
    abc obj1;
    abc obj(a,b);

    //Dynamic allocation
    abc *obj3 =new abc;
    //or
    abc *ojb4= new abc();   //this one also calls for default constructor (java like syntax)


    abc *obj2 = new abc(a,b);   //**   abc(a,b) calls constructor abc(int a,int b)
    cout<<endl<<sizeof(obj2);    //now its printing 8 bytes but why?? -due to padding i guess

    
    return 0;
}