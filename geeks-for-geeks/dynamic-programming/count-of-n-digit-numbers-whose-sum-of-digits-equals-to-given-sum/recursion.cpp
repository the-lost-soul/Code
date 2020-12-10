#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;
long helper(int digit , int sum)
{
    if(digit == 0)return sum == 0 ;
    if(sum == 0)return 1 ;
    long ans = 0 ;
    for(int i = 0 ; i <= 9 ; i++)
    {
        if(sum - i >= 0) ans += helper(digit - 1 , sum - i)%mod ;
    }
    return ans ;
}
long solve(int digit , int sum)
{
    long ans = 0 ;
    for(int i = 1 ; i <= 9 ; i++)
    {
        if(sum - i >= 0)
            ans += helper(digit - 1 , sum - i)%mod ;
    }
    return ans ;
}
int main()
{
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int digit , sum ;
	    cin >> digit >> sum ;
	    cout << solve(digit , sum) << endl ;
	}
	return 0;
}
