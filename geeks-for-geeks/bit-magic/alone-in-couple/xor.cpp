#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
/* Do XOR of all element , the couple who will be
 * alone will be left and rest will cancel out when
 * doing XOR .
 */
int solve(int arr[] , int size)
{
    int alone = 0 ;
    for(int i = 0 ; i < size ; i++)alone ^= arr[i] ;
    return alone ;
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
