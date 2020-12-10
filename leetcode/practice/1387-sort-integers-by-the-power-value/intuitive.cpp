class Solution {
public:
    int getKth(int lo, int hi, int k) ;
    int getPower(int num) ;
};

int Solution :: getPower(int num)
{
    int steps = 0 ;
    while(num != 1)
    {
        if(num%2)num = 3*num + 1 ;
        else num = num/2 ;
        steps++ ;
    }
    return steps ;
}

int Solution :: getKth(int low , int high , int k)
{
    vector<pair<int , int>>power ;
    for(int i = low ; i <= high ; i++)
    {
        power.push_back({getPower(i) , i}) ;
    }
    
    sort(begin(power) , end(power)) ;
    return power[k - 1].second ;
}

