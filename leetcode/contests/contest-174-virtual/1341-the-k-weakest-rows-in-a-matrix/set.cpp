class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) ;
};

vector<int> Solution :: kWeakestRows(vector<vector<int>>& mat , int k)
{
    int row = mat.size() ;
    set<pair<int , int>>mySet ;
    for(int i = 0 ; i < row ; i++)
    {
        int soldiers = accumulate(mat[i].begin() , mat[i].end() , 0) ;
        mySet.insert({soldiers , i}) ;
    }
    vector<int>ans ;
    for(auto it = mySet.begin() ; k > 0 ; it++ , k--)
        ans.push_back(it->second) ;
    return ans ;
}
