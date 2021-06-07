class Solution {
public:
    int maxProfit(vector<int>& arr) ;
} ;
int Solution :: maxProfit(vector<int>&arr)
{
    int len = arr.size() ;
    if(len < 2)return 0 ;
    int maxDiff = arr[1] - arr[0] ;
    int min = arr[0] ;
    for(int i = 1 ; i <len ; i++)
    {
        if(arr[i] - min > maxDiff)maxDiff = arr[i] - min ;
        
        if(min > arr[i])min = arr[i] ;
    }
    
    if(maxDiff >= 0)
    return maxDiff ;
    else return 0 ;
}
