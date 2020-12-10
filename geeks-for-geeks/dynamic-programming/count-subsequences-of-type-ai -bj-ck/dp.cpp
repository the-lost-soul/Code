#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;
long solve(string str)
{
    int n = str.size() ;
    vector<vector<long>>dp(n + 1 , vector<long>(3 , 0)) ;
    for(int i = 1 ; i <= n ; i++)
    {
        if(str[i - 1] == 'a')
        {
            dp[i][0] = 1 + 2*dp[i - 1][0] ;
            dp[i][1] = dp[i - 1][1] ;
            dp[i][2] = dp[i - 1][2] ;
        }
        else if(str[i - 1] == 'b')
        {
            dp[i][1] = 2*dp[i - 1][1] + dp[i - 1][0] ;
            dp[i][0] = dp[i - 1][0] ;
            dp[i][2] = dp[i - 1][2] ;
        }
        else if(str[i - 1] == 'c')
        {
            dp[i][2] = 2*dp[i - 1][2] + dp[i - 1][1] ;
            dp[i][0] = dp[i - 1][0] ;
            dp[i][1] = dp[i - 1][1] ;
        }
    }
    return dp[n][2] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    cout << solve(str) << endl ;
	}
	return 0;
}
