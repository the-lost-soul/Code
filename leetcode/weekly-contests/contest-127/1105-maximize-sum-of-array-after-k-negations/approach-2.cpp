class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) ;
};

int Solution :: largestSumAfterKNegations(vector<int>& A, int K)
{
    // Calculate the initial sum of vector .
    int sum = accumulate(A.begin() , A.end() , 0) ;
    
    // Initialize a min heap using priority queue .
    priority_queue<int , vector<int> , greater<int>> minHeap ;
    
    // Push all the elements of vector in heap .
    for(auto element : A)
    minHeap.push(element) ;
    
    // Do following while K is not zero .
    while(K)
    {
        // Pop the element with highest priority , i.e smallest element(if positive) 
        // or largest absolute value(if negative).
        int min = minHeap.top() ;
        minHeap.pop() ;
        
        // Calculate the sum obtained after negation 
        sum = sum -min + (-min) ;
        
        // Again push the newly negated element .
        minHeap.push(-min) ;
        
        // Decrement the counter
        K-- ;
    }
    
    // Return the final sum .
    return sum ;
    
}
