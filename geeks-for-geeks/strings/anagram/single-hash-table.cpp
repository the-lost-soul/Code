#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* We can solve this by only using one hash table .
 * What we do is that for every character in string s1
 * we increment count in hash table and for every character
 * in string s2 we decrement count in hash table .
 * Finally we check whether all 26 slots of hash table
 * is zero or not .
 */
string solve(string s1 , string s2)
{
    int len1 = s1.length() ;
    int len2 = s2.length() ;
    if(len1 > len2 or len1 < len2)return "NO" ;
    int hash[26] = {0} ;
    for(int i = 0 ; i < len1 ; i++)
    {
        hash[s1[i] - 'a']++ ;
        hash[s2[i] - 'a']-- ;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(hash[i] != 0)return "NO" ;
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
