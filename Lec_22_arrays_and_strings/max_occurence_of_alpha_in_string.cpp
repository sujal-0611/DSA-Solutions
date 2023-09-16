//GFG: Maximum Occuring Character
#include<iostream>
#include<string>
 
using namespace std;

void tolower(string &str)
{
    for(int i=0; i< str.length(); i++)
    {
        if( str[i] >= 'A' and str[i] <= 'Z')
            str[i] = str[i]+32;
    }
}
int main()
{
    system("cls");
    string str="testSample";
    int n=str.length();

    int arr[26]={0};
    //space complexity is still O(1) because 26 is constant here
    tolower(str);
    

    for(int i=0; i <n;i++)      //mapping for each alphabet in array arr,
    {
        int num= str[i]-97;     //num stores aplhabet's value in number form, for ex: for 'a' num is 97-97=0, for 'b' num is 98-97=1 and so on
        arr[num]++;
    }

    int maxi=arr[0];    //to store max count 
    int rec=0;      // to store max count's index
    for(int i =0; i < 26; i++)
        if(maxi < arr[i])
        {
            maxi=arr[i];
            rec=i;
        }
    
    //now rec have index having maximum number (i.e count for that index (which again we visualizing each alpabet on index))
    //so to get the alpha bet back add 97 to it 
    cout<<"alphabet with highest count in string"<<str<<" is : "<<char(rec+97);


    return 0;
}
