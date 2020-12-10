#include<bits/stdc++.h>
#include<iostream>
using namespace std;

string solve(string num1 , string num2)
{
    int len1 = num1.length() - 1;
    int len2 = num2.length() - 1;
    
    string sum = "" ;
    int carry = 0 ;
    int digits = 0 ;
    int add = 0 ;
    while(len1 >= 0 and len2 >= 0)
    {
        add = num1[len1] - '0' + num2[len2] - '0' + carry;
        sum += to_string(add%10) ;
        carry = add/10 ;
        len1-- ;
        len2-- ;
        digits++ ;
        
    }
    if(len2 < 0)
    {
        while(len1 >= 0)
        {
            add = num1[len1] - '0' + carry ;
            sum += to_string(add%10) ;
            carry = add/10 ;
            len1-- ;
            digits++ ;
        }
    }
    else if(len1 < 0)
    {
        while(len2 >= 0)
        {
            add = num2[len2] - '0' + carry ;
            sum += to_string(add%10) ;
            carry = add/10 ;
            len2-- ;
            digits++ ;
        }
    }
    
    // We may get a situation where we are stll left with
    // some carry after doing all operations .
    if(carry > 0)
    {
        sum += to_string(carry) ;
        digits++ ;
    }
    // reverse the answer .
    reverse(sum.begin() , sum.end()) ;

    if(digits == num1.length())
    return sum ;
    else return num1 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string num1 , num2 ;
	    cin >> num1 >> num2 ;
	    cout << solve(num1 , num2) << endl ;
	}
	return 0;
}
