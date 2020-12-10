#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* We can use bit wise XOR , if both are anagram
 * then XOR will be zero , else non zero . This should
 * be used only when both strings have same length .
 * If they have different lengths , then we may get
 * wrong result .
 * eg -- s1 = aa , s2 == aaaa ,here XOR = 0 , but they
 * are not anagram .
 */
string solve(string s1 , string s2)
{
    int len1 = s1.length() ;
    int len2 = s2.length() ;
    if(len1 > len2 or len1 < len2)return "NO" ;
    int value = 0 ;
    for(int i = 0 ; i < len1 ; i++)
    {
        value ^= (int)s1[i] ;
        value ^= (int)s2[i] ;
    }
    if(value != 0)return "NO" ;
    else return "YES" ;
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
