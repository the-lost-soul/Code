#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string expr)
{
    int len = expr.length() ;
    int i = 0 , count = 0 ;
    while(i < len)
    {
        // If current character is '1' .
        if(expr[i] == '1')
        {
            bool min1Zero = false ;
            i++ ;
            // Loop till we are getting zero
            while(expr[i] == '0')
            {
                i++ ;
                min1Zero = true ;
            }
            // If we get '1' and last character was '0' , then
            // we get a regular expression of form (10*1)
            if(expr[i] == '1' and min1Zero)count++ ;
        }
        else i++ ;
    }
    return count ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string expr ;
	    cin >> expr ;
	    cout << solve(expr) << endl ;
	}
	return 0;
}
