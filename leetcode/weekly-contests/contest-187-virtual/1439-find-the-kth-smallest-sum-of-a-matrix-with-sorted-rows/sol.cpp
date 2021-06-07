class Solution { 
    public: int kthSmallest(vector<vector<int>>& mat, int k) ;
};
int Solution :: kthSmallest(vector<vector<int>>& mat , int K) 
{
    vector<int> ans{0} ;
    for(int i = 0 ; i < mat.size() ; i++)
    {
        vector<int> temp ;
        for(int j = 0 ; j < mat[i].size() ; j++)
        {
            for(int k = 0 ; k < ans.size() ; k++)
            {
                temp.push_back(mat[i][j] + ans[k]) ;
            }
        } 
        sort(temp.begin() , temp.end()) ;
        ans.clear() ;
        int retain = min((int)K , (int)temp.size()) ;
        for(int i = 0 ; i < retain ; i++)
        {
            ans.push_back(temp[i]) ;
        }
    }
    return ans[K - 1] ; 
} 
