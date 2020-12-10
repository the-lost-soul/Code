class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) ;
    void steppingNumbers(vector<int>&ans , int low , int high) ;
    bool checkIfSteppingNum(int num) ;
};

bool Solution :: checkIfSteppingNum(int num)
{
    int currDigit = num%10 ;
    num /= 10 ;
    while(num != 0)
    {
        if(abs(currDigit - num%10) != 1)return false ;
        currDigit = num%10 ;
        num /= 10 ;
    }
    return true ;
}
void Solution :: steppingNumbers(vector<int>&ans , int low , int high)
{
    while(low <= high)
    {
        bool check = checkIfSteppingNum(low) ;
        if(check)ans.push_back(low) ;
        low++ ;
    }
}

vector<int>Solution :: countSteppingNumbers(int low , int high)
{
    vector<int>ans ;
    // All one digit numbers are stepping number
    while(low <= 10 and low <= high)
    {
        ans.push_back(low) ;
        low++ ;
    }
    
    steppingNumbers(ans , low , high) ;
    return ans ;
}
