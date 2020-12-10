#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* The pattern is building something like this , initially for n == 1 
 * we have 1 , and then for n == 2 , we have one 1 i.e count of digit
 * preceding the number which we have counted .
 * For n == 3 , we will have two 1 i.e 21 as answer .
 * For n == 4 , we will have one 2 one 1 i.e 1211 .
 */ 
string solve(int num)
{
    if(num == 1)return "1" ;
    if(num == 2)return "11" ;
    string answer = "11" ;
    string temp = "" ;
    int count = 1 ;
    for(int i = 3 ; i <= num ; i++)
    {
        answer += "$" ;
        temp = "" ;
        int len = answer.length() ;
        for(int j = 1 ; j < len ; j++)
        {
            if(answer[j] != answer[j - 1])
            {
                temp += to_string(count) ;
                temp += answer[j - 1] ;
                count = 1 ;
            }
            else count++ ;
        }
        answer = temp ;
    }
    return answer ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int num ;
    	cin >> num ;
	    cout << solve(num) << endl ;
	}
	return 0;
}
