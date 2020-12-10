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
    int max = arr[0] , answer = -1 ;
    for(int i = 1 ; i < size ; i++)
    {
        if(arr[i] >= max)
        {
            max = arr[i] ;
            if(answer == -1 and i < size-1)
            {
                answer = max ;
            }
        }
        else if(arr[i] < answer) answer = -1 ;
    }
    return answer ;
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
