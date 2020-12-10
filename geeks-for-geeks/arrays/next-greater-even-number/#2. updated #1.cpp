#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int breakNum(vector<int>& digit , long long int num)
{
    int oddCount = 0 ;
    while(num)
    {
        digit.push_back(num%10) ;
        if((num%10)%2 != 0)oddCount++ ;
        num /= 10 ;
    }
    reverse(digit.begin() , digit.end()) ;
    return oddCount ;
}

void solve(vector<int>digit)
{
    while(next_permutation(digit.begin() , digit.end()))
    {
        if(digit.back() %2 == 0)
        {
            for(auto ele : digit)
                cout << ele;
            return ;
        }
    }
    
    cout << -1;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    long long int num ;
    	cin >> num ;
    	vector<int>digit ;
    	int oddCount = breakNum(digit , num) ;
    	
    	// If all digits are odd , then no answer is possible
    	if(oddCount == digit.size())
    	    cout << -1;
	    else
	        solve(digit);
	   
	   cout << endl;
	}
	return 0;
}
