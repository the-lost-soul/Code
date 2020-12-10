#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int helper(int arr[] , int i , int j)
{
    if(j < i)return 0 ;
    int ans = 0 ;
    ans += max(arr[i] + min(helper(arr , i + 2 , j) , helper(arr , i + 1 , j - 1)) , 
                arr[j] + min(helper(arr , i , j - 2) , helper(arr , i + 1 , j - 1))) ;
    return ans ;
}
int solve(int arr[] , int size)
{
    return helper(arr , 0 , size - 1) ;
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
