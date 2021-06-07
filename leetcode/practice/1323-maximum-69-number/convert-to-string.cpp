class Solution {
public:
    int maximum69Number (int num) ;
};

int Solution :: maximum69Number(int num)
{
    string n = to_string(num) ;
    for(auto &ch : n)
    {
        if(ch == '6')
        {
            ch = '9' ;
            break ;
        }
    }
    return stoi(n) ;
}
