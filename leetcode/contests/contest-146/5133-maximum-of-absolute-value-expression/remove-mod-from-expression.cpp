class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) ;
};

int desiredValue(int sign1 , int sign2 , vector<int>& arr1 , vector<int>& arr2)
{
    int len = arr1.size() ;
    vector<int>arr3 ;
    // Get the desired combination i.e arr1[i]*sign + arr2[i]*sign + i
    for(int i = 0 ; i < len ; i++)
    {
        arr3.push_back(arr1[i]*sign1 + arr2[i]*sign2 + i) ;
    }
    // Get the minimum and maximum value from the new vector because
    // their difference will be the deired answer .
    int min = INT_MAX , max = INT_MIN ;
    for(int i = 0 ; i < len ; i++)
    {
        if(min > arr3[i])min = arr3[i] ;
        if(max < arr3[i])max = arr3[i] ;
    }
    
    return max - min ;
}
int Solution :: maxAbsValExpr(vector<int>& arr1 , vector<int>& arr2)
{
    int answer = 0 ;
    /* The above mod expression can be broken into 4 different forms after
     * we remove the mod from the given expression 
     */
    answer = max(answer , desiredValue(1 , 1 , arr1 , arr2)) ;
    answer = max(answer , desiredValue(1 , -1 , arr1 , arr2)) ;
    answer = max(answer , desiredValue(-1 , 1 , arr1 , arr2)) ;
    answer = max(answer , desiredValue(-1 , -1 , arr1 , arr2)) ;
    
    return answer ;
    
}
