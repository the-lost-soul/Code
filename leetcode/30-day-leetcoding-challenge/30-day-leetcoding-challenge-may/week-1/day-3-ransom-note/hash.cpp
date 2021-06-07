class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) ;
};

bool Solution :: canConstruct(string ransomNote , string magazine)
{
    int hashNote[26] , hashMagazine[26] ;
    memset(hashNote , 0 , sizeof(hashNote)) ;
    memset(hashMagazine , 0 , sizeof(hashMagazine)) ;
    for(auto ch : ransomNote)
        hashNote[ch - 'a']++ ;
    for(auto ch : magazine)
        hashMagazine[ch - 'a']++ ;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(hashNote[i] > hashMagazine[i])
            return false ;
    }
    return true ;
}
