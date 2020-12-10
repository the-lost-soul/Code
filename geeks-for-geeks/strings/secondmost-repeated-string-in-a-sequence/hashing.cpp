#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(vector<string>& vec , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> vec[i] ;
}
string solve(vector<string> vec , int size)
{
    unordered_map<string , int>hash = {} ;
    for(int i = 0 ; i < size ; i++)
    {
        hash[vec[i]]++ ;
    }
    int firstLargest  , secondLargest ;
    firstLargest = secondLargest = INT_MIN ;
    string firstS , secondS ;
    firstS = secondS = "" ;
    for(auto ele : hash)
    {
        // If we get a new largest element , then update the
        // second largest with first largest , as it has now
        // become 2nd largest element of string .
        // Remember this method of finding second largest , 
        // we can similarly find third largest also .
        if(firstLargest < ele.second)
        {
            secondLargest = firstLargest ;
            firstLargest = ele.second ;
            secondS = firstS ;
            firstS = ele.first ;
            
        }
        else if(secondLargest < ele.second)
        {
            secondLargest = ele.second ;
            secondS = ele.first ;
        }
    }
    return secondS ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	// Rememeber , create a vector of desired
    	// size here only , and then use index operator
    	// to input element , otherwise seg fault will ocur .
    	vector<string>vec(size , "") ;
    	scanArray(vec , size) ;
	   cout << solve(vec , size) << endl ;
	}
	return 0;
}
