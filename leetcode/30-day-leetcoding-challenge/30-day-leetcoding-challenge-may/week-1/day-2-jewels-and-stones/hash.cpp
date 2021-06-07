class Solution {
public:
    int numJewelsInStones(string J, string S) ;
};

int Solution :: numJewelsInStones(string jewel , string stones)
{
    unordered_set<char>hash ;
    for(auto ch : jewel)
        hash.insert(ch) ;
    int ans = 0 ;
    for(auto ch : stones)
    {
        if(hash.find(ch) != hash.end())
            ans += 1 ;
    }
    return ans ;
}
