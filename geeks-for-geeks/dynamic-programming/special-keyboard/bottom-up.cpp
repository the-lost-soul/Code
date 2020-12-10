#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(int num)
{
    vector<int>dp(num , 0) ;
    for(int i = 1 ; i <= 6 ; i++) dp[i - 1] = i ;
    
    for(int i = 7 ; i <= num ; i++)
    {
        dp[i - 1] = max(2*dp[i - 4] , max(3*dp[i - 5] , 4*dp[i - 6])) ;
    }
    
    return dp[num - 1] ;
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
