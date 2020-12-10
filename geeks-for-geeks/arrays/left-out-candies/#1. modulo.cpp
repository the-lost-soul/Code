#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(int students , int candies)
{
    int i = 0 ;
    while(candies != 0)
    {
        if(candies >= (i + 1))candies -= (i + 1) ;
        else return candies ;
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
