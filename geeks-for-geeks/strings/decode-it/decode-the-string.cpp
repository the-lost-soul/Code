#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char solve(string str , int index)
{
    int len = str.length() ;
    int i = 0 ;
    string decodedStr = "" ;
    while(i < len)
    {
        string tempStr = "" ;
        // Add the current word till we dont encounter a digit .
        while((i < len) and (str[i] >= 'a' and str[i] <= 'z'))
        {
            tempStr += str[i] ;
            i++ ;
        }
        // Concatenate the current word to earlier string .
        decodedStr += tempStr ;
        tempStr = decodedStr ;
        // Concatenate the new string to the earlier string , the number
        // of times it should be concatenated .
        for(int j = 1 ; j < (str[i] - '0') ; j++)decodedStr += tempStr ;
        i++ ;
    }
    return decodedStr[index - 1] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    int index ;
	    cin >> index ;
	    cout << solve(str , index) << endl ;
	}
	return 0;
}
