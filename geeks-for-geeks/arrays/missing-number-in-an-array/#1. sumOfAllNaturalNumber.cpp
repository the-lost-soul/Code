#include <iostream>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size)
{
    // Get the sum of first n natural numbers .
    int sum = (size*(size + 1))/2 ;
    
    // Subtract the numbers in array with sum and at 
    // last the number in sum will be equal to missing
    // number .
    for(int i = 0 ; i < size - 1 ; i++)
    {
        sum -= arr[i] ;
    }
    return sum ;
}
int main() 
{
	int testcase ;
	cin >> testcase ;
	while(testcase --)
	{
	    int size ;
	    cin >> size ;
	    int arr[size - 1] ;
	    scan(arr , size) ;
	    cout<<solve(arr , size) <<" "<<endl ;
	}
	return 0;
}
