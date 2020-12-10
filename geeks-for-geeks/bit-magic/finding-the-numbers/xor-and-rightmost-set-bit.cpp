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
    /* Get the XOR of all elements present in array , and all 
     * repeated elements will get cancelled out and we will be
     * only with non - repeating elements .
     * eg. -- [1 , 2 , 3 , 1 , 4 , 2 , 5 , 4]
     * When we will do XOR then XOR = 1^2^3^1^4^2^5^4 and we know
     * 0^1 = 1 and 0^0 = 0or 1^1 = 0 hence finally XOR = 3^5 .
     */
    int XORsum = 0 ;
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
    
    if(set1 > set2)cout<<set2<<" "<<set1<<endl ;
    else cout<<set1<<" "<<set2<<endl ;
    
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    int arr[2*size + 2] ;
	    scanArray(arr , 2*size + 2) ;
	    solve(arr , 2*size + 2) ;
	}
	return 0;
}
