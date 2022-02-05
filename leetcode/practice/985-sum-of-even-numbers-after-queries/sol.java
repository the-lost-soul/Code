class Solution
{
    public int[] sumEvenAfterQueries(int[] nums , int[][] queries)
    {
        int sum = 0 ;
        for(int i = 0 ; i < nums.length ; i++)
            sum += nums[i]%2 == 0 ? nums[i] : 0 ;

        int[] answer = new int[queries.length] ;
        for(int i = 0 ; i < queries.length ; i++)
        {
            int val = queries[i][0] ;
            int index = queries[i][1] ;
            int curr_ith = nums[index] ;
            int new_ith = curr_ith + val ;
            nums[index] = new_ith ;
            
            if(curr_ith % 2 == 0)
            {
                if(new_ith % 2 == 0)
                    sum = sum - curr_ith + new_ith ;
                else
                    sum = sum - curr_ith ;
            }
            else
            {
                if(new_ith % 2 == 0)
                    sum += new_ith ;
            }
            
            answer[i] = sum ;
        }

        return answer ;
    }
}




