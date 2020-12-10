#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string solve(string str)
{
    int len = str.length() ;
    int start = 0 , end = 0 , maxLen = 1 , startIndex = 0 ;
    for(int i = 1 ; i < len ; i++)
    {
        // Get the even pallindrome length . Expand the string
        // around a center .
        start = i-1 , end = i ;
        while(start >= 0 and end < len and str[start] == str[end])
        {
            if(end - start + 1 > maxLen)
            {
                maxLen = end - start + 1 ;
                startIndex = start ;
            }
            start-- ;
            end++ ;
        }
        // Get the odd length pallindrome .
        start = i-1 , end = i+1 ;
        while(start >= 0 and end < len and str[start] == str[end])
        {
            if(end - start + 1 > maxLen)
            {
                maxLen = end - start + 1 ;
                startIndex = start ;
            }
            start-- ;
            end++ ;
        }
    }
    return str.substr(startIndex , maxLen) ;
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
	return 0 ;
}
