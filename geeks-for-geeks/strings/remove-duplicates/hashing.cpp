#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string solve(string str)
{
    bool present[27] = {false} ;
    int len = str.length() ;
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] != ' ')present[str[i] - 'a'] = true ;
        else present[26] = true ;
    }
        
    
    string ans = "" ;
    for(int i = 0 ; i < len ; i++)
    {
        if(present[str[i] - 'a'])
        {
            ans += str[i] ;
            present[str[i] - 'a'] = false ;
        }
        else if(str[i] == ' ' and present[26] == true)
        {
            ans += str[i] ;
            present[26] = false ;
        }
    }
    return ans ;
        
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    getline(cin , str) ;
	    while(str.length() == 0)getline(cin , str) ;
	    cout << solve(str) << endl ;
	}
	return 0;
}
