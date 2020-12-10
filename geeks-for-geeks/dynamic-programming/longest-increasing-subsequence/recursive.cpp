#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int helper(int arr[] , int first , int second , int size)
{
    if(second >= size)return 1 ;
    int len1 = 0 ;
    if(arr[first] < arr[second])
    {
        len1 = 1 + helper(arr , second , second + 1 , size) ;
    }
    int len2 = helper(arr , first , second + 1 , size) ;
    return max(len1 , len2) ;
}

int solve(int arr[] , int size)
{
    int len = INT_MIN ;
    for(int i = 0 ; i < size ; i++)
    {
        len = max(len , helper(arr , i , i + 1 , size)) ;
    }
    
    return len ;
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
