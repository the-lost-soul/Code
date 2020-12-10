#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int solve(string num)
{
    int len = num.length() ;
    int evenBits = 0 , oddBits = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(num[i] == '1')
        {
            if(i%2 == 0)evenBits++ ;
            else oddBits++ ;
        }
    }
    if(abs(evenBits - oddBits)%3 == 0)return 1 ;
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string num ;
	    cin >> num ;
	    cout << solve(num) << endl ;
	}
	return 0;
}
