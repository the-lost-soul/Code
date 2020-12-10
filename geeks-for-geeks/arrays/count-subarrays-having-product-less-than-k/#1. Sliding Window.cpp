#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size , long long int k)
{
    long long int product = 1 ;
    int startInd = 0 ;
    int subArrCount = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        product *= arr[i] ;
         while(product >= k and startInd < i)
        {
            product /= arr[startInd] ;
            startInd++ ;
        }
        if(product < k)
        {
            subArrCount += (i - startInd) + 1 ;
        }
    }
    return subArrCount ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    long long int k ;
    	cin >> k ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size , k) << endl ;
	}
	return 0;
}
