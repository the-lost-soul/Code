#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

string solve(int arr[] , int size)
{
    int total_sum = accumulate(arr , arr + size , 0) ;
    if(total_sum%2 != 0)return "NO" ;
    int dp[2][total_sum/2 + 1] ;
    memset(dp , 0 , sizeof(dp)) ;
    for(int i = 0 ; i <= size ; i++)
    {
        for(int j = 0 ; j <= total_sum/2 ; j++)
        {
            if(i == 0)dp[0][j] = 0 ;
            else if(j == 0)dp[i%2][0] = 1 ;
            else if(arr[i - 1] > j)
            {
                dp[i%2][j] = dp[(i - 1)%2][j] ;
            }
            else
            {
                dp[i%2][j] = dp[(i - 1)%2][j] || dp[(i - 1)%2][j - arr[i - 1]] ;
            }
        }
    }
    
    return dp[size%2][total_sum/2] == 1 ? "YES" : "NO" ;
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
