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
    int finalSum = INT_MIN , currSum = 0 ;
    int finalStart = -1 , finalEnd = -1 ;
    int currStart = -1 , currEnd = -1 ;
    /* The reason , why we are iterating till "size" and not
     * till "size - 1" is that there may occur a case when
     * we have got a max sum sub-array somewhere in middle
     * of the array and finally we have also got an sub-array
     * which ends at last index . Hence ,to check whether this
     * sub-array can be a legitimate answer or not we iterate
     * till "size" .
     */
    for(int i = 0 ; i <= size ; i++)
    {
        if(arr[i] >= 0 and i!= size)
        {
            if(currStart == -1)currStart = i ;
            currSum += arr[i] ;
            currEnd = i ;
        }
        else
        {
            if(currSum > finalSum)
            {
                finalSum = currSum ;
                finalStart = currStart ;
                finalEnd = currEnd ;
            }
            else if(currSum == finalSum)
            {
                int prevLen = finalEnd - finalStart + 1 ;
                int currLen = currEnd - currStart + 1 ;
                if(currLen > prevLen)
                {
                    finalStart = currStart ;
                    finalEnd = currEnd ;
                }
            }
            currStart = currEnd = -1 ;
            currSum = 0 ;
        }
    }
    for(int i = finalStart ; i <= finalEnd ; i++)
    {
        cout << arr[i] << " " ;
    }
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
	}
	return 0;
}
