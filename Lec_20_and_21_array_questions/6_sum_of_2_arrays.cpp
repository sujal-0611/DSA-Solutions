//code studio: sum of 2 arrays
#include<iostream>
#include<vector>
using namespace std;

void print_arr(vector<int>& vec)
{
    int n= vec.size();
    int i=0;
    while(i < n)
    {
        cout<<(vec[i])<<" ";
        i++;
    }
    cout<<endl;
}

void rev(vector<int>& vec, int start, int end)
{   
    while(start <=end)
    {
            vec[start] = vec[end] + vec[start] - ( vec[end] = vec[start]);  //swapping of two numbers

            start++;
            end--;
        }
}
vector<int> sum_2arrays(vector<int>& vec1, vector<int>& vec2)
{
 /*
    1.as addtion start from ones place so we have 2 pointers pointing at last of each vector
    2.using carry to store extra digit generated when adding 2 numbers.. for ex: 9+3=12 ,carry will store tens of that number

    3. case where both vectors are of same size and on addition of their highest places lead to creation of new place... 
        for ex: v1->9,2,8 | v2-> 3,0,4 so on addtion of 9 and 1 that is 12 we need sum new place to store tens place (i.e 1 of 12), 
        that is why we are increasing larger by 1 

    4.Working of loop
            till 'larger' is not zero
            -if both 'i' and 'j' are not zero then,
                --create sum int variable 'sum' storing sum of elements of each vector plus carry(at first carry is 0) .
            -if 'j' becomes zero(but 'i' is not zero) then,
                -- variable 'sum' will store element of first vector + carry only.
            -if 'i' becomes zero(but 'j' is not zero) then,
                --variable 'sum' will store element of second vector +carry only.
            -
        if second vector is larger
            till 'j' is not zero
            create sum int variable 'sum' storing sum of elements of each vector plus carry(at first carry is 0) .
            

        now
            carry = sum/10 (it which stores extra digit generated when adding 2 numbers.. 
            for ex: 9+3=12 ,carry will store tens of that number).
        
    5.this case run when i and j both are less than 0 ,but there's still sum digit to be added.
                case where both vectors are of same size and on addition of their highest places lead to 
                 creation of new place... 
                for ex: v1->9,2,8 | v2-> 3,0,4 so on addtion of 9 and 1 that is 12 we need sum new place 
                to store tens place (i.e 1 of 12) but as both i and j becomes -1 this '1' remains in carry
                variable and not added to vec3

    */
        int n=vec1.size();
        int m=vec2.size();
        vector<int> vec3;
		int i,j;
		i=n-1; j=m-1;       //1.
		int carry=0;         // 2.

		//4.
		while(i>=0 || j>=0 )       
		{   
			int sum;
			if(j>=0 && i>= 0)    //taking care of overlapping numbers for ex: v1-> 1,5,4 and v2-> 2,6 so here 4 overlap with 6 and 5 overlap with 2    
				sum = vec1[i--] + vec2[j--] + carry;
			else if(i>=0)       // if digits in second vector run out but first vector still have digits
				sum= vec1[i--] + carry;
			else if (j>=0)      // if digits in first vector run out but second vector still have digits
				sum= vec2[j--] + carry;
		
			carry= sum/10;
			sum =sum %10;
			vec3.push_back(sum); 
			
		}
		 while(carry != 0)  //5.
		 {
			int sum = carry;
			carry = sum/10;
			sum = sum%10;
			vec3.push_back(sum);
    }
	
		rev(vec3,0,vec3.size()-1);  //the answer we got is reversed , so we will reverse the reversed answer
	
		return vec3;

}

int main()
{   
    system("cls");
    vector<int> vec1={9,3,2};
    vector<int> vec2={1,1,6};
    vector<int> vec3;
    cout<<"vector 1: ";
    print_arr(vec1);
    cout<<"vector 2: ";
    print_arr(vec2);

    vec3=sum_2arrays(vec1,vec2);
    cout<<"sum of these 2 vector is:";
    print_arr(vec3);
    
    return 0;
}