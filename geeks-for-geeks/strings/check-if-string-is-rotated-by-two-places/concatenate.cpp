#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool rotateLeft(string str1 , string str2)
{
    /* Get the 2 characters from start which will move to end after rotating
     * string to left by 2 places , and conactenate it with the original string .
     * If we get string2 as a sub-string of concatenated string , then this means
     * we can get string2 from string1 after 2 rotations .
     * eg -- str1 = aquib , str2 = uibaq--> If we extract first two characters
     * from str1 and concatenate it with str1 , then concatenated string will be
     * str = aquibaq , and we can see that str2 is a sub-string of this string .
     */
    string concatenate = str1 + str1.substr(0 , 2);
    
    if(concatenate.find(str2) != string::npos)return true ;
    return false ;
}

bool rotateRight(string str1 , string str2)
{
    /* Get the 2 characters from end which will move to start after rotating
     * string to right by 2 places , and conactenate it with the original string .
     * Note that we have to concatenate the extracted character at the start of str1 .
     * If we get string2 as a sub-string of concatenated string , then this means
     * we can get string2 from string1 after 2 rotations .
     */
    string concatenate = str1.substr(str1.length()-2 , 2) + str1 ;
    
    if(concatenate.find(str2) != string :: npos)return true ;
    return false ;
}
int solve(string str1 , string str2)
{
    bool right = rotateRight(str1 , str2) ;
    bool left = rotateLeft(str1 , str2) ;
    if(left or right)return 1 ;
    return 0 ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    string str1 , str2 ;
	    cin >> str1 >> str2 ;
	    cout << solve(str1 , str2) << endl ;
	}
	return 0;
}
