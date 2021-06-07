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
    
    temp.push_back(candidates[ind]) ;
    helper(temp , ind + 1 , sum + candidates[ind] , target) ;
    temp.pop_back() ;
    helper(temp , ind + 1 , sum , target) ;
}
vector<vector<int>> Solution :: combinationSum2(vector<int>& candidates , int target)
{
    this->candidates = candidates ;
    vector<int>temp ;
    helper(temp , 0 , 0 , target) ;
    for(int i = 0 ; i < res.size() ; i++)
    {
        sort(begin(res[i]) , end(res[i])) ;
    }
    sort(begin(res) , end(res)) ;
    vector<vector<int>>ans ;
    for(int i = 0 ; i < res.size() ;)
    {
        int j = i ;
        while(j < res.size() and res[i] == res[j])
            j++ ;
        ans.push_back(res[i]) ;
        i = j ;
    }
    return ans ;
}
