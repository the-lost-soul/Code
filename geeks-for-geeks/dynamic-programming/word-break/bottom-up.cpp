#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(unordered_set<string>& dictionary , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        string str ;
        cin >> str ;
        dictionary.insert(str) ;
    }
}
int solve(string word , unordered_set<string>dictionary)
{
    int len = word.length() ;
    if(len == 0)return 1 ;
    vector<int>dp(len + 1 , 0) ;
    for(int i = 1 ; i <= len ; i++)
    {
        if(dp[i] == 0 and dictionary.find(word.substr(0 , i)) != dictionary.end())
            dp[i] = 1 ;
            
        if(dp[i] == 1)
        {
            if(i == len)return 1 ;
            for(int j = i + 1 ; j <= len ; j++)
            {
                if(dp[j] == 0 and dictionary.find(word.substr(i , j - i)) != dictionary.end())
                    dp[j] = 1 ;
                
                if(j == len and dp[j])return 1 ;
            }
        }
    }
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	unordered_set<string>dictionary ;
    	scanArray(dictionary , size) ;
    	string word ;
    	cin >> word ;
	    cout << solve(word , dictionary) << endl ;
	}
	return 0;
}
