#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(string str , int len)
{
    int freq[26] = {} ;
    for(int i = 0 ; i < len ; i++)
    {
        freq[str[i] - 'a']++ ;
    }
    for(int i = 0 ; i < len ; i++)
    {
        if(freq[str[i] - 'a'] == 1)
        {
            cout << str[i] << endl ;
            return ;
        }
    }
    cout << -1 << endl ;
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int len ;
	    cin >> len ;
	    string str ;
	    cin >> str ;
	    solve(str , len) ;
	}
	return 0;
}
