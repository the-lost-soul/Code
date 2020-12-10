#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void getAllPallindromes(string str , vector<vector<bool>>& pallindrome)
{
    int len = str.length() ;
    for(int i = 0 ; i < len ; i++)
    {
        pallindrome[i][i] = true ;
    }
    
    for(int i = 0 ; i < len - 1 ; i++)
    {
        pallindrome[i][i + 1] = str[i] == str[i + 1] ;
    }
    
    for(int length = 3 ; length <= len ; length++)
    {
        for(int i = 0 ; i <= len - length ; i++)
        {
            int j = i + length - 1 ;
            pallindrome[i][j] = str[i] == str[j] ? pallindrome[i + 1][j - 1] : false ;
        }
    }
}

int getMinCut(vector<vector<bool>>pallindrome)
{
    int len = pallindrome.size() ;
    vector<int>minCut(len , INT_MAX) ;
    for(int i = 0 ; i < len ; i++)
    {
        if(pallindrome[0][i])
        {
            minCut[i] = 0 ;
        }
        else
        {
            int j = i - 1 ;
            while(j >= 0)
            {
                if(pallindrome[j + 1][i])
                {
                    minCut[i] = min(minCut[i] , 1 + minCut[j]) ;
                }
                j-- ;
            }
        }
    }
    return minCut[len - 1] ;
}
int solve(string str)
{
    int len = str.length() ;
    vector<vector<bool>>pallindrome(len , vector<bool>(len , false)) ;
    getAllPallindromes(str , pallindrome) ;
    
    int minCut = getMinCut(pallindrome) ;
    return minCut ;
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
	return 0;
}
