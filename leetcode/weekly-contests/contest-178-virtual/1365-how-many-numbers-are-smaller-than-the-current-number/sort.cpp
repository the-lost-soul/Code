class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) ;
};

vector<int> Solution :: smallerNumbersThanCurrent(vector<int>& nums)
{
    vector<int>temp = nums ;
    sort(temp.begin() , temp.end()) ;
    unordered_map<int , int>myMap ;
    for(int i = temp.size() - 1 ; i >= 0 ; )
    {
        int j = i ;
        while(j >= 0 and temp[i] == temp[j])
        {
            j-- ;
        }
        myMap[temp[i]] = j + 1 ;  
        i = j ;
    }
    
    vector<int>ans ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        ans.push_back(myMap[nums[i]]) ;
    }
    return ans ;
}
