class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) ;
};

int Solution :: numEquivDominoPairs(vector<vector<int>>& dominoes)
{
    int count = 0 ;
    unordered_map<string , int>hash = {};
    string temp = "" ;
    for(int i = 0 ; i < dominoes.size() ; i++)
    {
        // Sort the current row , and sorting will take constant time .
        sort(dominoes[i].begin() , dominoes[i].end()) ;
        temp = "" ;
        // Encode the current row as a string
        temp += to_string(dominoes[i][0]) + to_string(dominoes[i][1]) ;
        // check if the above string is already present or not in the hash table .
        if(hash.find(temp) != hash.end())
        {
            count += hash[temp] ;
        }
        // Hash the encoded string .
        hash[temp] ++ ;
        
    }
    return count ;
}
