class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) ;
};

vector<int> Solution :: luckyNumbers(vector<vector<int> >& arr) 
{
    int row = arr.size() , col = arr[0].size() ;
    int rowMin[row] , colMax[col] ;
    for(int i = 0 ; i < row ; i++)
    {
        int minEle = INT_MAX ;
        for(int j = 0 ; j < col ; j++)
        {
            minEle = min(minEle , arr[i][j]) ;
        }
        rowMin[i] = minEle ;
    }

    for(int j = 0 ; j < col ; j++)
    {
        int maxEle = INT_MIN ;
        for(int i = 0 ; i < row ; i++)
        {
            maxEle = max(arr[i][j] , maxEle) ;
        }
        colMax[j] = maxEle ;
    }
    
    vector<int> ans ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(rowMin[i] == colMax[j])
            {
                ans.push_back(arr[i][j]) ;
                break ;
            }
        }
    }
    return ans ;
}
