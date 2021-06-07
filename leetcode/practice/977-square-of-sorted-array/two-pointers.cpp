class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) ;
};

vector<int> Solution :: sortedSquares(vector<int>& arr)
{
    int left = 0 , right = arr.size() - 1 ;
    vector<int>answer ;
    while(left <= right)
    {
        int front = arr[left] ;
        int end = arr[right] ;
        if(abs(front) > abs(end))
        {
            answer.push_back(front*front) ;
            left++ ;
        }
        else
        {
            answer.push_back(end*end) ;
            right-- ;
        }
    }
    reverse(answer.begin() , answer.end()) ;
    return answer ;
}
