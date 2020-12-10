#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(long int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
int countSameSetBits(long int num1 , long int num2)
{
    long int num = num1 ^ num2 ;
    int count = 0 ;
    while(num)
    {
        if(num & 1)count++ ;
        num = num >> 1 ;
    }
    return count ;
}
int solve(long int arr[] , int size)
{
    int sum = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            sum += countSameSetBits(arr[i] , arr[j]) ;
        }
    }
    return sum%10000007 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
	    cin >> size ;
	    long int arr[size] ;
	    scanArray(arr , size) ;
	    cout<<solve(arr , size)<<endl ;
	}
	return 0;
}
