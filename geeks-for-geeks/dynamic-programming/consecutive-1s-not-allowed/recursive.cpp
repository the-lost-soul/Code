#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;

int helper(string bin , int i , int size)
{
    if(i >= size)return 1 ;
    int ans = 0 ;
    if(bin[i - 1] != '1')
        ans += helper(bin + '1' , i + 1 , size) ;
    ans = (ans%mod + helper(bin + '0' , i + 1 , size)%mod)%mod ;
    return ans ;
}

int solve(int size)
{
    int ans = 0 ;
    string bin = "" ;
    ans += helper(bin + '0' , 1 , size) ;
    ans += helper(bin + '1' , 1 , size) ;
    return ans%mod ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
	    cout << solve(size) << endl ;
	}
	return 0;
}
