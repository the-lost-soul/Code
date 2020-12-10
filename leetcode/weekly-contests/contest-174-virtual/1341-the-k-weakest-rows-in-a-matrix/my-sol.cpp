class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) ;
};

vector<int> Solution :: kWeakestRows(vector<vector<int>>& mat , int k)
{
    int row = mat.size() , col = mat[0].size() ;
    vector<pair<int , int>>myVector ;
    for(int i = 0 ; i < row ; i++)
    {
        int soldiers = 0 ;
        for(int j = 0 ; j < col ; j++)
        {
            soldiers += mat[i][j] ;
        }
        myVector.push_back({soldiers , i}) ;
    }
    
    sort(myVector.begin() , myVector.end()) ;
    vector<int>ans ;
    int i = 0 ;
    while(k--)
    {
        ans.push_back(myVector[i].second) ;
        i++ ;
    }
    return ans ;
}
