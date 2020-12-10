class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) ;
    bool strictlyIncreasing(vector<int>& arr) ;
};

bool Solution :: strictlyIncreasing(vector<int>& arr)
{
    for(int i = 0 ; i < arr.size() - 1 ; i++)
    {
        if(arr[i] > arr[i + 1])return false ;
    }
    return true ;
}

vector<int> Solution :: prevPermOpt1(vector<int>& arr)
{
    
    if(strictlyIncreasing(arr))
        return arr ;
    
    int right = arr.size() - 1 ;
    while(arr[right] >= arr[right - 1])
    {
        right-- ;
    }
    for(int i = arr.size() - 1 ; i > right - 1 ; i--)
    {
        if(arr[i] < arr[right - 1])
        {
            if(arr[i] != arr[i - 1])
            {
                swap(arr[right - 1] , arr[i]) ;
                break ;
            }
        }
    }
    
    return arr ;
}
