#include<bits/stdc++.h>
#include <iostream>
using namespace std;

/* The idea here is to use 2's complement .
 * 1. Take 2's complement of the given number
 * as all bits will get reverted except the
 * first set bit from right .
 * 
 * 2. Do bit wise AND b/w num and 2's(num) i.e
 * AND b/w num & -num , this will give a number
 * having the required set-bit only .
 *
 * 3. Take log2 of the above gotten number and
 * add 1 .
 */
void print(int num)
{
    if(num)
    cout<<(log2(num & -num) + 1) ;
    else cout<<"0" ;
    
    cout<<endl ;
}

int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int num ;
	    cin >> num ;
	    print(num) ;
	}
	return 0;
}
