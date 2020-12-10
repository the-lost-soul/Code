#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string s)
{
    
    stack<int>index ;
    index.push(-1) ;
    int len = s.length() ;
    int result = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i] == '(')index.push(i) ;
        else
        {
            index.pop() ;
            if(!index.empty())result = max(result , i - index.top()) ;
            else index.push(i) ;
        }
    }
    return result ;
}

int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string s ;
	    cin >> s ;
	    cout<<solve(s)<<endl ;
	}
	return 0;
}
