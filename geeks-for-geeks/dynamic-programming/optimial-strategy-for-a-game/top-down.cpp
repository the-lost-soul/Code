#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int helper(int arr[] , vector<vector<int>>& dp , int i , int j)
{
    if(j < i)return 0 ;
    if(dp[i][j] != -1)return dp[i][j] ;
    int strategy1 = arr[i] + min(helper(arr , dp , i + 2 , j) , helper(arr , dp , i + 1 , j - 1)) ;
    int strategy2 = arr[j] + min(helper(arr , dp , i , j - 2) , helper(arr , dp , i + 1 , j - 1)) ;
    dp[i][j] = max(strategy1 , strategy2) ;
    return dp[i][j] ;
}
int solve(int arr[] , int size)
{
    vector<vector<int>>dp(size , vector<int>(size , -1)) ;
    dp[0][size - 1] = helper(arr , dp , 0 , size - 1) ;
    return dp[0][size - 1] ;
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
