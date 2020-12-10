#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* The problem is similar to conversion from one base to another base number */

void solve(string columnTitle)
{
    int len  = columnTitle.length() ;
    int answer = 0 ;
    for(int  i = 0 ; i < len ; i++)
        answer += ((columnTitle[i] - 'A' + 1)*(pow(26 , len - i - 1))) ;
    cout << answer << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string columnTitle ;
	    cin >> columnTitle ;
	    solve(columnTitle) ;
	}
	return 0;
}
