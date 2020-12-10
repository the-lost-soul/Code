class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) ;
    bool ifPossible(int arr1[] , int arr2[]) ;
};

bool Solution :: ifPossible(int arr1[] , int arr2[])
{
    int count = 0 ;
    for(int i = 0 ; i < 26 ; i++)
    {
        count += arr1[i] - arr2[i] ;
        if(count < 0)
            return false ;
    }
    return true ;
}
bool Solution :: checkIfCanBreak(string s1 , string s2)
{
    int arr1[26] , arr2[26] ;
    memset(arr1 , 0 , sizeof(arr1)) ;
    memset(arr2 , 0 , sizeof(arr2)) ;
    for(auto ch : s1)
        arr1[ch - 'a']++ ;
    for(auto ch : s2)
        arr2[ch - 'a']++ ;
    return ifPossible(arr1 , arr2) or ifPossible(arr2 , arr1) ;
}
