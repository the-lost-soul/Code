#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string str1 , string str2)
{
    int len1 = str1.size() , len2 = str2.size() ;
    vector<vector<int>>dp(len2 + 1 , vector<int>(len1 + 1 , 0)) ;
    for(int i = 0 ; i <= len1 ; i++)
        dp[0][i] = 1 ;
    for(int i = 1 ; i <= len2 ; i++)
        dp[i][0] = 0 ;
    
    for(int i = 1 ; i <= len2 ; i++)
    {
        for(int j = 1 ; j <= len1 ; j++)
        {
            dp[i][j] = dp[i][j - 1] + (str1[j - 1] == str2[i - 1] ? dp[i - 1][j - 1] : 0) ;
        }
    }
    return dp[len2][len1] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str1 , str2 ;
	    cin >> str1 >> str2 ;
	    cout << solve(str1 , str2) << endl ;
	}
	return 0;
}
