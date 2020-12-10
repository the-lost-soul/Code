class Solution {
public:
    vector<int> selfDividingNumbers(int left , int right) ;
    bool selfDividing(int num) ;
};

bool Solution :: selfDividing(int num)
{
    string n = to_string(num) ;
    for(auto ch : n)
    {
        if(ch == '0')
            return false ;
        if(num%(ch - '0') != 0)
            return false ;
    }
    return true ;
}

vector<int> Solution :: selfDividingNumbers(int left , int right)
{
    vector<int>ans ;
    for(int num = left ; num <= right ; num++)
    {
        if(num < 10)
            ans.push_back(num) ;
        else if(selfDividing(num))
            ans.push_back(num) ;

    }
    return ans ;
}
