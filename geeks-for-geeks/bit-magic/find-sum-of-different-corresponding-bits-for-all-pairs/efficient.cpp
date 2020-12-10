#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(long int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(long int arr[] , int size)
{
    long int count1 = 0 , count0 = 0 ;
    long int answer = 0 ;
    // From the given range , we can see that our numbers
    // are in 32 bit format and hence we have to check all
    // 32 bits .
    for(int i = 0 ; i < 32 ; i++)
    {
        count1 = count0 = 0 ;
        /* Check if ith bit is set or not and make combination
         * between pairs depending and total pairs will be 
         * 2*count0*count1 because if a number a1(ith bit set) is 
         * making pair with a number a2(ith bit off) then a2 will
         * also make pair with a1 and hence we will be having double
         * combinations .
         */
        for(int j = 0 ; j < size ; j++)
        {
            if(arr[j] & (1<<i))count1 ++ ;
            else count0 ++ ;
        }
        // To do a check , if in case answer exceeds 10^9 + 7 .
        answer = (answer + (2*count1*count0))%1000000007 ;
    }
    cout << answer << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	long int arr[size] ;
    	scanArray(arr , size) ;
	    solve(arr , size) ;
	}
	return 0;
}
