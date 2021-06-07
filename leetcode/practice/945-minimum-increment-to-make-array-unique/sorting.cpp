class Solution {
public:
    int minIncrementForUnique(vector<int>& A) ;
};

int Solution :: minIncrementForUnique(vector<int>& arr)
{
    sort(begin(arr) , end(arr)) ;
    int increments = 0 ;
    for(int i =  1 ; i < size(arr) ; i++)
    {
        if(arr[i - 1] >= arr[i])
        {
            increments += (arr[i - 1] - arr[i] + 1) ;
            arr[i] = arr[i - 1] + 1 ;
        }
    }
    return increments ;
}
