#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int checkIfMatch(int textHash[] , int wordHash[])
{
    int match = 0 ;
    for(int i = 0 ; i < 26 ; i++)
        if(wordHash[i] == textHash[i])
            match++ ;
    if(match == 26)return 1 ;
    return 0 ;
}
int solve(string& text , string& word)
{
    int len1 = text.length() , len2 = word.length() ;
    if(len2 > len1)return 0 ;
    int textHash[26] = {} , wordHash[26] = {} ;
    // Check in the first window of size of length = len(word)
    for(int i = 0 ; i < len2 ; i++)
    {
        wordHash[word[i] - 'a']++ ;
        textHash[text[i] - 'a']++ ;
    }
    int anagram = 0 ;
    // Find if the current window is anagram of the word or not .
    // If it is anagram , then both the hash tables will be same else
    // not .
    anagram += checkIfMatch(textHash , wordHash) ;
    // Check for the next window .
    for(int i = len2 ; i < len1 ; i++)
    {
        textHash[text[i] - 'a']++ ;
        textHash[text[i - len2] - 'a']-- ;
        anagram += checkIfMatch(textHash , wordHash) ;
    }
    return anagram ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string text , word ;
	    cin >> text >> word ;
	    cout << solve(text , word) << endl ;
	}
	return 0;
}
