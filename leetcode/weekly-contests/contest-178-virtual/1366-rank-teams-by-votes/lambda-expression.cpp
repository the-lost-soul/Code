class Solution {
public:
    string rankTeams(vector<string>& votes) ;
};

string Solution :: rankTeams(vector<string>& votes)
{
    int candidates = votes[0].length() , len = votes.size() ;
    vector<vector<int>>ranks(26 , vector<int>(candidates , 0)) ;
    for(string &str : votes)
    {
        for(int i = 0 ; i < candidates ; i++)
        {
            int row = str[i] - 'A' ;
            ranks[row][i]++ ;
        }
    }
    string ans = votes[0] ;
    sort(ans.begin() , ans.end() , [&](char &a , char &b)
    {
        if(ranks[a - 'A'] == ranks[b - 'A'])
            return a < b ;
        return ranks[a - 'A'] > ranks[b - 'A'] ;
    }) ;
    return ans ;
}
