class Solution {
public:
    bool rotateString(string A , string B) ;
};

bool Solution :: rotateString(string text , string pattern)
{
    if(text.length() != pattern.length())return false ;
    
    string concatenatedStr = text + text ;
    
    if(concatenatedStr.find(pattern) != string :: npos)return true ;
    return false ;
    
}
