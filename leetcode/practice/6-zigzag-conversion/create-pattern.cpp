class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows == 1)
            return s ;
        vector<string>ans(min(numRows , int(s.size()))) ;

        int currRow = 0 ;
        bool goingDown = false ;

        for(auto ch : s)
        {
            ans[currRow]+= ch ;
            if(currRow == 0 or currRow == numRows - 1)
                goingDown = !goingDown ;
            currRow += goingDown ? 1 : -1 ;
        }

        string zigzag = "" ;
        for(auto str : ans)
            zigzag += str ;
        return zigzag ;
    }
};
