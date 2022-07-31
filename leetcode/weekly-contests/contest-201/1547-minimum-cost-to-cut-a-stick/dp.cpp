struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
class Solution
{
    unordered_map<pair<int , int> , int , pair_hash>dp ;
public:
    int solve(vector<int>& cuts , int left , int right)
    {
        if(right - left <= 1)
            return 0 ;
        if(dp.find({left , right}) != dp.end())return dp[{left , right}] ;

        int minValue = INT_MAX ;

        for(auto ele : cuts)
        {
            if(ele >= right or ele <= left)continue ;

            int temp = 0 ;
            temp += solve(cuts , left , ele) ;
            temp += solve(cuts , ele , right) ;

            // cost of cutting left and right part plus the
            // cost of cutting current part .
            minValue = min(minValue , temp + right - left) ;
        }

        if(minValue == INT_MAX)
            minValue = 0 ;
        dp[{left , right}] = minValue ;
        return minValue ;
    }
    int minCost(int n, vector<int>& cuts)
    {
        return solve(cuts , 0 , n) ;
    }
};
