class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) ;
};

vector<vector<int>> Solution :: groupThePeople(vector<int>& grpSize)
{
    vector<vector<int>>answer , groupEle(grpSize.size() + 1) ;
    for(int i = 0 ; i < grpSize.size() ; i++)
    {
        groupEle[grpSize[i]].push_back(i) ;
        if(groupEle[grpSize[i]].size() == grpSize[i])
        {
            answer.push_back({}) ;
            swap(answer.back() , groupEle[grpSize[i]]) ;
        }
    }
    return answer ;
}
