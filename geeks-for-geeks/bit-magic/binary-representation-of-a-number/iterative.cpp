#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void print(int num , int bit)
{
    for(int i = 14 ; i > 0 ; i--)
    {
        // Why the below statement is producing just 111...
        // when i use && operator ?
        // printf("%d" , num && (1<<(i - 1))) ;
        
        // Why the below statement is printing wrong AND operation
        // value at the position where bit is 1 ?
        // The answer to it is that after doing AND between the two
        // numbers we are printing the overall value of "num &(1<<(i-1))"
        // instead of printing whether the AND operation gives 0 or 1 .
        // printf("%d" , num & (1<<(i - 1))) ;
        if(num & (1<<(i - 1)))cout<<"1" ;
        else cout<<"0" ;
        
        // Why the below statement is not working ?
        // The compiler is showing error .
        // Because of ambiguity in << operator .
        // cout<<num & (1<<(i - 1)) ;
        // Instead of above we have to use -- cout << (num & (1<<(i - 1)) ;
    }
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
