class Solution {
public:
    unordered_map<string , pair<int , int>>count ;
    int findMaxForm(vector<string>& strs, int m, int n) ;
    int helper(vector<string>& strs , int m , int n , int index) ;
};

int Solution :: helper(vector<string>& strs , int m , int n ,int index)
{
    if(m <= 0 and n <= 0)
        return 0 ;
    if(index >= strs.size())
        return 0 ;
    
    int zeroes = count[strs[index]].first , ones = count[strs[index]].second ;
    int ans1 = 0 ;
    if(m >= zeroes and n >= ones)
        ans1 = 1 + helper(strs , m - zeroes , n - ones , index + 1) ;
    int ans2 = helper(strs , m , n , index + 1) ;
    return max(ans1 , ans2) ;
    
}

int Solution :: findMaxForm(vector<string>& strs , int m , int n)
{
    for(auto s : strs)
    {
        int count0 = 0 , count1 = 0 ;
        for(auto ch : s)
            ch == '0' ? count0++ : count1++ ;
        count[s] = {count0 , count1} ;
    }
    return helper(strs , m , n , 0) ;
}
