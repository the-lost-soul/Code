#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void solve(int num)
{
    string answer = "" ;
    int remain = 0 ;
     while(num)
     {
         remain = num%26 ;
         /* If reainder is zero then that means "Z" , and hence
          * we add "Z" to string and then divide the number by 26
          * and subtract 1 from it .The reason for subtracting is
          * "Z" is at 25th position with respect to "A" .
          */
         if(remain == 0)
         {
             answer += "Z" ;
             num = (num/26) - 1 ;
         }
         else 
         {
             answer += char(remain) + 'A' - 1 ;
             num = num/26 ;
         }
         
     }
     reverse(answer.begin() , answer.end()) ;
     cout << answer << endl ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int num ;
    	cin >> num ;
	    solve(num) ;
	}
	return 0;
}
