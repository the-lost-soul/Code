class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) ;
};

int Solution :: maxChunksToSorted(vector<int>& arr)
{
    int len = arr.size() ;
    int maxArr[len] ;
    maxArr[0] = arr[0] ;
    for(int i = 1 ; i < len ; i++)
    {
        maxArr[i] = max(arr[i] , maxArr[i - 1]) ;
    }
    int chunks = 0 ;
    for(int i = 0 ; i < len ; i++)
    {
        if(maxArr[i] == i)
        {
            chunks++ ;
        }
    }
    
    return chunks ;
}
