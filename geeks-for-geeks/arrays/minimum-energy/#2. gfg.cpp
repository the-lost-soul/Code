#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size)
{
    int currEnergy = 0 , minEnergy = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        currEnergy += arr[i] ;
        // If current energy becomes negative , then increase minEnergy
        // by absolute of currEnergy and add 1 , to make energy positive .
        if(currEnergy <= 0)
        {
            minEnergy += abs(currEnergy) + 1 ;
            currEnergy = 1 ;
        }
    }
    return (minEnergy == 0) ? 1 : minEnergy ;
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
