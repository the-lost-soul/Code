#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void scanArray(vector<string>& str , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> str[i] ;
}
int solve(vector<string>& str , int size , string word1 , string word2)
{
    // Store the indices of occurrences of both words in 
    // respective vectors.
    vector<int>indexWord1 , indexWord2 ;
    for(int i = 0 ; i < size ; i++)
    {
        if(str[i] == word1)indexWord1.push_back(i) ;
        if(str[i] == word2)indexWord2.push_back(i) ;
    }
    int len1 = indexWord1.size() , len2 = indexWord2.size() ;
    int i = 0 , j = 0 , minDiff = INT_MAX ;
    // Now , get the minimum difference b/w to indices .
    while(i < len1 and j < len2)
    {
        minDiff = min(minDiff , abs(indexWord1[i] - indexWord2[j])) ;
        /* If current index of vector "indexWord1" is greater than
         * that of current index of vector "indexWord2" , then move
         * ahead in vector "indexWord2" to minimize the difference
         * else we move ahead in vector "indexWord1" .
         */
        if(indexWord1[i] > indexWord2[j])j++ ;
        else i++ ;
    }
    return minDiff ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<string>str(size) ;
    	scanArray(str , size) ;
    	string word1 , word2 ;
    	cin >> word1 >> word2 ;
	    cout << solve(str , size , word1 , word2) << endl ;
	}
	return 0;
}
