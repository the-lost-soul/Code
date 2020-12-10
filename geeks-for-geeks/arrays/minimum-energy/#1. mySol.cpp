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
    int i = 0 , initEnergy = 0 , minEnergy = 0 ;
    while(i < size)
    {
        if(arr[i] > 0)
        {
            initEnergy += arr[i] ;
            i++ ;
        }
        else
        {
            while(i < size and arr[i] <= 0)
            {
                minEnergy += abs(arr[i]) ;
                i++ ;
            }
            if(minEnergy >= initEnergy)
            {
                minEnergy += 1 - initEnergy ;
                initEnergy = 1 ;
            }
            else
            {
                initEnergy -= minEnergy ;
                minEnergy = 0 ;
            }
        }
    }
    if(minEnergy != 0)return minEnergy ;
    return 1 ;
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
