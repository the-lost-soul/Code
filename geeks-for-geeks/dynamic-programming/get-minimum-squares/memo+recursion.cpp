#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int helper(int num , int dp[])
{
    if(num <= 0)return 0 ;
    if(dp[num] != INT_MAX)
        return dp[num] ;
    for(int i = 1 ; i*i <= num ; i++)
    {
        dp[num] = min(dp[num] , 1 + helper(num - i*i , dp)) ;
    }
    return dp[num] ;
}
int solve(int num)
{
    int dp[num + 1] ;
    for(int i = 1 ; i <= num ; i++)
        dp[i] = INT_MAX ;
    dp[0] = 0 ;
    for(int i = 1 ; i*i <= num ; i++)
    {
        dp[num] = min(dp[num] , 1 + helper(num - i*i , dp)) ;
    }
    return dp[num] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int num ;
    	cin >> num ;
	    cout << solve(num) << endl ;
	}
	return 0;
}
