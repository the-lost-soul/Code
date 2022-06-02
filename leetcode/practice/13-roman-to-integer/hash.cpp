class Solution
{
    unordered_map<char , int> hash =
    {
        { 'I' , 1 },
        { 'V' , 5 },
        { 'X' , 10 },
        { 'L' , 50 },
        { 'C' , 100 },
        { 'D' , 500 },
        { 'M' , 1000 }
    } ;

public:
    int romanToInt(string s)
    {
        int len = s.length() ;
        int num = 0 ;
        for(int i = len - 1 ; i >= 0 ; i--)
        {
            if(i < len - 1 and hash[s[i]] < hash[s[i + 1]])
                num -= hash[s[i]] ;
            else 
                num += hash[s[i]] ;
        }
        return num ;
    }
};
