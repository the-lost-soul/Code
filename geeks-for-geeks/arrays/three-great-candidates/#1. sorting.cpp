#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

long long solve(int arr[] , int size)
{
    sort(arr , arr + size) ;
    /* The solution can be either the product of elements at
     * index 0 , 1 , and size - 1 if the first two elements 
     * are negative and maximizes the product or the product
     * of elements at index size - 1 , size - 2 , size - 3 .
     */
    long long max1 = (long long)arr[0]*arr[1]*arr[size - 1] ;
    long long max2 = (long long)arr[size - 1]*arr[size - 2]*arr[size - 3] ;
    if(max1 > max2)return max1 ;
    return max2 ;
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
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
