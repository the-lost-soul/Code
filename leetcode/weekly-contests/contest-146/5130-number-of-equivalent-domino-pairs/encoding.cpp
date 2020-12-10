class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) ;
};

int Solution :: numEquivDominoPairs(vector<vector<int>>& dominoes)
{
    int count = 0 ;
    unordered_map<int , int>hash = {};
    int encode = 0 ;
    for(int i = 0 ; i < dominoes.size() ; i++)
    {
        // Sort the current row , and sorting will take constant time .
        sort(dominoes[i].begin() , dominoes[i].end()) ;
        encode = dominoes[i][0]*10 + dominoes[i][1] ;
        
        // check if the encoded number is already present or not in the hash table .
        if(hash.find(encode) != hash.end())
        {
            count += hash[encode] ;
        }
        // Hash the encoded number .
        hash[encode] ++ ;
        
    }
    return count ;
}
