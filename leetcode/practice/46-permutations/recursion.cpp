class Solution
{
    unordered_set<int>hash ;
public:
    void solve(vector<int>& nums , vector<vector<int>>&ans , vector<int>&temp)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp) ;
            return ;
        }

        for(auto ele : nums)
        {
            if(hash.find(ele) == hash.end())
            {
                hash.insert(ele) ;
                temp.push_back(ele) ;
                solve(nums , ans , temp) ;
                temp.pop_back() ;
                hash.erase(ele) ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans ;
        vector<int>temp ;
        solve(nums , ans , temp) ;
        return ans ;
    }
};
