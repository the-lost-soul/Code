#include <iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
    
}
int solve(int arr[] , int size)
{
    // Stores the maximum bar to the
    // left of i'th bar
    int left[size] ; 
    
    // Stores maximum bar to the right
    // of i'th bar
    int right[size] ;
    // Fill left array
    left[0] = arr[0] ;
    for(int i = 1 ; i < size ; i++)
        left[i] = max(left[i - 1] , arr[i]) ;
    
    // Fill right array
    right[size-1]=arr[size-1];
    for(int i = size - 2; i >= 0 ; i--)
        right[i] = max(right[i + 1] , arr[i]) ;
    
    // This stores the amount of water
    int result = 0 ;
    for(int i = 0 ; i < size ; i++)
        result += min(left[i] , right[i]) - arr[i] ;
    
    return result ;
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase--)
    {
        int size ;
        cin >> size ;
        int arr[size];
        scanArray(arr , size) ;
        cout << solve(arr , size) << endl ;
    }
    return 0 ;
}

