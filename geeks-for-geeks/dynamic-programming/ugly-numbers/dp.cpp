#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<unsigned long> solve(int n)
{
    vector<unsigned long>ugly(n  , 0) ;
    ugly[0] = 1 ;
    unsigned long multiple_of_2 = 2 ;
    unsigned long multiple_of_3 = 3 ;
    unsigned long multiple_of_5 = 5 ;
    int i2 = 0 , i3 = 0 , i5 = 0 ;
    for(int i = 1 ; i < n ; i++)
    {
        ugly[i] = min(multiple_of_2 , min(multiple_of_3 , multiple_of_5)) ;
        if(ugly[i] == multiple_of_2)
        {
            i2++ ;
            multiple_of_2 = ugly[i2]*2 ;
        }
        if(ugly[i] == multiple_of_3)
        {
            i3++ ;
            multiple_of_3 = ugly[i3]*3 ;
        }
        if(ugly[i] == multiple_of_5)
        {
            i5++ ;
            multiple_of_5 = ugly[i5]*5 ;
        }
    }
    return ugly ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	vector<unsigned long>ans = solve(10000) ;
	while(testcase--)
	{
	    int n ;
	    cin >> n ;
	    cout << ans[n - 1] << endl ;
	}
	return 0;
}
