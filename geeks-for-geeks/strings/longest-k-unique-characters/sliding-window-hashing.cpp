#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string str , int k)
{
    int hash[26] = {0} ;
    int windowStart = 0 , maxLen = INT_MIN , len = str.length() , count = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        // If current character is unique , then increase count .
        if(hash[str[i] - 'a'] == 0)count++ ;
        hash[str[i] - 'a']++ ;
        /* If the count of unique characters becomes more than k .
         * Then , start removing the undesirable elements one by one
         * from left side till count is not less than or equal to k .
         */
        while(count > k)
        {
            hash[str[windowStart] - 'a']-- ;
            if(hash[str[windowStart]- 'a'] == 0)count-- ;
            windowStart++ ;
        }
        // Update length of sub - string .
        if(count == k)maxLen = max(maxLen , i - windowStart + 1) ;
    }
    if(maxLen == INT_MIN)return -1 ;
    return maxLen ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    int k ;
	    cin >> k ;
	    cout << solve(str , k) << endl ;
	}
	return 0;
}
