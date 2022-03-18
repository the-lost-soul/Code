class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1 , 1) ;

        for(int i = 2 ; i <= rowIndex ; i++)
        {
            int left = 1 , right = i - 1 ;
            vector<int> temp(i + 1 , 1) ;
            while(left <= right)
            {
                temp[left] = ans[left - 1] + ans[left] ;
                temp[right] = ans[right] + ans[right - 1] ;
                left++ ;
                right-- ;
            }

            for(int j = 0 ; j < temp.size() ; j++)
                ans[j] = temp[j] ;
        }
        return ans ;
    }
};
