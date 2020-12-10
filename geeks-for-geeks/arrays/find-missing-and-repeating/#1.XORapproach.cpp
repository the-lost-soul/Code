#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    /* Find the XOR of numbers present in array and then do
     * XOR of numbers from 1 to N . After this point we will
     * have XOR equal to "repeating^missing" numbers i.e the
     * final XOR will contains the XOR of only the missing 
     * and repeating number .
     * eg. -- input Array[1 , 2 , 3 , 1 , 4] and array of numbers
     * from 1 to 5 [1 , 2 , 3 , 4 , 5]
     * When we will do XOR then XORsum = 1^2^3^1^4 and we know
     * 0^1 = 1 and 0^0 = 0or 1^1 = 0 hence finally XORsum = 2^3^4 .
     * And after this when we will do XOR of numbers between b/w 1 to N
     * with XORsum then we will be left only with missing and repeating
     * elements .
     * XORsum = XORsum ^ array of numbers from 1 to 5 .
     * XORsum = 2^3^4^(1^2^3^4^5) which will give XORsum = 1^5 , which are the
     * desired repeating and missing elements .
     */
    int XORsum = 0 ;
    for(int i = 1 ; i <= size ; i++)
        XORsum = XORsum ^ i ;
        
    for(int i = 0 ; i < size ; i++)
        XORsum = XORsum ^ arr[i] ;
    
        
    // Get the number whose only set bit is the right most
    // set bit of XORsum .
    int rightMostSetBitNum ;
    /* Why this statement is giving wrong output when i am using "&&" operator
     * or "and" operator .
     * rightMostSetBitNum = (XORsum) && (~(XORsum - 1));
     * The same code is giving correct result when i am using "&" operator .
     * The reason being that we can't use *logical operators(&& , ||)* in 
     * place of *bit-wise operator(& , | ,<<)* because result of bitwise 
     * operator is an integer whereas result of a logical operator is a 
     * boolean value .
     */
    rightMostSetBitNum = (XORsum) & (~(XORsum - 1));
    
    /* Divide the array into two sets . First set will conatin XOR of those
     * numbers whose bit and the bit of "rightMostSetBitNum" is set , and
     * second set will contain XOR of those numbers whose bit and bit of
     * "rightMostSetBitNum" is not set . Below for loops serve the purpose
     * and after both loop ends then set1 and set2 will contain either the
     * missing or repeating number .
     */
    int set1 = 0 ;
    int set2 = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        /* Here also same problem is occuring i.e when i am using
         * "and" operator , then result is coming wrong whereas
         * when i am using "&" operator then result is coming write .
         *
         * The reason being "and" operation of two numbers gives "TRUE"
         * only when both numbers are non-zero , whereas "&" operation
         * of two bits gives another integer
         */
        
        if(arr[i] & rightMostSetBitNum)set1 = set1 ^ arr[i] ;
        else set2 = set2 ^ arr[i] ;
    }
    
    
    for(int i = 1 ; i <= size ; i++)
    {
        if(i & rightMostSetBitNum)set1 = set1 ^ i ;
        else set2 = set2 ^ i ;
    }
    
    // Find the missing and repeating numbers .
    int missing , repeating ;
    for(int i = 0 ; i < size ; i++)
    {
        if(set1 == arr[i])
        {
            cout<<set1<<" "<<set2<<endl ;
            break ;
        }
        else if(set2 == arr[i])
        {
             cout<<set2<<" "<<set1<<endl ;
             break ;
        }
    }
    
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    int arr[size] ;
	    scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
