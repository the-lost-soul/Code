#include<bits/stdc++.h>
#include<iostream>
using namespace std;
struct minimum
{
    int first , second ;
} ;
struct maximum
{
    int first , second , third ;
} ;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void getMin(int arr[] , int size , minimum& minEle)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] < minEle.first)
        {
            minEle.second = minEle.first ;
            minEle.first = arr[i] ;
        }
        else if(arr[i] < minEle.second)
        {
            minEle.second = arr[i] ;
        }
    }
}

void getMax(int arr[] , int size , maximum& maxEle)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] > maxEle.first)
        {
            maxEle.third = maxEle.second ;
            maxEle.second = maxEle.first ;
            maxEle.first = arr[i] ;
        }
        else if(arr[i] > maxEle.second)
        {
            maxEle.third = maxEle.second ;
            maxEle.second = arr[i] ;
        }
        else if(arr[i] > maxEle.third)
        {
            maxEle.third = arr[i] ;
        }
    }
}
long long solve(int arr[] , int size)
{
    // Get the two minimum numbers .
    minimum minEle = {INT_MAX , INT_MAX} ;
    getMin(arr , size , minEle) ;
    
    // Get the three largest numbers .
    maximum maxEle = {INT_MIN , INT_MIN , INT_MIN} ;
    getMax(arr , size , maxEle) ;
    
    return max((long long)minEle.first*minEle.second*maxEle.first , 
                (long long)maxEle.first*maxEle.second*maxEle.third) ;
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
