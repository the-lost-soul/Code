#include<bits/stdc++.h>
#include<iostream>
using namespace std;

double solve(double amount , int row , int glass)
{
    if(glass > row)return 0.0 ;
    // We are filling the imaginary glass below the last row too .
    double filled[((row + 1)*(row + 2))/2] ;
    memset(filled , 0.0 , sizeof(filled)) ;
    int index = 0 ;
    filled[index] = amount ;
    
    for(int r = 1 ; r <= row ; r++)
    {
        for(int c = 1 ; c <= r ; c++)
        {
            amount = filled[index] ;
            filled[index] = (filled[index] >= 1.0) ? 1.0 : filled[index] ;
            amount = (amount >= 1.0) ? (amount - 1.0) : 0.0 ;
            filled[index + r] += amount/2.0 ;
            filled[index + r + 1] += amount/2.0 ;
            index++ ;
        }
    }
    return filled[((row*(row - 1))/2) + glass - 1] ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int amount , row , glass ;
	    cin >> amount >> row >> glass ;
	    cout << solve((double)amount , row , glass) << endl ;
	}
	return 0;
}
