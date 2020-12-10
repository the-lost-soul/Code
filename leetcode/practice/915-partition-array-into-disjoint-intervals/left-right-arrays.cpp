class Solution {
public:
    int partitionDisjoint(vector<int>& arr) ;
};

int Solution :: partitionDisjoint(vector<int>& arr)
{
    int len = arr.size() ;
    vector<int>maxLeft(len , 0) ;
    maxLeft[0] = arr[0] ;
    for(int i = 1 ; i < len ; i++)
        maxLeft[i] = max(maxLeft[i - 1] , arr[i]) ;
    
    vector<int>minRight(len , 0) ;
    minRight[len - 1] = arr[len - 1] ;
    for(int i = len - 2 ; i >= 0 ; i--)
        minRight[i] = min(minRight[i + 1] , arr[i]) ;
    
    int disjoint = 1 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(maxLeft[i] <= minRight[i + 1])
        {
            disjoint = i + 1 ; 
            break ;
        }
    }
    return disjoint ;
}
