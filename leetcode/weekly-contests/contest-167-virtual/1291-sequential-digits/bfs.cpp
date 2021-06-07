class Solution {
public:
    vector<int> sequentialDigits(int low, int high) ;
};

vector<int> Solution :: sequentialDigits(int low , int high)
{
    queue<int>myQueue ;
    for(int i = 1 ; i <= 9 ; i++)
    {
        myQueue.push(i) ;
    }
    vector<int>ans ;
    while(!myQueue.empty())
    {
        int num = myQueue.front() ;
        myQueue.pop() ;
        if(num <= high and num >= low)
        {
            ans.push_back(num) ;
        }
        if(num > high)break ;
        int lastDigit = num%10 ;
        if(lastDigit < 9)
        {
            myQueue.push(num*10 + lastDigit + 1) ;
        }
    }
    return ans ;
}
