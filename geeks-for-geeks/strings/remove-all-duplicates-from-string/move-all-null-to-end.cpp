#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(string str)
{
    int len = str.length() ;
    unordered_set<char>hash ;
    for(int i = 0 ; i < len ; i++)
    {
        if(hash.find(str[i]) != hash.end())str[i] = '\0' ;
        else hash.insert(str[i]) ;
    }
    int nullVal = 0 ;
    // Move all terminating values to end , keeping the order
    // of rest elements preserved .
    for(int i = 0 ; i < len ; i++)
    {
        if(str[i] != '\0')
        {
            swap(str[nullVal] , str[i]) ;
            nullVal++ ;
        }
    }
    int i = 0 ;
    while(str[i] != '\0')
    {
        cout << str[i] ;
        i++ ;
    }
    cout << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    solve(str) ;
	}
	return 0;
}
