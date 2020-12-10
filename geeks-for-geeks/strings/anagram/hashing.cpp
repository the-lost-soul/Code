#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* Since we know the given strings can contain
 * alphabets only from a to z , hence we make an
 * array andd hash each alphabet with its count .
 * We do above process for both strings in a different
 * hash table for each string .
 * After this , we check whether both hash tables have
 * same frequency of alphabets or not .
 */
string solve(string s1 , string s2)
{
    int len1 = s1.length() ;
    int len2 = s2.length() ;
    if(len1 > len2 or len1 < len2)return "NO" ;
    int hash1[26] = {0} ;
    for(int i = 0 ; i < len1 ; i++)
    {
        hash1[s1[i] - 'a']++ ;
    }
    int hash2[26] = {0} ;
    for(int i = 0 ; i < len2 ; i++)
    {
        hash2[s2[i] - 'a']++ ;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(hash1[i] != hash2[i])return "NO" ;
    }
    return "YES" ;
}

int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string s1 , s2 ;
	    cin >> s1 >> s2 ;
	    cout << solve(s1 , s2) << endl ;
	}
	return 0;
}
