#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/* On doing (num & ~(num - 1)) , we get a number whose first
 * bit from right is set . So , if a number is even then on
 * doing the above operation we will get the same number again
 * as an even number has only one bit set .
 */
bool solve(unsigned long long int num)
{
    // Base case .
    if(num == 0)return false ;
    if((num & ~(num - 1)) == num)return true ;
    else return false ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    unsigned long long int num ;
    	cin >> num ;
	    if(solve(num))cout<<"YES"<<endl ;
	    else cout<<"NO"<<endl ;
	}
	return 0;
}
