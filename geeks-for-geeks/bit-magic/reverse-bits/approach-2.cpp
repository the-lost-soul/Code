#include<bits/stdc++.h>
#include<iostream>
using namespace std;
unsigned int solve(unsigned int num)
{
    int start = 0 ;
    int end = 31 ;
    // This tells whether a particular bit from left and
    // right is set or not .
    int setFromRight = 0 ;
    int setFromLeft = 0 ;
    
    while(start <= end)
    {
        // Check whether ith bit from right is set or not .
        if(num & (1<<(start)))setFromRight = 1 ;
        else setFromRight = 0 ;
        
        // Check whether jth bit from left is set or not .
        if(num & (1<<(end)))setFromLeft = 1 ;
        else setFromLeft = 0 ;
        
        // All desired bits are getting printed correctly .
        // cout<<setFromLeft<<" "<<setFromRight<<" " ;
        
        // If jth bit from left is set , then un-set it and if
        // ith bit from right is not-set , then set it .
        // 
        if(setFromLeft and !setFromRight)
        {
            // offs the bit , which is set .
            num = num & ~(1<<(end)) ;
            // set the bit , which is un-set .
            num = num | (1<<(start)) ;
        }
        else if(!setFromLeft and setFromRight)
        {
            num = num & ~(1<<(start)) ;
            num = num | (1<<end) ;
        }
        // cout<<num<<" " ;
        start ++ ;
        end -- ;
    }
    return num ;
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
