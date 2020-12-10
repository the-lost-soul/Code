#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef vector<vector<vector<int>>> arr3D ;
void printArr3D(arr3D dp , int len)
{
    for(int i = 0 ; i < len ; i++)
    {
        for(int j = 0 ; j < 1 ; j++)
        {
            for(int k = 0 ; k < 2 ; k++)
            {
                cout << dp[i][j][k] << " " ;
            }
            cout << endl ;
        }
        cout << endl ;
    }
}
int countStrings(arr3D& dp , int len , int a , int b , int c)
{
    if(b > 1 || c > 2)return 0 ;
    if(len == 0)return 1 ;
    if(b == 1 and c == 2)return 1 ;
    
    if(dp[a][b][c] != -1)return dp[a][b][c] ;
    dp[a][b][c] = countStrings(dp , len - 1 , a + 1 , b , c) ;
    dp[a][b][c] += countStrings(dp , len - 1 , a , b + 1 , c) ;
    dp[a][b][c] += countStrings(dp , len - 1 , a , b , c + 1) ;
    return dp[a][b][c] ;
}
int solve(int len)
{
    arr3D dp(len + 1 , vector<vector<int>>(2 , vector<int>(3 , -1))) ;
    // printArr3D(dp , len) ;
    countStrings(dp , len , 0 , 0 , 0) ;
    return dp[0][0][0] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int len ;
    	cin >> len ;
	    cout << solve(len) << endl ;
	}
	return 0;
}
