class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) ;
} ;

vector<vector<string>> Solution :: groupAnagrams(vector<string>& strs)
{
    unordered_map<string , vector<string>>anagrams ;
    vector<int>hash(26 , 0) , count(26 , 0) ;
    for(auto word : strs)
    {
        fill(hash.begin() , hash.end() , 0) ;
        for(auto ch : word)
            hash[ch - 'a']++ ;
        string temp = "" ;
        // Counting Sort
        for(int i = 0 ; i < 26 ; i++)
            temp += string(hash[i] , i + 'a') ;
        anagrams[temp].push_back(word) ;
    }
    vector<vector<string>>res ;
    for(auto itr : anagrams)
    {
        res.push_back(itr.second) ;
    }
    return res ;
}
