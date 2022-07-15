class Pair
{
    int x ;
    int y ;
    public Pair(int x , int y)
    {
        this.x = x ;
        this.y = y ;
    }
}

class Solution
{
    public int[] twoSum(int[] nums, int target)
    {
        Pair arr[] = new Pair[nums.length] ;
        for(int i = 0 ; i < nums.length ; i++)
            arr[i] = new Pair(nums[i] , i) ;
        Arrays.sort(arr , new Comparator<Pair>()
                {
                    public int compare(Pair p1 , Pair p2)
                    {
                        return p1.x - p2.x ;
                    }
                }) ;
        int left = 0 , right = nums.length - 1 ;
        int ind1 = -1 , ind2 = -1 ;
        while(left < right)
        {
            Pair p1 = arr[left] ;
            Pair p2 = arr[right] ;
            int sum = p1.x + p2.x ;
            if(sum == target)
            {
                ind1 = p1.y ;
                ind2 = p2.y ;
                break ;
            }
            else if(sum > target)
                right-- ;
            else
                left++ ;
        }
        return new int[] {ind1 , ind2} ;
        
    }
}
