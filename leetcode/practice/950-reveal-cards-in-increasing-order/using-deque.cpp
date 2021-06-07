class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) ;
};
/* What we have to do here is that , first sort the vector and then
 * for every new element added to deque , we have to rearrange the
 * elements already present in the deque in such a way that once we
 * start removing elements from them as per rule provided then the 
 * output should be sorted . After re-arranging, push the new 
 * element to front of the deque .
 * For re-arranging the input , we start from the end of the sorted
 * array .
 * Eg -- Take input -- [17,13,11,2,3,5,7] , correct output(ordering)
 * will be -- [2,13,3,11,5,17,7]
 * 1 -- First sort the input - [2,3,5,7,11,13,17]
 * 2 -- Initially , push to deque the last element , so deque = [17]
 * 3 -- Now start rearranging the deque for every new element .
 *  3.1 -- For ele = 13 , if we need the sorted output then deque should be
 *  deque = [13,17] . To get this , we pop the last element and push it
 *  to front of deque and then push current element i.e 13 to front of
 *  deque .
 *  3.2 -- For ele = 11 , deque should have order [11,17,13] . With this ,
 *  we can get the sorted result i.e [11,13,17] . To do this , we pop last
 *  element of deque i.e 17 , push it to front to get deque = [17,13] and 
 *  then push to front the current element of array to deque to get [11,17,13]
 *  Similarly , iterate for rest of the elements .
 */
vector<int> Solution :: deckRevealedIncreasing(vector<int>& deck)
{
    sort(deck.begin() , deck.end()) ;
    deque<int>dq ;
    int len = deck.size() ;
    dq.push_back(deck[len - 1]) ;
    for(int i = len - 2 ; i >= 0 ; i--)
    {
        // Re-arranging .
        int pivot = dq.back() ;
        dq.pop_back() ;
        dq.push_front(pivot) ;
        dq.push_front(deck[i]) ;
    }
    
    vector<int>res(len , 0) ;
    for(int i = 0 ; i < len ; i++)
    {
        res[i] = dq.front() ;
        dq.pop_front() ;
    }
    return res ;
}
