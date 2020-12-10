#include<bits/stdc++.h>
#include <iostream>
using namespace std;

string getPattern(string text)
{
    int hash[26] = {0} ;
    int len = text.length() ;
    string pattern = "" ;
    for(int i = 0 ; i < len ; i++)
    {
        if(hash[text[i] - 'a'] == 0)pattern += text[i] ;
        hash[text[i] - 'a']++ ;
    }
    return pattern ;
}

int smallestWindow(string text , string pattern)
{
    int lenText = text.length() ;
    int lenPatt = pattern.length() ;
    // If length of pattern is greater than that of text string , then 
    // no window is possible .
    if(lenText < lenPatt)return -1 ;
    
    int hashPatt[26] = {0} ;
    // Hash the count of occurrences of pattern string .
    for(int i = 0 ; i < lenPatt ; i++)hashPatt[pattern[i] - 'a']++ ;
    
    int hashText[26] = {0} ;
    int minLen = INT_MAX , windowStart = -1 , start = 0 , count = 0  ;
    
    for(int i = 0 ; i < lenText ; i++)
    {
        auto ele = text[i] - 'a';
        // count occurrence of characters of text string
        hashText[ele]++ ;
        // If current ele of text string exists in pattern string , then
        // increment count .
        if(hashPatt[ele] != 0 and hashPatt[ele] >= hashText[ele])count++ ;
        // If all the characters of pattern is matched with text .
        if(count == lenPatt)
        {
            /* Consider the current window , and remove all the undesired
             * characters(characters not present in pattern string) or if any
             * character in text string is occuring more no. of times than it's
             * occurrence in pattern string , then discard that from starting .
             */
            while(hashPatt[text[start] - 'a'] == 0 or hashText[text[start] - 'a'] > hashPatt[text[start] - 'a'])
            {
                if(hashText[text[start] - 'a'] > hashPatt[text[start] - 'a'])
                    hashText[text[start] - 'a']-- ;
                start++ ;
            }
            // Get the current window length .
            int currWinLen = i - start + 1 ;
            if(currWinLen < minLen)
            {
                minLen = currWinLen ;
                windowStart = start ;
            }
        }
    }
    
    if(windowStart == -1)return -1 ;
    return minLen ;
}
int main() 
{
    int testcase ;
    cin >> testcase ;
    while(testcase--)
    {
        string text ;
        cin >> text ;
        string pattern = getPattern(text) ;
        cout << smallestWindow(text , pattern) << endl ;   
    }
	  return 0;
}
