#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int min(int insert , int remov , int del)
{
    return min(insert , min(remov , del)) ;
}



int solve(string source , string target , int sourceLength , int targetLength , 
          vector< vector<int> >&dp)
{
    if(sourceLength == 0)return targetLength ;
    if(targetLength == 0)return sourceLength ;
    
    if(dp[sourceLength - 1][targetLength - 1] != -1)
    return dp[sourceLength - 1][targetLength - 1] ;
    
    if(source[sourceLength - 1] == target[targetLength - 1])
    return dp[sourceLength - 1][targetLength - 1] = solve(source , target , sourceLength-1 
                                                     , targetLength - 1 , dp) ;
    
    else return dp[sourceLength - 1][targetLength - 1] = 1 + min(solve(source , target , sourceLength , targetLength - 1 , dp) ,
                        solve(source , target , sourceLength - 1 , targetLength , dp) ,
                        solve(source , target , sourceLength - 1 , targetLength - 1 , dp)) ;
    
    
    return dp[sourceLength - 1][targetLength - 1] ;
}



int main() 
{
    int testcase ;
    cin >> testcase ;
    string source ;
    int sourceLength ;
    string target ;
    int targetLength ;
    while(testcase --)
    {
        cin >> sourceLength ;
        cin >> targetLength ;
        cin >> source ;
        cin >> target ;
        vector<vector<int> >dp(sourceLength) ;
        for(int i = 0 ; i < sourceLength ; i++)
        {
            dp[i] = vector<int>(targetLength) ;
        }
        
        for(int i = 0 ; i < sourceLength ; i++)
        {
            for(int j = 0 ; j < dp[i].size() ; j++)
            {
                dp[i][j] = -1 ;
            }
        }
        cout << solve(source , target , sourceLength , targetLength , dp) << endl ;
    }
	return 0;
}
