    long ans = ((count[0]*(count[0] - 1))/2) ;

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
long solve(int arr[] , int size)
{
    long count[3] = {0} ;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i]%3 == 0)count[0]++ ;
        else if(arr[i]%3 == 1)count[1]++ ;
        else count[2]++ ;
    }
    // Form groups of 2 from numbers giving remainder 0 , on divided by 3 .
    long ans = ((count[0]*(count[0] - 1))/2) ;
    // Form group of 3 from numbers which gives remainder 0 ,
    // on divided by 3 .
    ans += ((count[0]*(count[0] - 1)*(count[0] - 2))/6) ;
    // Form groups of 3 among numbers which on divided by 3 , gives
    // remainder 1 .
    ans += ((count[1]*(count[1] - 1)*(count[1] - 2))/6) ;
    // Form groups of 3 among numbers which on divided by 3 , gives
    // remiander 2 .
    ans += ((count[2]*(count[2] - 1)*(count[2] - 2))/6) ;
    // Form group of 2's from among numbers which on divided by 3 , gives
    // remainder 1 and 2 .
    ans += count[1]*count[2] ;
    // Form group of 3's from among numbers which on divided by 3 , gives
    // remainder 0 , 1 , 2 .
    ans += count[0]*count[1]*count[2] ;
    return ans ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	int arr[size] ;
    	scanArray(arr , size) ;
	    cout << solve(arr , size) << endl ;
	}
	return 0;
}
