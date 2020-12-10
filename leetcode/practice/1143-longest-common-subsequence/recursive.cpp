class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) ;
    int lcs(string text1, string text2 , int i , int j) ;
};

int Solution :: lcs(string text1, string text2 , int i , int j)
{
    int len1 = text1.length() , len2 = text2.length() ;
    if(i >= len1 or j >= len2)return 0 ;
    if(text1[i] == text2[j])return 1 + lcs(text1 , text2 , i+1 , j+1) ;
    return max(lcs(text1 , text2 , i , j+1) , lcs(text1 , text2 , i+1 , j)) ;
}

int Solution :: longestCommonSubsequence(string text1 , string text2)
{
    return lcs(text1 , text2 , 0 , 0) ;
}
