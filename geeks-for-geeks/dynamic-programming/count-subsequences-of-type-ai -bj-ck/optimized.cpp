#include<bits/stdc++.h>
#include<iostream>
using namespace std;
const int mod = 1e9 + 7 ;
long solve(string str)
{
    int n = str.size() ;
    long aCount = 0 , bCount = 0 , cCount = 0 ;
    for(int i = 1 ; i <= n ; i++)
    {
        if(str[i - 1] == 'a')
        {
            aCount = 1 + 2*aCount ;
        }
        else if(str[i - 1] == 'b')
        {
            bCount = bCount*2 + aCount ;
        }
        else if(str[i - 1] == 'c')
        {
            cCount = cCount*2 + bCount ;
        }
    }
    return cCount ;
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
