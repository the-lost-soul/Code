class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) ;
};

string Solution :: stringShift(string s , vector<vector<int>>& shift)
{
    int moves = 0 ;
    for(auto details : shift)
    {
        moves += details[0] == 0 ? details[1] : -details[1] ;
    }
    
    int len = s.length() ;
    moves = (moves%len + len)%len ;
    return s.substr(moves) + s.substr(0 , moves) ;
}
