#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(string s)
{
    int upper = 0 , lower = 0 , num = 0 , special = 0 ;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] >= 'A' and s[i] <= 'Z')upper++ ;
        else if(s[i] >= 'a' and s[i] <= 'z')lower++ ;
        else if(s[i] >= '0' and s[i] <= '9')num++ ;
        else special++ ;
    }
    cout<<upper<<endl<<lower<<endl<<num<<endl<<special<<endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string s ;
	    cin >> s ;
	    solve(s) ;
	}
	return 0;
}
