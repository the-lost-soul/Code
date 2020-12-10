#include<bits/stdc++.h>
#include<iostream>
using namespace std;
unsigned int solve(unsigned int num)
{
    int start = 0 ;
    int end = 31 ;
    unsigned int result  = 0 ;
    while(num)
    {
        // If the first bet is set , then set the *end* bit
        // to 1 .
        if(num & 1)
        {
            // Store the result .
            result = result | (1<<end) ;
        }
        // Shift the original number one bit towards right .
        num = num>>1 ;
        start ++ ;
        end -- ;
    }

    return result ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    unsigned int num ;
	    cin >> num ;
	    cout<<solve(num)<<endl ;
	}
	return 0;
}
