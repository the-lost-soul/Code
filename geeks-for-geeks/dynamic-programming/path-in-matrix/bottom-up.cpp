#include<bits/stdc++.h>
#include<iostream>
using namespace std ;
void scanArray(vector<vector<int>>& matrix , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            cin >> matrix[i][j] ;
        }
    }
}
int solve(vector<vector<int>>matrix , int size)
{
    vector<vector<int>>dp(size , vector<int>(size , 0)) ;
    for(int i = 0 ; i < size ; i++)
        dp[0][i] = matrix[0][i] ;
    for(int r = 1 ; r < size ; r++)
    {
        for(int c = 0 ; c < size ; c++)
        {
            if(c == 0)
                dp[r][c] = max(dp[r - 1][c] , dp[r - 1][c + 1]) + matrix[r][c] ;
                
            else if(c == size - 1)
                dp[r][c] = max(dp[r - 1][c] , dp[r - 1][c - 1]) + matrix[r][c] ;
            
            else
                dp[r][c] = max(dp[r - 1][c] , max(dp[r - 1][c + 1] , dp[r - 1][c - 1])) + matrix[r][c] ;
        }
    }
    return *max_element(dp[size - 1].begin() , dp[size - 1].end()) ;
    
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<vector<int>>matrix(size , vector<int>(size)) ;
    	scanArray(matrix , size) ;
	    cout << solve(matrix , size) << endl ;
	}
	return 0;
}
