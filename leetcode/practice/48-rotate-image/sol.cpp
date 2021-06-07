class Solution {
public:
    void rotate(vector<vector<int>>& matrix) ;
};

void Solution :: rotate(vector<vector<int>>& matrix)
{
    int row = matrix.size() , col = matrix[0].size() ;
    int ring = row/2 ;
    int currRing  = 0 ;
    while(currRing < ring)
    {
        int i = currRing , len = row - currRing - 1 ;
        while(i < len)
        {
            int currRow = currRing , currCol = i  ;
            int currEle = matrix[currRow][currCol] ;
            
            int targRow = currCol , targCol = row - currRing - 1 ;
            swap(currEle , matrix[targRow][targCol]) ;
            
            targRow = row - currRing - 1 , targCol = row - i - 1 ;
            swap(currEle , matrix[targRow][targCol]) ;
            
            targRow = row - i - 1 , targCol = currRing ;
            swap(currEle , matrix[targRow][targCol]) ;
            
            swap(currEle , matrix[currRow][currCol]) ;
            i++ ;
        }
        currRing++ ;
    }
}
