#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int partition(int arr[] , int board , int painters , vector<vector<int>>& dp)
{
    if(board == 1)return arr[board - 1] ;
    if(painters == 1) return accumulate(arr , arr + board , 0) ;
    if(dp[board][painters] != -1)return dp[board][painters] ;
    int best = INT_MAX ;
    for(int i = 1 ; i <= board ; i++)
    {
        best = min(best , max(partition(arr , i , painters - 1 , dp) , accumulate(arr + i , arr + board , 0))) ;
    }
    return dp[board][painters] = best ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int painters , board ;
    	cin >> painters >> board ;
    	int arr[board] ;
    	scanArray(arr , board) ;
    	vector<vector<int>> dp(board + 1 , vector<int>(painters + 1 , -1)) ;
	    cout << partition(arr , board , painters , dp) << endl ;
	}
	return 0;
}
