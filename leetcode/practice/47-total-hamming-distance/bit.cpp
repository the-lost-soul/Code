class Solution {
public:
    int totalHammingDistance(vector<int>& nums) ;
};

/* Same as finding different corresponding bits between pairs of numbers */
int Solution :: totalHammingDistance(vector<int>& nums)
{
    int answer = 0 ,count1 = 0 ,count0 = 0 ;
    // Iterate for 32 bits as the range of numbers given 
    // can fit in 32 bit integers .
    for(int i = 0 ; i < 32 ; i++)
    {
        count0 = count1 = 0 ;
        for(int j = 0 ; j < nums.size() ; j++)
        {
            // Check if ith bit is set or not .
            if(nums[j] & (1<<i))count1++ ;
            else count0++ ;
        }
        
        // Our result after ith iteration will be the new combination of
        // earlier answer plus that of combination formed by count0 and count1  .
        answer = (answer + count1*count0) ;
    }
    return answer ;
}
