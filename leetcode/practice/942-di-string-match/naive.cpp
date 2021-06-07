class Solution {
public:
    vector<int> diStringMatch(string S) ;
};

vector<int> Solution :: diStringMatch(string S)
{
    int left = 0 , right = S.length() ;
    vector<int>ans ;
    for(int i = 0 ; i < S.length() ; i++)
    {
        S[i] == 'I' ? ans.push_back(left++) : ans.push_back(right--) ;
    }
    
    S[S.length() - 1] == 'I' ? ans.push_back(right) : ans.push_back(left) ;
    return ans ;
}
