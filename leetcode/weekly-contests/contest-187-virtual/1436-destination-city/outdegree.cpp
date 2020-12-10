class Solution {
public:
    string destCity(vector<vector<string>>& paths) ;
};

string Solution :: destCity(vector<vector<string>>& paths)
{
    unordered_map<string , int>hash ;
    // Calculate out-degree for each city
    for(auto p : paths)
    {
        hash[p[0]]++ ;
    }
    // The city which will not be present in hash table
    // will be the answer
    for(auto p : paths)
    {
        if(hash.find(p[1]) == hash.end())
            return p[1] ;
    }
    return "" ;
}
