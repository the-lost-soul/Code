#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* g e e k s f o r g e e k s */
int solve(string str)
{
    int freq[26] = {} ;
    int slider = 0 ;
    int maxLen = INT_MIN ;
    int len = str.length() ;
    int i = 0 ;
    for(i = 0 ; i < len ; i++)
    {
        // If we have still not visited the current element , then
        // increment it's count to denote it as visited .
        if(freq[str[i] - 'a'] == 0)freq[str[i] - 'a']++ ;
        // If we found an element which was earlier visited .
        else
        {
            // Update the max contiguous sub-string length .
            maxLen = max(maxLen , i - slider) ;
            /* As the current element has been seen earlier , so
             * mark all elements from the start of current window
             * as unvisited(decrement their count) . Do this till the
             * current element has not been marked unvisited .
             * 
             * After while loop end , then slider will be pointing to
             * the next of the element in previous window due to which
             * current element was marked .
             */
            while(freq[str[i] - 'a'] != 0)
            {
                freq[str[slider] - 'a']-- ;
                slider++ ;
            }
            // Mark the current element as visited .
            freq[str[i] - 'a']++ ;
        }
    }
    /* We may get a case when the window contained all the unique
     * characters and we may not be able to update the length as
     * "else" statement of for loop won't be executed .
     */
    maxLen = max(maxLen , i - slider) ;
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
