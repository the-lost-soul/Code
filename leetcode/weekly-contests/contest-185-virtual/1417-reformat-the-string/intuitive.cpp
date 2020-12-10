class Solution {
public:
    string reformat(string s) ;
};

string Solution :: reformat(string s)
{
    int len = s.length() ;
    if(len == 1)return s ;
    string ans = s ;
    // Check if number of alphabets are greater than numbers or not .
    int greater = 0 ;
    for(auto ch : s)
        greater += ch >= 'a' and ch <= 'z' ? 1 : -1 ;
    int letter = 1 , num =  0 ;
    // If alphabets are greater then start filling ans string by alphabets
    // else by numbers .
    if(t > 0)
    {
        letter = 0 , num = 1 ;
    }
    
    bool onlyLetter = true , onlyNum = true ;
    for(int i = 0 ; i < len ; i++)
    {
        if(letter < len and s[i] >= 'a' and s[i] <= 'z')
        {
            ans[letter] = s[i] ;
            letter += 2 ;
            onlyNum = false ;
        }
        else if(num < len and s[i] >= '0' and s[i] <= '9')
        {
            ans[num] = s[i] ;
            num += 2 ;
            onlyLetter = false ;
        }
    }
    return onlyLetter or onlyNum ? "" : ans ;
}
