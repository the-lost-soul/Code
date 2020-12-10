#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(string num)
{
    int len  = num.length() - 1 ;
    /* If the last number is less than or equal to 5
     * then it can be rounded to the nearest (here previous)
     * multiple of 10 , just by replacing last char by 0 .
     */
    if(num[len] <= '5')
    {
        num[len] = '0' ;
        cout << num << endl ;
    }
    else
    {
        int currDigit = num[len] - '0' ;
        num[len] = '0' ;
        int carry = 1 ;
        len-- ;
        // While string is not empty and there is carry to add
        // to next char .
        while(carry == 1 and len >= 0)
        {
            currDigit = num[len] - '0' ;
            currDigit += carry ;
            if(currDigit > 9)
            {
                carry = 1 ;
                currDigit = 0 ;
            }
            else carry = 0 ;
            num[len] = (char)(currDigit + '0') ;
            len-- ;
        }
        if(carry == 1)cout << 1 ;
        cout << num << endl ;
    }
}

int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string num ;
	    cin >> num ;
	    solve(num) ;
	}
	return 0;
}
