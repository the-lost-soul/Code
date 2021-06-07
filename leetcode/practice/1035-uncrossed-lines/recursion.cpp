class Solution
{
    public :
        int maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2) ;
        int helper(vector<int>& arr1 , vector<int>& arr2 , int i , int j) ;
} ;

int Solution :: helper(vector<int>& arr1 , vector<int>& arr2 , int i , int j)
{
    int size1 = arr1.size() , size2 = arr2.size() ;
    if(i >= size1 or j >= size2) return 0 ;
    if(arr1[i] == arr2[j])
    {
        return 1 + helper(arr1 , arr2 , i + 1 , j + 1) ;
    }
    return max(helper(arr1 , arr2 , i , j + 1) , helper(arr1 , arr2 , i + 1 , j)) ;
}


int Solution :: maxUncrossedLines(vector<int>& arr1 , vector<int>& arr2)
{
    return helper(arr1 , arr2 , 0 , 0) ;
}
