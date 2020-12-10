class Solution {
public:
    vector<int> closestDivisors(int num) ;
    vector<int> usingNum1OR2(int num) ;
};

vector<int> Solution :: usingNum1OR2(int num)
{
    int ansX = 1 , ansY = num ;
    int x = 2 , y = num/2 ;
    while(x <= y)
    {
        if(num%x == 0)
        {
            y = num/x ;
            if(abs(ansX - ansY) > abs(x - y))
            {
                ansX = x ;
                ansY = y ;
            }
        }
        x++ ;
        y = num/x ;
    }
    return {ansX , ansY} ;
}

vector<int> Solution :: closestDivisors(int num)
{
    int num1 = num + 1 ;
    vector<int> ans1 = usingNum1OR2(num1) ;
    
    int num2 = num + 2 ;
    vector<int>ans2 = usingNum1OR2(num2) ;
    
    return abs(ans1[0] - ans1[1]) > abs(ans2[0] - ans2[1]) ? ans2 : ans1 ;
}
