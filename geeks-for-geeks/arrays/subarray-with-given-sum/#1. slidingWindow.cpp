#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}

/* The idea is to maintain sumSoFar and a variable 
 * "start" which tells index from where our window 
 * started so that  it is giving the required sum . 
 * If at any ith index  we get the the "sumSoFar" greater
 * than required "sum" , then subtract all elements from 
 * maxSoFar till the time we get maxSoFar less than the
 * required sum , for doing this step start subtracting 
 * from the index equal to "start" .
 */
pair<int , int> solve(int arr[] , int size , int sum)
{
    int sumSoFar = 0 ;
    int start = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        sumSoFar += arr[i] ;
        while(sumSoFar > sum)
        {
            sumSoFar -= arr[start] ;
            start ++ ;
        }
        if(sumSoFar == sum)return make_pair(start + 1 , i + 1) ;
    }
    return make_pair(-1 , -1) ;
    
}
int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int size , sum ;
	    cin >> size >> sum ;
	    int arr[size] ;
	    scan(arr , size) ;
	    pair<int , int>solution = solve(arr , size , sum) ;
	    if(solution.first == -1)cout<<"-1"<<endl ;
	    else if(solution.second >= size)cout<<solution.first<<" "<< size << endl ;
	    else cout<<solution.first<<" "<<solution.second<<endl ;
	}
	return 0;
}
