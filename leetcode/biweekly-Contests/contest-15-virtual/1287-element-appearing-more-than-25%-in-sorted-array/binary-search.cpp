class Solution {
public:
    int findSpecialInteger(vector<int>& arr) ;
};

int Solution :: findSpecialInteger(vector<int>& arr)
{
    int len = arr.size() ;
    vector<int>candidates = {arr[len/4] , arr[len/2] , arr[len*3/4]} ;
    int ans = 0 ;
    for(auto ele : candidates)
    {
        auto upper = upper_bound(arr.begin() , arr.end() , ele) ;
        auto lower = lower_bound(arr.begin() , arr.end() , ele) ;
        if(4*(upper - lower) >= len)ans = ele ;
    }
    return ans ;
}
