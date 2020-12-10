#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void solve(int num)
{
    queue<string>q ;
    q.push("1") ;
    while(num-- > 0)
    {
        string s1 = q.front() ;
        q.pop() ;
        cout << s1 << " " ;
        string s2 = s1 + "1" ;
        q.push(s1 + "0") ;
        q.push(s2) ;
    }
    cout << endl ;
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
