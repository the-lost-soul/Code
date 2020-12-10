class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) ;
} ;

vector<vector<string>> Solution :: groupAnagrams(vector<string>& strs)
{
    unordered_map<string , vector<string>>anagrams ;
    vector<int>hash(26 , 0) ;
    for(auto word : strs)
    {
        string temp = word ;
        sort(begin(temp) , end(temp)) ;
        anagrams[temp].push_back(word) ;
    }
    vector<vector<string>>res ;
    for(auto itr : anagrams)
    {
        res.push_back(itr.second) ;
    }
    return res ;
}
