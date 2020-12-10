#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;

long solve(int digit , int sum)
{
    long ans = 0 ;
    vector<vector<long>>dp(digit + 1 , vector<long>(sum + 1 , 0)) ;
    dp[0][0] = 1 ;
    for(int i = 1 ; i <= digit ; i++)
    {
        for(int j = 1 ; j <= sum ; j++)
        {
            for(int k = 0 ; k <= 9 ; k++)
            {
                if(i == 1 and k == 0)continue ;
                if(j - k >= 0)dp[i][j] = dp[i - 1][j - k]%mod + dp[i][j]%mod ;
            }
        }
    }
    return dp[digit][sum] == 0 ? -1 : dp[digit][sum]%mod ;
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
