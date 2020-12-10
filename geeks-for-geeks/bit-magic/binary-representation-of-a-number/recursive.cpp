#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int num , int bit)
{
    if(bit > 1)
    print(num>>1 , bit - 1) ;
    
    printf("%d" , num & 1) ;
}

int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int num ;
	    cin >> num ;
	    print(num , 14) ;
	    cout<<endl ;
	}
	return 0;
}
