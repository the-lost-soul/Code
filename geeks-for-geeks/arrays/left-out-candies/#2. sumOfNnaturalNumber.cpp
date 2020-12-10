#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(int students , int candies)
{
    /* As every ith student is getting i candies , hence it is 
     * something like some of n natural numbers .
     * Hence , we first find the number of candies which can be
     * uniformly distributed to all students .
     */
    int uniformDistribution = (students*(students + 1))/2 ;
    // Now we get the candies which are remaining , and we check
    // whether we can distribute these candies to students or not .
    int leftOutCandies = candies%uniformDistribution ;
    int i = 0 ;
    while(leftOutCandies != 0)
    {
        if(leftOutCandies >= (i + 1))leftOutCandies -= (i + 1) ;
        else return leftOutCandies ;
        i = (i + 1)%students ;
    }
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int students , candies ;
    	cin >> students >> candies ;
	    cout << solve(students , candies) << endl ;
	}
	return 0;
}
