#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int countSetBits(int num)
{
    int count = 0 ;
    while(num)
    {
        if(num & 1)count ++ ;
        num = num>>1 ;
    }
    return count ;
}
bool solve(int num)
{
    // Base Case .
    if(num == 0)return true ;
    
    // Check for all numbers , whether they are bleak or not .
    for(int i = num - 1 ; i >= 0 ; i--)
    {
        if(num == i + countSetBits(i))return true ;
    }
    return false ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int num ;
	    cin >> num ;
	    if(solve(num))cout<<"0"<<endl ;
	    else cout<<"1"<<endl ;
	}
	return 0;
}
