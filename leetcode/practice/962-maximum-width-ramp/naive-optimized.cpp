class Solution {
public:
    int maxWidthRamp(vector<int>& arr) ;
};

int Solution :: maxWidthRamp(vector<int>& arr)
{
    int ans = 0 ;
    // After every ith iteration , we'll start from
    // this index . 
    int start = 1 ;
    for(int i = 0 ; i < arr.size() - 1 ; i++)
    {
        for(int j = start ; j < arr.size() ; j++)
        {
            if(arr[j] >= arr[i])
            {
                ans = max(ans , j - i) ;
                start = j + 1 ;
            }
        }
    }
    return ans ;
}
