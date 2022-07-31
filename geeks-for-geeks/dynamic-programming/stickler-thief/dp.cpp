class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1)
            return arr[0] ;
        vector<int> loot(n , 0) ;
        loot[0] = arr[0] ;
        loot[1] = max(arr[0] , arr[1]) ;

        for(int i = 2 ; i < n ; i++)
        {
            loot[i] = max(arr[i] + loot[i - 2] , loot[i - 1]) ;
        }

        return loot[n - 1] ;
    }
};
