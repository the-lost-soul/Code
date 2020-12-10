#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

void optimalCost(int arr[] , int size, vector<vector<int>>& dp , vector<vector<int>>& brackets)
{
    for(int len = 2 ; len < size ; len++)
    {
        for(int s = 1 ; s < size - len + 1 ; s++)
        {
            int e = s + len - 1 ;
            dp[s][e] = INT_MAX ;
            for(int k = s ; k <= e - 1 ; k++)
            {
                int currCost = dp[s][k] + dp[k + 1][e] + arr[s - 1]*arr[k]*arr[e] ;
                if(dp[s][e] > currCost)
                {
                    dp[s][e] = currCost ;
                    brackets[s][e] = k ;
                }
            }
        }
    }
    
}

void putBrackets(int i , int j , char& ch , vector<vector<int>>& brackets)
{
    if(i == j)
    {
        cout << ch ;
        ch++ ;
        return ;
    }
    
    cout << "(" ;
    
    putBrackets(i , brackets[i][j] , ch , brackets) ;
    putBrackets(brackets[i][j] + 1 , j , ch , brackets) ;
    cout << ")" ;
}
void solve(int arr[] , int size)
{
    vector<vector<int>>dp(size , vector<int>(size , 0)) ;
    vector<vector<int>>brackets(size , vector<int>(size , 0)) ;

    optimalCost(arr , size , dp , brackets) ;
    char ch = 'A' ;
    putBrackets(1 , size - 1 , ch , brackets) ;
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
	    solve(arr , size) ;
	}
	return 0;
}
