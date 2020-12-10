class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) ;
};

bool isEven(int num)
{
    if(num%2 == 0)return true ;
    else return false ;
}
vector<int> Solution :: sortArrayByParity(vector<int>& arr)
{
    int front = 0 ;
    int end = arr.size() - 1 ;
    while(front < end)
    {
        // If front element id odd and last element is even , then
        // swap both and shrink both pointers towards each other .
        if(!isEven(arr[front]) and isEven(arr[end]))
        {
            swap(arr[front] , arr[end]) ;
            front ++ ;
            end -- ;
        }
        // If both front and last element id odd , then this means that last 
        // element is at correct position , so simply decremnt end .
        else if(!isEven(arr[front]) and !isEven(arr[end]))end -- ;
        else if(isEven(arr[front]) and !isEven(arr[end]))
        {
            front ++ ;
            end -- ;
        }
        else front ++ ;
    }
    return arr ;
}
