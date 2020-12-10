#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;
long solve(int n)
{
    vector<long>dp(n + 1 , 0) ;
    dp[0] = 1 ;
    dp[1] = 1 ;
    for(int i = 2 ; i <= n ; i++)
    {
        // Refer mathstackexchange for this fromula's explanation
        // https://math.stackexchange.com/questions/2833504/friends-pairing-problem
        dp[i] = (dp[i - 1]%mod + ((i - 1)*dp[i - 2])%mod)%mod ;
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
