#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string makeStrictlyDecreasing(string& answer , int start , int end)
{
    while(start <= end)
    {
        swap(answer[start] , answer[end]) ;
        start++ ;
        end-- ;
    }
    return answer ;
}
string solve(string pattern)
{
    string answer = "" ;
    int len = pattern.length() ;
    stack<int>index ;
    for(int i = 0 ; i <= len ; i++)
    {
        index.push(i+1) ;
        /* If all characters are processed or current character
         * is increasing that means all characters behind it is 
         * decreasing hence pop from stack to get all numbers in
         * decreasing order .
         */
        if(i == len || pattern[i] == 'I')
        {
            while(!index.empty())
            {
                answer += to_string(index.top()) ;
                index.pop() ;
            }
        }
    }
    return answer ;
    
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string pattern ;
	    cin >> pattern ;
	    cout << solve(pattern) << endl ;
	}
	return 0;
}
