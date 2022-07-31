class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) ;
};

vector<int> Solution :: peopleIndexes(vector<vector<string>>& favoriteCompanies)
{
    unordered_map<string , int>hash ;
    int row = favoriteCompanies.size() , numMap = 0 ;
    for(int i = 0 ; i < row ; i++)
    {
        for(auto companies : favoriteCompanies[i])
        {
            if(hash.find(companies) == hash.end())
            {
                hash[companies] = numMap ;
                numMap++ ;
            }
        }
    }
    
    vector<vector<int>>mapping(row , vector<int>(numMap , 0)) ;
    for(int i = 0 ; i < row ; i++)
    {
        for(auto companies : favoriteCompanies[i])
        {
            mapping[i][hash[companies]] = 1 ;
        }
    }
    
    unordered_map<int , bool>isSubset ;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < row ; j++)
        {
            if(j == i)continue ;
            int matched = 0 ;
            for(int k = 0 ; k < numMap ; k++)
            {
                if(mapping[i][k] == 1 and mapping[i][k] == mapping[j][k])
                {
                    matched++ ;
                }
            }
            if(matched == favoriteCompanies[i].size())
            {
                isSubset[i] = true ;
                break ;
            }
        }
    }
    vector<int>ans ;
    for(int i = 0 ; i < row ; i++)
    {
        if(isSubset.find(i) == isSubset.end())
        {
            ans.push_back(i) ;
        }
    }
    return ans ;
}
