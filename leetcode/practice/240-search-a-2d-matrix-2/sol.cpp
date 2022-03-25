class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int r = 0 , c = matrix[0].size() - 1 ;
        while(r < matrix.size() and c >= 0)
        {
            int curr = matrix[r][c] ;
            if(curr == target)
                return true ;
            if(curr > target)
                c-- ;
            else if(curr < target)
                r++ ;
        }
        return false ;
    }
};
