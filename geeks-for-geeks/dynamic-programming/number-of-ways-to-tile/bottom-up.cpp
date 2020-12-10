#include<bits/stdc++.h>
#include<iostream>
using namespace std;

const int mod = 1e9 + 7 ;
long solve(int n)
{
    if(n == 0)return 0 ;
    if(n <= 3)return 1 ;
    if(n == 4)return 2 ;
    vector<long> dp(n + 1 , 0) ;
    dp[0] = 0 ;
    dp[1] = dp[2] = dp[3] = 1 ;
    dp[4] = 2 ;
    for(int i = 5 ; i <= n ; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 4] ;
    }
    return dp[n] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int n ;
	    cin >> n ;
	    cout << solve(n) << endl ;
	}
	return 0;
}
