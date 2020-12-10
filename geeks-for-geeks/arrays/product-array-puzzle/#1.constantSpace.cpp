#include<iostream>
using namespace std;
void scanArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
}
void solve(int arr[] , int size)
{
    int product = 1 ;
    for(int i = 0 ; i < size ; i++)
    {
        product *= arr[i] ;
    }
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = product/arr[i] ;
    }
}
void printArray(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)cout << arr[i] << " " ;
    cout << endl ;
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
	    printArray(arr , size) ;
	}
	return 0;
}
