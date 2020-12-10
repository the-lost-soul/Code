#include<bits/stdc++.h>
#include<iostream>
using namespace std;
pair<string , int> solve(string str)
{
    unordered_map<string , int>hash ;
    int len = str.length() , i = 0 ;
    // Hash each word of the given sentence .
    while(i < len)
    {
        string tempStr = "" ;
        while(i < len and !isspace(str[i]))
        {
            tempStr += str[i] ;
            i++ ;
        }
        hash[tempStr]++ ;
        i++ ;
    }
    string word = "" ;
    int count = INT_MIN ;
    i = 0 ;
    // Get the word with maximum frequency .
    while(i < len)
    {
        string tempStr = "" ;
        while(i < len and !isspace(str[i]))
        {
            tempStr += str[i] ;
            i++ ;
        }
        if(count < hash[tempStr])
        {
            word = tempStr ;
            count = hash[tempStr] ;
        }
        i++ ;
    }
    return {word , count} ;
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
	    pair<string , int>answer = solve(str) ;
	    cout << answer.first << " " << answer.second << endl ;
	}
	return 0;
}
