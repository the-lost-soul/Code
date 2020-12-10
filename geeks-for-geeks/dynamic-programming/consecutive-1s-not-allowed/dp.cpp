#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;

int solve(int size)
{
    vector<int>endAtOne(size , 0) , endAtZero(size , 0) ;
    endAtOne[0] = 1 ;
    endAtZero[0] = 1 ;
    for(int i = 1 ; i < size ; i++)
    {
        endAtZero[i] = (endAtZero[i - 1]%mod + endAtOne[i - 1]%mod)%mod ;
        endAtOne[i] = endAtZero[i - 1] ;
    }
    return (endAtZero[size - 1] + endAtOne[size - 1])%mod ;
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
