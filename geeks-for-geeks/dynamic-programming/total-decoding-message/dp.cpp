#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string str)
{
    if(str[0] == '0')return 0 ;
    int len = str.size() ;
    vector<int>dp(len + 1 , 0) ;
    dp[0] = 1 ;
    dp[1] = 1 ;
    for(int i = 2 ; i <= len ; i++)
    {
        char curr = str[i - 1] ;
        char prev = str[i - 2] ;
        if(curr > '0')
        {
            dp[i] = dp[i - 1] ;
        }
        // if((prev == '1' or prev == '2') and curr < '7') -->wrong
        // because curr can be >= '7' which can be coupled with '1'
        // but not with '2' . Hence , below condition is correct .
        if(prev == '1' or (prev == '2' and curr < '7'))
        {
            dp[i] += dp[i - 2] ;
        }
    }
    return dp[len] ;
}
int main()
{
    int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int len ;
	    cin >> len ;
	    string str ;
	    cin >> str ;
	    cout << solve(str) << endl ;
    }
	return 0;
}
