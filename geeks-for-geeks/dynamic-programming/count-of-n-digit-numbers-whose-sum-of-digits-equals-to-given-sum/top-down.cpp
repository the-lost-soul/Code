#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;

long helper(int digit , int sum , vector<vector<long>>& dp)
{
    if(digit == 0)return sum == 0 ;
    if(dp[digit][sum] != -1)return dp[digit][sum] ;
    long ans = 0 ;
    for(int i = 0 ; i <= 9 ; i++)
    {
        if(sum - i >= 0) ans = ans%mod + (helper(digit - 1 , sum - i , dp))%mod ;
    }
    dp[digit][sum] = ans%mod ;
    return dp[digit][sum] ;
}
long solve(int digit , int sum)
{
    long ans = 0 ;
    vector<vector<long>>dp(digit + 1 , vector<long>(sum + 1 , -1)) ;
    for(int i = 1 ; i <= 9 ; i++)
    {
        if(sum - i >= 0)
            ans = ans%mod + (helper(digit - 1 , sum - i , dp))%mod ;
    }
    return ans == 0 ? -1 : ans%mod ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int digit , sum ;
	    cin >> digit >> sum ;
	    cout << solve(digit , sum) << endl ;
	}
	return 0;
}
