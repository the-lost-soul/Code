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
    // Keep track of last max number inserted in string and it's index .
    int maxIndex = 0 , maxNum = 2 ;
    
    // If first element of pattern is 'D' , then concatenate
    // 21 . The reason we are concatenating 21 is because we want
    // the result to be minimum .
    if(pattern[0] == 'D')
    {
        answer += to_string(21) ;
        maxIndex = 0 ;
    }
    if(pattern[0] == 'I')
    {
        answer += to_string(12) ;
        maxIndex = 1 ;
    }
    int i = 1 , currNum = 3 , len = pattern.length() ;
    while(i < len)
    {
        // Till we get a 'D' , add currNum to answer string and
        // after insertion swap the currNum with the maxNum .
        while(i < len and pattern[i] == 'D')
        {
            answer += to_string(currNum) ;
            
            // Newly added element will be at index (i+1) because
            // the answer string will be of length (len+1) .
            swap(answer[maxIndex] , answer[i+1]) ;
            i++ ;
            maxNum = currNum ;
            currNum++ ;
        }
        
        // Finally after completion of above step , all the elements
        // from index (maxIndex , i] will be in increasing order so
        // make that sub-string strictly decreasing .
        answer = makeStrictlyDecreasing(answer , maxIndex + 1 , i) ;
        
        // Add currNum to answer string till we are encountering a 'I'
        // and simultaneously update maxNum and maxIndex .
        while(i < len and pattern[i] == 'I')
        {
            answer += to_string(currNum) ;
            i++ ;
            maxNum = currNum ;
            maxIndex = i ;
            currNum++ ;
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
