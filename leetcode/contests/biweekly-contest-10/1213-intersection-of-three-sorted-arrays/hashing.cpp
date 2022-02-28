class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) ;
};

vector<int>Solution :: arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
    // Rememeber to use map , as we need the answer in sorted order
    map<int , int>hash ;
    for(auto ele : arr1)hash[ele]++ ;
    for(auto ele : arr2)hash[ele]++ ;
    for(auto ele : arr3)hash[ele]++ ;
    
    vector<int>ans ;
    for(auto ele : hash)
    {
        if(ele.second == 3)
        {
            ans.push_back(ele.first) ;
        }
    }
    return ans ;
}
