class Solution {
public:
    bool isPathCrossing(string path) ;
    struct pair_hash 
    {  // you need this in order to put pair in the set
        std::size_t operator()(const std::pair<int, int>& v) const 
        { 
            return v.first * 97 + v.second; 
        }
    } ;
};
bool Solution :: isPathCrossing(string path)
{
    unordered_set<pair<int , int> , pair_hash> points ;
    points.insert({0 , 0}) ;
    int x = 0 , y = 0 ;
    for(auto dir : path)
    {
        if(dir == 'N') y += 1 ;
        else if(dir == 'S') y -= 1 ;
        else if(dir == 'E') x += 1 ;
        else x -= 1 ;

        if(points.find({x , y}) != points.end())
            return true ;
        points.insert({x , y}) ;
    }
    return false ;
}
