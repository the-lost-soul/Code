class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if(needle.size() == 0) return 0 ;
        if(haystack.size() == 0)return -1 ;
        if(haystack.size() < needle.size()) return -1 ;

        string str = haystack.substr(0 , needle.size()) ;
        if(str == needle) return 0 ;
        for(int i = 1 ; i < haystack.size() - needle.size() + 1 ; i++)
        {
            str = haystack.substr(i , needle.size()) ;
            if(str == needle) return i ;
        }
        return -1 ;
    }
};
