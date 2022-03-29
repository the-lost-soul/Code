class Solution {
    static bool sortComp(const vector<int>& a , const vector<int>& b)
    {
        return a[0] < b[0] ;
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(begin(points) , end(points) , sortComp) ;

        int arrows = 1 ;
        vector<int>balloon = points[0] ;
        for(int i = 1 ; i < points.size() ; i++)
        {
            if(points[i][0] > balloon[1])
            {
                balloon = points[i] ;
                arrows++ ;
            }
            else
            {
                if(balloon[1] > points[i][1])
                    balloon = points[i] ;
            }
        }
        return arrows ;
    }
};
