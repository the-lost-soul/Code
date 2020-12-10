class Solution {
public:
    int maxArea(vector<int>& height) ;
};

int Solution :: maxArea(vector<int>& heights)
{
    int maxArea = INT_MIN , left = 0 , right = heights.size() - 1 ;
    while(left < right)
    {
        maxArea = max(maxArea , (right - left)*min(heights[right] , heights[left])) ;
        if(heights[left] < heights[right])
            left++ ;
        else right-- ;
    }
    return maxArea ;
}
