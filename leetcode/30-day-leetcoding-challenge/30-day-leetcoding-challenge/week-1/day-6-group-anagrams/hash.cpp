class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) ;
} ;

vector<vector<string>> Solution :: groupAnagrams(vector<string>& strs)
{
    unordered_map<string , vector<int>>anagrams ;
    vector<int>hash(26 , 0) ;
    vector<string> temp = strs ;
    for(int i = 0 ; i < size(strs) ; i++)
    {
        sort(begin(temp[i]) , end(temp[i])) ;
        anagrams[temp[i]].push_back(i) ;
    }
    vector<vector<string>>res ;
    for(auto itr : anagrams)
    {
        vector<int>indices = itr.second ;
        vector<string>group ;
        for(int i = 0 ; i < size(indices) ; i++)
            group.push_back(strs[indices[i]]) ;
        res.push_back(group) ;
    }
    return res ;
}
