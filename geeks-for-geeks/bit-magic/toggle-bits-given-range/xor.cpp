#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/* The idea here is to use XOR .
 * Do XOR of given num with shifted 1 . Start shifting
 * from "start" position and do XOR with num and do this
 * till we reach "end" position .
 */
int print(int num , int start , int end)
{
    while(start <= end)
    {
        num = num ^ (1<<(start - 1)) ;
        start ++ ;
    }
    
    return num ;
}

int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int num , start , end ;
	    cin >> num >> start >> end ;
	    cout << print(num , start , end) << endl ;
	}
	return 0;
}
