class Solution {
public:
    vector<string> stringMatching(vector<string>& words) ;
};

vector<string> Solution :: stringMatching(vector<string>& words)
{
    unordered_map<string , int> count ;
    for(int i = 0 ; i < words.size() ; i++)
    {
        string s1 = words[i] ;
        for(int j = 0 ; j < words.size() ; j++)
        {
            string s2 = words[j] ;
            if(s2.length() > s1.length() or j == i)
                continue ;
            if(s1.find(s2) != string :: npos)
            {
                count[s2]++ ;
            }
        }
    }
    vector<string>ans ;
    for(auto itr : count)
        ans.push_back(itr.first) ;
    return ans ;
}
