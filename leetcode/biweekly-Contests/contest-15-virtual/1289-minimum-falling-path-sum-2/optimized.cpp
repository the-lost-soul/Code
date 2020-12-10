class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) ;
};

int Solution :: minFallingPathSum(vector<vector<int>>& arr)
{
    int row = arr.size() , col = arr[0].size() ;
    int prevMin1 = 0 , prevMin2 = 0 , prevPos = -1 ;
    for(int i = 0 ; i < row ; i++)
    {
        int currMin1 = INT_MAX , currMin2 = INT_MAX , currPos = -1 ;
        for(int j = 0 ; j < col ; j++)
        {
            int minEle = j != prevPos ? prevMin1 : prevMin2 ;
            if(arr[i][j] + minEle < currMin1)
            {
                currMin2 = currMin1 ;
                currMin1 = arr[i][j] + minEle ;
                currPos = j ;
            }
            else
            {
                currMin2 = min(currMin2 , arr[i][j] + minEle) ;
            }
        }
        prevMin2 = currMin2 ;
        prevMin1 = currMin1 ;
        prevPos = currPos ;
        
    }
    
    return prevMin1 ;
    
}
