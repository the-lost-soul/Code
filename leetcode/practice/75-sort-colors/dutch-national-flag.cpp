class Solution {
public:
    void sortColors(vector<int>& nums) ;
};

void Solution :: sortColors(vector<int>& arr)
{
    int left = 0 , middle = 0 , right = arr.size() - 1 , len = arr.size() ;
    int i = 0 ;
    while(middle <= right)
    {
        if(arr[middle] == 0)
        {
            swap(arr[middle] , arr[left]) ;
            left++ ;
            middle++ ;
        }
        else if(arr[middle] == 1)
        {
            middle++ ;
        }
        else
        {
            swap(arr[middle] , arr[right]) ;
            right-- ;   
        }
    }
}
