/*This is a function problem.You only need to complete the function given below*/
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
typedef pair<int , pair<int , int> > valueIndexPair ;
int *mergeKArrays(int arr[][N], int k)
{
    int* answer = new int[k*k] ;
    
    // knew how to store the pairs .
    priority_queue<valueIndexPair , vector<valueIndexPair> , greater<valueIndexPair> >minHeap ;
    int row = 0  , col = 0 ;
    
    // Push the first elements of each row to heap .
    while(row < k)
    {
        minHeap.push({arr[row][col] , {row , col}}) ;
        row++ ;
    }
    
    // It will store the top item present in Min Heap .
    valueIndexPair currIndexAndValue ;
    int minEle = 0 ;
    // It will store the index of element at top of heap .
    pair<int , int>currIndex ;
    
    int index = 0 ;
    
    while(!minHeap.empty())
    {
        // Get the item present in top of heap .
        currIndexAndValue = minHeap.top() ;
        minHeap.pop() ;
        // Get the min element .
        minEle = currIndexAndValue.first ;
        // Get the index of min element .
        currIndex = currIndexAndValue.second ;
        row = currIndex.first ;
        col = currIndex.second ;
        // Push the minimum element to answer array .
        answer[index] = minEle ;
        index++ ;
        
        // If next column exists , then push the element
        // which is next greater than current min Element .
        if((col + 1) < k)
        {
            minHeap.push({arr[row][col + 1] , {row , col + 1}}) ;
        }
    }
    
    return answer ;
    
    
}
