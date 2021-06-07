class Solution 
{
    string res ;
    vector<char>set{'a' , 'b' , 'c'} ;
public:
    string getHappyString(int n, int k) ;
    void helper(string happy , char prev , int n , int& k) ;
};

void Solution :: helper(string happy , char prev , int n , int& k)
{
    if(n == 0)
    {
        k-- ;
        if(k == 0)
            res = happy ;
        return ;
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        if(set[i] != prev)
        {
            helper(happy + set[i] , set[i] , n - 1 , k) ;
            if(k == 0)break ;
        }
    }
}

string Solution :: getHappyString(int n , int k)
{
    helper("" , '1' , n , k) ;
    return k == 0 ? res : "" ;
}
