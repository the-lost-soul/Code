#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string solve(string str)
{
    int len = str.length() ;
    bool dp[len][len] ;
    memset(dp , false , len*len) ;
    
    // All sub-strings of length 1 are pallindromes .
    for(int i = 0 ; i < len ; i++)dp[i][i] = true ;
    int maxLen = 1 , startIndex = 0 ;
    // Mark all sub-strings of length 2 which are pallindrome .
    for(int i = 0 ; i < len - 1 ; i++)
    {
        dp[i][i+1] = str[i] == str[i+1] ;
        if(dp[i][i+1] and maxLen < 2)
        {
            startIndex = i ;
            maxLen = 2 ;
        }
    }
    
    // For every sub-string of length greater than 2 .
    for(int pLength = 3 ; pLength <= len ; pLength++)
    {
        // Fix the starting index .
        for(int i = 0 ; i <= len - pLength ; i++)
        {
            // Get the ending index of the desired sub-string .
            int j = pLength + i - 1 ;
            // Check if characters at index i and j are equal or not .
            // Also check whether the sub-string starting at "i+1" and
            // ending at "j-1" is pallindrome or not .
            dp[i][j] = (dp[i+1][j-1]) and (str[i] == str[j]) ;
            if(dp[i][j] and maxLen < pLength)
            {
                startIndex = i ;
                maxLen = pLength ;
            }
        }
    }
    return str.substr(startIndex , maxLen) ;
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
	return 0 ;
}
