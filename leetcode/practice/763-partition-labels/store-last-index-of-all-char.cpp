class Solution {
public:
    vector<int> partitionLabels(string S) ;
};

vector<int> Solution :: partitionLabels(string s)
{
    vector<int>lastInd(26 , 0) ;
    for(int i = 0 ; i < s.size() ; i++)
        lastInd[s[i] - 'a'] = i ;
    int j = 0 , start = 0 ;
    vector<int>ans ;
    for(int i = 0 ; i < s.size() ; i++)
    {
        j = max(j , lastInd[s[i] - 'a']) ;
        if(i == j)
        {
            ans.push_back(i - start + 1) ;
            start = i + 1 ;
        }
    }
    return ans ;
}
