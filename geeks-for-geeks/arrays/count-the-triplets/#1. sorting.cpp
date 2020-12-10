#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

int solve(int arr[] , int size)
{
    int triplets = 0 ;
    sort(arr , arr + size) ;
    int j , k ;
    for(int i = size - 1 ; i >= 0 ; i--)
    {
        j = 0 ;
        k = i - 1 ;
        while(k > j)
        {
            if(arr[i]  == arr[k] + arr[j])
            {
                triplets ++ ;
                j ++ ;
            }
            else if(arr[i] > arr[j] + arr[k])j++ ;
            else k -- ;
        }
    }
    if(triplets == 0)return - 1;
    else return triplets ;
    
    
}
int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int size ;
	    cin >> size ;
	    int arr[size] ;
	    scan(arr , size) ;
	    cout<<solve(arr , size) <<" "<<endl ;
	}
	return 0;
}
