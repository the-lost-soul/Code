#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* The idea behind the algorithm is to store the frequrncy of
 * each character in a hash table and from this table get the 
 * frequency of character which occurred maximum .
 * Now , to re-arrange the string such that no same character
 * occurs adjacent , then the length of string must be greater
 * than 2*maxCount .
 */
int solve(string str , int length)
{
    unordered_map<char , int>hash ;
    for(int i = 0 ; i < length ; i++)
    {
        hash[str[i] - 'a']++ ;
    }
    int maxCount = INT_MIN ;
    for(auto ele : hash)
    {
        if(ele.second > maxCount)maxCount = ele.second ;
    }
    if(length >= 2*maxCount)return 1 ;
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str ;
	    cin >> str ;
	    int length = str.length() ;
	    cout << solve(str , length) << endl ;
	}
	return 0;
}
