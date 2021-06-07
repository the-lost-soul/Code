class Solution
{
    public :
        int maxProduct(vector<int>& nums) ;
} ;

int Solution :: maxProduct(vector<int>& nums)
{
    vector<bool>no_negative_ahead(nums.size() , true) ;
    for(int i = nums.size() - 2 ; i >= 0 ; i--)
    {
        if(no_negative_ahead[i + 1] == false)
            no_negative_ahead[i] = false ;
    }


    int i = 0 , ans = 0 , curr_prod = 1 , len = nums.size() ;
    while(i < len)
    {
        curr_prod *= nums[i] ;
        ans = max(ans , curr_prod) ;
        if(curr_prod < 0)
        {
            if(no_negative_ahead[i] == true)
            {
                curr_prod = 1 ;
            }
        }
        
        if(curr_prod == 0)
            curr_prod = 1 ;
        i++ ;
    }

    return ans ;
}


int main()
{
    int size ;
    cin >> size ;
    vector<int> nums ;
    for(int i = 0 ; i < size ; i++)
    {
        int num ;
        cin >> num ;
        nums.push_back(num) ;
    }

    Solution obj ;
    int ans = obj.maxProduct(nums) ;
    cout << ans << endl ;
    return 0 ;
}



