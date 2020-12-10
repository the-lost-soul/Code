#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(int arrA[] , int arrB[] , int sizeOfA , int sizeOfB)
{
    for(int i = 0 ; i < sizeOfA ; i++)
    {
        cin >> arrA[i] ;
    }
    for(int i = 0 ; i < sizeOfB ; i++)
    {
        cin >> arrB[i] ;
    }
}

long maxDotProd(int arrA[] , int arrB[] , int i , int j , int sizeOfA , int sizeOfB , int count0)
{
    if(i >= sizeOfA or j >= sizeOfB)return 0 ;
    
    long dotProd1 = INT_MIN , dotProd2 = INT_MIN ;
    // There can only be below two cases possible for maximizing dot product --
    // 1 -- Multiply the current element of arrA with 0 and recur ahead .
    if(count0 > 0)
        dotProd1 = maxDotProd(arrA , arrB , i + 1 , j , sizeOfA , sizeOfB , count0 - 1) ;
    
    // 2 -- Multiply the current element's of arrA and arrB and move ahead .
    dotProd2 = arrA[i]*arrB[j] + maxDotProd(arrA , arrB , i + 1 , j + 1 , sizeOfA , sizeOfB , count0) ;
    
    return max(dotProd1 , dotProd2) ;
}
long solve(int arrA[] , int arrB[] , int sizeOfA , int sizeOfB)
{
    int count0 = sizeOfA - sizeOfB ;
    int i = 0 , j = 0 ;
    return maxDotProd(arrA , arrB , i , j , sizeOfA , sizeOfB , count0) ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int sizeOfA , sizeOfB ;
    	cin >> sizeOfA >> sizeOfB ;
    	int arrA[sizeOfA] , arrB[sizeOfB];
    	scanArray(arrA , arrB , sizeOfA , sizeOfB) ;
	    cout << solve(arrA , arrB , sizeOfA , sizeOfB) << endl ;
	}
	return 0;
}
