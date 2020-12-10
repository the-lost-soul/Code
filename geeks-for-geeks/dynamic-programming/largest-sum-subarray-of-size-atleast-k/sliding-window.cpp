#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size , int k)
{
    vector<int>maxSum(size , 0) ;
    maxSum[0] = arr[0] ;
    int currMax = arr[0] ;
    for(int i = 1 ; i < size ; i++)
    {
        currMax = max(arr[i] , currMax + arr[i]) ;
        maxSum[i] = currMax ;
    }
    
    int sum = accumulate(arr , arr + k , 0) ;
    int result = sum ;
    for(int i = k ; i < size ; i++)
    {
        sum = sum + arr[i] - arr[i - k] ;
        result = max(result , sum) ;
        result = max(result , sum + maxSum[i - k]) ;
    }
    
    return result ;
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
    	int k ;
    	cin >> k ;
	    cout << solve(arr , size , k) << endl ;
	}
	return 0;
}
