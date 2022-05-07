class Solution
{
public:
    bool valid(int r , int c , int row , int col)
    {
        return r >= 0 and r < row and c >= 0 and c < col ;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int row = img.size() , col = img[0].size() ;
        int cell_count = 0 ;
        vector<vector<int>>filter(row , vector<int>(col , 0)) ;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                filter[i][j] = img[i][j] ;
                cell_count = 1 ;
                if(valid(i , j + 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i][j + 1] ;
                }
                if(valid(i , j - 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i][j - 1] ;
                }
                if(valid(i - 1 , j , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i - 1][j] ;
                }
                if(valid(i + 1 , j , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i + 1][j] ;
                }
                if(valid(i + 1 , j + 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i + 1][j + 1] ;
                }
                if(valid(i + 1 , j - 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i + 1][j - 1] ;
                }
                if(valid(i - 1 , j + 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i - 1][j + 1] ;
                }
                if(valid(i - 1 , j - 1 , row , col))
                {
                    cell_count++ ;
                    filter[i][j] += img[i - 1][j - 1] ;
                }
                filter[i][j] = filter[i][j]/cell_count ;
            }
        }
        return filter ;
    }
};
