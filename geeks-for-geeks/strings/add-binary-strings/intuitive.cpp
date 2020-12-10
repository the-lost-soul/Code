#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string addStr(string str1 , string str2)
{
    int len1 = str1.length() , len2 = str2.length() ;
    int carry = 0 ;
    string answer = "" ;
    // Get the binary sum till the smaller string is not finished .
    for(int i = 0 ; i < len2 ; i++)
    {
        if(str1[i] == '1' and str2[i] == '1')
        {
            if(carry == 0)
            {
                answer += '0' ;
                carry = 1 ;
            }
            else
            {
                answer += '1' ;
                carry = 1 ;
            }
        }
        else if((str1[i] == '0' and str2[i] == '1') or (str1[i] == '1' and str2[i] == '0'))
        {
            if(carry == 0)
            {
                answer += '1' ;
                carry = 0 ;
            }
            else
            {
                answer += '0' ;
                carry = 1 ;
            }
        }
        else
        {
            if(carry == 0)
            {
                answer += '0' ;
                carry = 0 ;
            }
            else
            {
                answer += '1' ;
                carry = 0 ;
            }
        }
    }
    for(int i = len2 ; i < len1 ; i++)
    {
        if(str1[i] == '1')
        {
            if(carry == 0)
            {
                answer += '1' ;
                carry = 0 ;
            }
            else
            {
                
                answer += '0' ;
                carry = 1 ;
            }
        }
        else
        {
            if(carry == 0)
            {
                answer += '0' ;
                carry = 0 ;
            }
            else
            {
                answer += '1' ;
                carry = 0 ;
            }
        }
    }
    if(carry == 1)answer += '1' ;
    reverse(answer.begin() , answer.end()) ;
    return answer ;
}
string solve(string str1 , string str2)
{
    int len1 = str1.length() , len2 = str2.length() ;
    reverse(str1.begin() , str1.end()) ;
    reverse(str2.begin() , str2.end()) ;
    if(len1 >= len2)return addStr(str1 , str2) ;
    return addStr(str2 , str1) ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str1 , str2 ;
	    cin >> str1 >> str2 ;
	    cout << solve(str1 , str2) << endl ;
	}
	return 0;
}
