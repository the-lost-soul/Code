#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
/* Here we have used the same algorithm as Dutch National
 * Algorithm . Here we maintain the loop invariant that
 * arr[0...low - 1] stores 0 and arr[high..size - 1] stores
 * 1 and arr[low...high - 1] is where unknown binary are 
 * stored.
 * 1-->If low is 0 then element is at correct place and we
 *     just went ahead towards right.
 * 2-->If low is 1 then we need to put the element at it's
 *     correct position i.e to index "high" and move left .
 */
void segregate(int arr[] , int size)
{
    int low = 0 ;
    int high = size -1 ;
    while(low <= high)
    {
        if(arr[low] == 0)low ++ ;
        else if(arr[low] == 1)
        {
            swap(arr[low] , arr[high]) ;
            high -- ;
        }
    }
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cout<<arr[i]<<" " ;
    cout<<endl ;
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
	    segregate(arr , size) ;
	    print(arr , size) ;
	}
	return 0;
}
