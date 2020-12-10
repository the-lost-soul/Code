#include<bits/stdc++.h>
using namespace std;
void scan(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> arr[i] ;
    
}

void print(int arr[] , int size)
{
    for(int i = 0 ; i < size ; i++)
        cout << arr[i] ;
}

int matrixChain(int arr[] , int size)
{
    // Total matrix formed from an array of length "size"
    // is "size - 1" .
    int cost[size - 1][size - 1] ;
    // Multiplying matrix with itself .
    for(int i = 0 ; i < size - 1 ; i++)
        cost[i][i] = 0 ;
    
    for(int length = 2 ; length < size ; length ++)
    {
        for(int i = 0 ; i < size - length ; i++)
        {
            int j = i + length - 1 ;
            cost[i][j] = INT_MAX ;
            for(int k = i ; k < j ; k++)
            {
                int currCost = cost[i][k] + cost[k + 1][j] + arr[i]*arr[k + 1]*arr[j + 1] ;
                cost[i][j] = min(cost[i][j] , currCost) ;
            }
        }
    }
    
    return cost[0][size - 2] ;
}

int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase --)
    {
        int size ;
        cin >> size ;
        int arr[size] ;
        scan(arr , size) ;
        cout << matrixChain(arr , size) << endl ;
        
    }
	return 0;
}
