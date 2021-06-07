class Solution {
public:
    vector<vector<int>> combinationSum3(int k , int n) ;
    void solve(vector<vector<int>>& ans , vector<int> path , int i , int k , int n) ;
};

void Solution :: solve(vector<vector<int>>& ans , vector<int> path , int i , int k , int n)
{
    if(k == 0)
    {
        if(n == 0)ans.push_back(path) ;
        return ;
    }
    for(int num = i ; num <= 9 ; num++)
    {
        path.push_back(num) ;
        solve(ans , path , num + 1 , k - 1 , n - num) ;
        path.pop_back() ;
    }
    return ;
}

vector<vector<int>> Solution :: combinationSum3(int k , int n)
{
    vector<vector<int>>ans ;
    vector<int>path ;
    solve(ans , path , 1 , k , n) ;
    return ans ;
}
