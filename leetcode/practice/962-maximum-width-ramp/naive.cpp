class Solution {
public:
    int maxWidthRamp(vector<int>& arr) ;
};

int Solution :: maxWidthRamp(vector<int>& arr)
{
    int ans = 0 ;
    for(int i = 0 ; i < arr.size() - 1 ; i++)
    {
        for(int j = i + 1 ; j < arr.size() ; j++)
        {
            if(arr[j] >= arr[i])
            {
                ans = max(ans , j - i) ;
            }
        }
    }
    return ans ;
}
