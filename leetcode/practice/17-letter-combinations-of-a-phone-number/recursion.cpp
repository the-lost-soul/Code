class Solution
{
    vector<string> ans ;
    unordered_map<int , string>keypad = {
        {2 , "abc"} ,
        {3 , "def"} ,
        {4 , "ghi"} ,
        {5 , "jkl"} ,
        {6 , "mno"} ,
        {7 , "pqrs"} ,
        {8 , "tuv"} ,
        {9 , "wxyz"}
    } ;

public:
    void solve(string digits , string str , int ind)
    {
        if(ind >= digits.length())
            ans.push_back(str) ;
        string keys = keypad[digits[ind] - '0'] ;
        for(auto ch : keys)
            solve(digits , str + ch , ind + 1) ;
    }
                
    vector<string> letterCombinations(string digits)
    {
        if(digits == "")
            return {} ;
        solve(digits , "" ,  0) ;
        return ans ;
    }
};
