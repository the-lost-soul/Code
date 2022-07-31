class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) ;
};

vector<vector<int>> Solution :: groupThePeople(vector<int>& grpSize)
{
    // Hash each ID's to their respective sizes .
    unordered_map<int , vector<int>>hash ;
    for(int i = 0 ; i < grpSize.size() ; i++)
    {
        hash[grpSize[i]].push_back(i) ;
    }
    
    vector<vector<int>>answer ;
    // For each group size
    for(auto itr : hash)
    {
        // Get the size of a single group
        int eachGroupSize = itr.first ;
        // Get all the ID's which have same group size . Remember number of
        // ID's can be larger than the group size .
        vector<int>temp = itr.second ;
        // Get the number of ID's which belong to same size .
        int tempSize = temp.size() ;
        // Get the number of groups which can be formed from the current ID's .
        int numOfGroup = tempSize/eachGroupSize ;
        int i = 0 ;
        // Starting assigning each ID's to a group according to their group size .
        while(i < tempSize)
        {
            // Number of ID's in each group will be equal to the group size to which
            // each ID belong .
            answer.push_back({temp.begin() + i , temp.begin() + i + eachGroupSize}) ;
            i += eachGroupSize ;
        }
    }
    return answer ;
}
