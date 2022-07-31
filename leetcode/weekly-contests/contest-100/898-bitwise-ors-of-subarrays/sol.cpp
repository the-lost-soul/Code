class Solution
{
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        int len = arr.size() ;
        unordered_set<int>ans , prev ;
        for(int i = 0 ; i < len ; i++)
        {
            unordered_set<int>temp ;
            // Bitwise OR of prev result with current element .
            // arr[i] | arr[i + 1].. | arr[j] == OR of arr[i .. j - 1] | arr[j]
            for(auto ele : prev)
                temp.insert(ele | arr[i]) ;
            temp.insert(arr[i]) ;
            prev = temp ;

            for(auto ele : temp)
                ans.insert(ele) ;
        }
        return ans.size() ;
    }
};
