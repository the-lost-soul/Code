#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int>dx{2 , 2 , -2 , -2 , 1 , 1 , -1 , -1} ;
vector<int>dy{1 , -1 , 1 , -1 , 2 , -2 , 2 , -2} ;
bool isLegal(int r , int c , int n)
{
    return r >= 0 and r < n and c >= 0 and c < n ;
}

double round(double num)
{
    double ret = (int)(num*1000000.0 + 0.5)/1000000.0 ;
    return (double)ret ;
}
void solve(int n , int sx , int sy , int k)
{
    vector<vector<vector<double>>>dp(n , vector<vector<double>>(n , vector<double>(k + 1 , 0))) ;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            dp[i][j][0] = 1 ;
        }
    }
    
    for(int steps = 1 ; steps <= k ; steps++)
    {
        for(int x = 0 ; x < n ; x++)
        {
            for(int y = 0 ; y < n ; y++)
            {
                double probability = 0.0 ;
                for(int i = 0 ; i < 8 ; i++)
                {
                    int row = x + dx[i] ;
                    int col = y + dy[i] ;
                    if(isLegal(row , col , n))
                    {
                        probability += (dp[row][col][steps - 1])/8.0 ;
                    }
                }
                dp[x][y][steps] = probability ;
            }
        }
    }
    // Remember this trick of "fixed" and "setprecision" .
    cout << fixed << setprecision(6) << dp[sx][sy][k] << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int n , x , y , k ;
	    cin >> n >> x >> y >> k ;
	    solve(n , x , y , k) ;
	}
	return 0;
}
