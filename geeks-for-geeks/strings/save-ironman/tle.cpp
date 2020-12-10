#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string solve(string str , int len)
{
    int left = 0 , right = len-1 ;
    int ele1 = 0 , ele2 = 0 ;
    int digitLeft = 0 , digitRight = 0 ;
    int alphaLeft = 0 , alphaRight = 0 ;
    while(left < right)
    {
        digitLeft = isdigit(str[left]) ;
        digitRight = isdigit(str[right]) ;
        alphaLeft = isalpha(str[left]) ;
        alphaRight = isalpha(str[right]) ;
        // If first and last characters are numbers .
        if(digitLeft != 0 and digitRight != 0) 
        {
            ele1 = str[left] - '0' ;
            ele2 = str[right] - '0' ;
            left++ ;
            right-- ;
        }
        // If first and last characters are alphabets .
        else if(alphaLeft != 0 and alphaRight != 0)
        {
            if(isupper(str[left]) != 0) ele1 = str[left] - 'A' ;
            else ele1 = str[left] - 'a' ;
            
            if(isupper(str[right]) != 0)ele2 = str[right] - 'A' ;
            else ele2 = str[right] - 'a' ;
            left++ ;
            right-- ;
        }
        else
        {
            if(alphaLeft == 0 and digitLeft == 0)left++ ;
            if(alphaRight == 0 and digitRight == 0)right-- ;
        }
        if(ele1 != ele2)return "NO" ;
    }
    return "YES" ;
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
	    cout << solve(str , str.length()) << endl ;
	}
	return 0;
}
