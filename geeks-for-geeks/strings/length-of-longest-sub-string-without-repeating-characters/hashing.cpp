#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(string& str)
{
    /* If a character was seen earlier then -- 
     * "start" will have the index of that cell where current
     * character was seen earlier .
     * And "last" will have the index till where we have to iterate
     * backwards to remove the contribution of characters lying b/w
     * range = [start , last] . The reason why we are removing
     * characters in this range is because all the elements present
     * before the element at index = start won't be able to contribute 
     * for the next sub-string(as sub-string needs to have unique characters) .
     */
    int start = 0 , last = 0 , currLen = 0 , maxLen = INT_MIN , len = str.length();
    int hash[26] ;
    memset(hash , -1 , sizeof(hash)) ;
    for(int i = 0 ; i < len ; i++)
    {
        if(hash[str[i] - 'a'] == -1)
        {
            hash[str[i] - 'a'] = i ;
            currLen ++ ;
        }
        else
        {
            maxLen = max(maxLen , currLen) ;
            start = hash[str[i] - 'a'] ;
            for(int j = start ; j >= last ; j--)
            {
                hash[str[j] - 'a'] = -1 ;
                currLen-- ;
            }
            // For the current character who was repeated earlier , and
            // now this character too will contribute to the newsub-string .
            currLen++ ;
            // Hash the current character as it will also contribute
            // to the new sub-string .
            hash[str[i] - 'a'] = i ;
            last = start + 1 ;
        }
    }
    // This is for the case when the longest sub-string may end
    // at last index .
    maxLen = max(maxLen , currLen) ;
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
	    cout << solve(str) << endl ;
	}
	return 0;
}
