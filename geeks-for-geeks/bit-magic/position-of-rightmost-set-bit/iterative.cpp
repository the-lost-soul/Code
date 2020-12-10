#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int num)
{
    int position = 1 ;
    if(num == 0)position = 0 ;
    else
    {
        // If we do AND of the given num with 1 , then
        // we will get 1 only when at least first bit is
        // set and till that time we have to increment
        // position .
        while(!(num & 1))
        {
            position ++ ;
            num >>= 1 ;
        }
    }
    cout<<position<<endl ;
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
