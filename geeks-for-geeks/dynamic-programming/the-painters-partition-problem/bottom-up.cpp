#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int partition(int arr[] , int board , int painters)
{
    vector<int>cumulative_sum(board , 0) ;
    cumulative_sum[0] = arr[0] ;
    for(int i = 1 ; i < board ; i++)cumulative_sum[i] = arr[i] + cumulative_sum[i - 1] ;
    
    vector<vector<int>> dp(painters + 1 , vector<int>(board + 1 , 0)) ;
    for(int b = 1 ; b <= board ; b++)dp[1][b] = cumulative_sum[b - 1] ;
    for(int p = 1 ; p <= painters ; p++)dp[p][1] = arr[0] ;
    
    
    for(int p = 2 ; p <= painters ; p++)
    {
        for(int b = 2 ; b <= board ; b++)
        {
            int best = INT_MAX ;
            for(int k = 1 ; k <= b ; k++)
            {
                best = min(best , max(dp[p - 1][k] , cumulative_sum[b - 1] - cumulative_sum[k - 1])) ;
            }
            dp[p][b] = best ;
        }
    }
    return dp[painters][board] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int painters , board ;
    	cin >> painters >> board ;
    	int arr[board] ;
    	scanArray(arr , board) ;
	    cout << partition(arr , board , painters) << endl ;
	}
	return 0;
}
