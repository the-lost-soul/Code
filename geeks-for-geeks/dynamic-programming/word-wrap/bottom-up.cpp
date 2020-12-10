#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

int printSolution(vector<int>parent , int size)
{
    if(parent[size] == 1)
    {
        cout << 1 << " " << size << " " ;
        return 1 ;
    }
    
    int k = printSolution(parent , parent[size] - 1) + 1 ;
    cout << parent[size] << " " << size  << " " ;
    return k ;
}
void solve(int arr[] , int size , int lineLen)
{
    vector<int>cumulativeWordLen(size + 1 , 0) ;
    for(int i = 1 ; i <= size ; i++)
    {
        cumulativeWordLen[i] = cumulativeWordLen[i - 1] + arr[i - 1] ;
        // cout << cumulativeWordLen[i] << "  " ;
    }
    // cout << endl ;
    vector<vector<int>>dp(size + 1 , vector<int>(size + 1 , 0)) ;
    
    for(int i = 1 ; i <= size ; i++)
    {
        for(int j = i ; j <= size ; j++)
        {
            int spaces = lineLen - (cumulativeWordLen[j] - cumulativeWordLen[i] + arr[i - 1] + j - i) ;
            if(j == size and spaces >= 0)dp[i][j] = 0 ;
            else dp[i][j] = spaces >= 0 ? spaces*spaces : INT_MAX ;
        }
    }
    
    
    vector<int>parent(size + 1) , cost(size + 1 , INT_MAX) ;
    cost[0] = 0 ;
    for(int till = 1 ; till <= size ; till++)
    {
        for(int from = 1 ; from <= till ; from++)
        {
            if(cost[from - 1] != INT_MAX and dp[from][till] != INT_MAX and
            (cost[from - 1] + dp[from][till] < cost[till]))
            {
                cost[till] = cost[from - 1] + dp[from][till] ;
                parent[till] = from ;
            }
        }
    }
    
    printSolution(parent , size) ;
    
    // for(int i = 1 ; i <= size ; i++)
    // {
    //     for(int j = 1 ; j <= size ; j++)
    //     {
    //         cout << dp[i][j] << "  " ;
    //     }
    //     cout << endl ;
    // }
    cout << endl ;
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
    	int lineLen ;
    	cin >> lineLen ;
	    solve(arr , size , lineLen) ;
	}
	return 0;
}
