#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
    cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    // Create a temp array of size "size + 1" with initial
    // value equal to 0 .
    int temp[size + 1] ;
    memset(temp , 0 , sizeof(temp)) ;
    
    // For each element of array "arr" , check if temp[arr[i]]
    // is visited or not . If visited then that element id our
    // repeating element and if not visited then search ahead .
    int repeating ;
    for(int i = 0 ; i < size ; i++)
    {
        if(temp[arr[i]] == 0)temp[arr[i]] = 1 ;
        else
        {
            repeating = arr[i] ;
        }
    }
    
    // Check which cell of array "temp" has value 0 , and that
    // cell will be our missing number .
    int missing ;
    for(int i = 1 ; i <= size ; i++)
    {
        if(temp[i] == 0)
        {
            missing = i ;
            break ;
        }
    }
    cout<<repeating<<" "<<missing<<endl ;
    
    
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
	    solve(arr , size) ;
	}
	return 0;
}
