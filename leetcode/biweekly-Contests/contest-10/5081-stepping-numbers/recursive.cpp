class Solution 
{
    public :
        vector<int> countSteppingNumbers(int low, int high) ;
        void createSteppingNum(set<long>&numbers , long num , int upperBound) ;
};

void Solution :: createSteppingNum(set<long>&numbers , long num , int upperBound)
{
    if(num > upperBound)return ;
    numbers.insert(num) ;
    int lastDigit = num%10 ;
    
    if(lastDigit != 9) createSteppingNum(numbers , (num*10 + (lastDigit + 1)) , upperBound) ;
    if(lastDigit != 0)createSteppingNum(numbers , (num*10 + (lastDigit - 1)) , upperBound) ;
}

vector<int>Solution :: countSteppingNumbers(int low , int high)
{
    set<long>numbers ;
    int upperBound = high ;
    for(int i = 0 ; i <= 9 ; i++)
    {
        createSteppingNum(numbers , i , upperBound) ;
    }
    
    vector<int>ans ;
    for(auto ele : numbers)
    {
        if(ele >= low and ele <= high)ans.push_back(ele) ;
    }
    return ans 
}
