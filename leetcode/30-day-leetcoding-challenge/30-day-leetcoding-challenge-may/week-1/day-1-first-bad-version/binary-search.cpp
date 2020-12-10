// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        int left = 1 , right = n ;
        int ans ;
        while(left <= right)
        {
            int mid = left + (right - left)/2 ;
            bool ans = isBadVersion(mid) ;
            if(!ans)
            {
                left = mid + 1 ;
            }
            else 
            {
                if(mid == 1 || !isBadVersion(mid - 1)) return mid ;
                right = mid - 1 ;
            }
        }
        return -1 ;
    }
};
