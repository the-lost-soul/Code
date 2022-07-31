class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) ;
};

int Solution :: maxFreq(string s , int maxLetters , int minSize , int maxSize)
{
    int distinctChar = 0 , ans = 0 ;
    unordered_map<string , int>hash ;
    int hashChar[26] = {} ;
    string str = "" ;
    for(int i = 0 ; i < minSize ; i++)
    {
        if(hashChar[s[i] - 'a'] == 0)
        {
            distinctChar++ ;
        }
        hashChar[s[i] - 'a']++ ;  
        str += s[i] ;
    }
    if(distinctChar <= maxLetters)
    {
        hash[str]++ ;
        ans = max(ans , hash[str]) ;
    }
    for(int i = minSize ; i < s.length() ; i++)
    {
        if(hashChar[s[i] - 'a']++ == 0)
        {
            distinctChar++ ;
        }
        if(--hashChar[s[i - minSize] - 'a'] == 0)
        {
            distinctChar-- ;
        }
        str += s[i] ;
        str.erase(str.begin()) ;
        if(distinctChar <= maxLetters)
        {
            hash[str]++ ;
            ans = max(ans , hash[str]) ;
        }
    }
    
    return ans ;
}
