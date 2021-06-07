class Solution {
public:
    vector<vector<int>>res ;
    vector<int>candidates ;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) ;
    void helper(vector<int>& temp , int ind , int sum , int target) ;
    
};
void Solution :: helper(vector<int>& temp , int ind , int sum , int target)
{
    if(sum == target)
    {
        res.push_back(temp) ;
        return ;
    }
    if(sum > target)
        return ;
    if(ind >= candidates.size())
        return ;
    
    for(int i = ind ; i < candidates.size() ; i++)
    {
        if(candidates[i] > target)
            return ;
        // This keeps a check on duplicate element .
        if(i != 0 and i > ind and candidates[i] == candidates[i - 1])
            continue ;
        temp.push_back(candidates[i]) ;
        helper(temp , i + 1 , sum + candidates[i] , target) ;
        temp.pop_back() ;
    }
}
vector<vector<int>> Solution :: combinationSum2(vector<int>& candidates , int target)
{
    sort(begin(candidates) , end(candidates)) ;
    this->candidates = candidates ;
    vector<int>temp ;
    helper(temp , 0 , 0 , target) ;
    return res ;
}
