class Solution {
public:
    int maxWidthRamp(vector<int>& arr) ;
};

int Solution :: maxWidthRamp(vector<int>& arr)
{
    multimap<int , int>valInd ;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        valInd.insert({arr[i] , i}) ;
    }
    
    int ans = 0 , minInd = INT_MAX ;
    for(auto itr : valInd)
    {
        ans = max(ans , itr.second - minInd) ;
        minInd = min(minInd , itr.second) ;
    }
    return ans ;
}
