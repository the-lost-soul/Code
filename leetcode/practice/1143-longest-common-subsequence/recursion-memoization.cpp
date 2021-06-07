class Solution {
public:
    int longestCommonSubsequence(string text1 , string text2) ;
    int lcs(string& text1 , string& text2 , int** mat , int i , int j) ;
    int** createMatrix(int** mat , int row , int col) ;
};

int** Solution :: createMatrix(int** mat , int row , int col)
{
    mat = new int*[row] ;
    for(int i = 0 ; i < row ; i++)
    {
        mat[i] = new int[col] ;
    }
    return mat ;
}
/* Here's a trick , assume we have two very large strings and every time we call
 * lcs() , we are passing a new copy of string to the newly called lcs() . Because
 * of this Time Limit Exceeds . Hence , to avoid TLE we should pass the strings as
 * reference as on passing the strings by reference the same copy is used by all the
 * lcs() recursive calls .
 */
int Solution :: lcs(string& text1, string& text2 , int** mat , int i , int j)
{
    int len1 = text1.length() , len2 = text2.length() ;
    if(i >= len1 or j >= len2)return 0 ;
    if(mat[i][j] != -1)return mat[i][j] ;
    if(text1[i] == text2[j])
    {
        
        mat[i][j] = 1 + lcs(text1 , text2 , mat , i + 1 , j + 1) ;
    }
    else 
    {
        int first = lcs(text1 , text2 , mat , i , j + 1) ;
        int second = lcs(text1 , text2 , mat , i + 1 , j) ;
        mat[i][j] = max(first , second) ;
    
    }
    return mat[i][j] ;
    
}

int Solution :: longestCommonSubsequence(string text1 , string text2)
{
    int len1 = text1.length() , len2 = text2.length() ;
    int** mat = createMatrix(mat , len1 , len2) ;
    
    for(int i = 0 ; i < len1 ; i++)
    {
        for(int j = 0 ; j < len2 ; j++)
        {
            mat[i][j] = -1 ;
        }
    }
    return lcs(text1 , text2 , mat , 0 , 0) ;
}
