#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int solve(string str)
{
    int len = str.length() ;
    int sum = 0 ;
    for(int i = 0 ; i < len ;)
    {
        int number =  0 ;
        if(isdigit(str[i]))
        {
            while(isdigit(str[i]))
            {
                number = number*10 + str[i] - '0' ;
                i++ ;
            }
        }
        else i++ ;
        sum += number ;
    }
    return sum ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    cout << solve(str) << endl ;
	}
	return 0;
}
