class Solution {
public:
    string sortString(string s) ;
};

string Solution :: sortString(string s)
{
    int hash[26] ;
    memset(hash , 0 , sizeof(hash)) ;
    for(auto ele : s)
    {
        hash[ele - 'a']++ ;
    }
    string result = "" ;
    int i = 0 ;
    while(i < s.length())
    {
        for(int j = 0 ; j < 26 ; j++)
        {
            if(hash[j])
            {
                hash[j]-- ;
                result += (j + 'a') ;
                i++ ;
            }
        }
        
        for(int j = 25 ; j >= 0 ; j--)
        {
            if(hash[j])
            {
                hash[j]-- ;
                result += (j + 'a') ;
                i++ ;
            }
        }
    }
    return result ;
}
