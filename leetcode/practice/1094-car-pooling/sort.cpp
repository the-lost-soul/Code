class Solution
{
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        vector<pair<int , int>> vec ;
        for(int i = 0 ; i < trips.size() ; i++)
        {
            vec.push_back({trips[i][1] , trips[i][0]}) ;
            vec.push_back({trips[i][2] , -trips[i][0]}) ;
        }

        sort(vec.begin() , vec.end()) ;
        int passengers = 0 ;
        for(int i = 0 ; i < vec.size() ; i++)
        {
            passengers += vec[i].second ;
            if(passengers > capacity)
                return false ;
        }
        return true ;
    }
};
