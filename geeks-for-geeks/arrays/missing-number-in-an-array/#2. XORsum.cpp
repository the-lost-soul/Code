#include <iostream>
using namespace std;

void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
        cin >> arr[i] ;
}
int solve(int arr[] , int size)
{
    // Get the XOR sum of first n natural numbers .
    int origXORsum = 0 ;
    for(int i = 1 ; i <= size ; i++)
    {
        origXORsum ^= i ;
    }
    
    // Get the XOR sum of the numbers present in
    // array .
    int XORsum = 0 ;
    for(int i = 0 ; i < size - 1 ; i++)
    {
        XORsum ^= arr[i] ;
    }
    
    /* Since we know x(XOR)x equals zero , so using
     * this fact if we do XOR of origXORsum and XORsum
     * then all the commons between them will become
     * zero and the final result will be the missing number .
     *
     * Eg -- origXORsum = 1^2^3^4 and XORsum = 1^2^3
     * So , origXORsum^XORsum will be(1^1)^(2^2)^(3^3)^4
     * and that will be equal to 0^0^0^3 and hence
     * answer is 3 .
     */
     
    return origXORsum^XORsum ;
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
