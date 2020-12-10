class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) ;
};
 
vector<int> Solution :: deckRevealedIncreasing(vector<int>& deck)
{
    sort(deck.begin() , deck.end()) ;
    deque<int>dq ;
    int len = deck.size() ;
    for(int i = 0 ; i < len ; i++)
    {
        dq.push_back(i) ;
    }
    vector<int>res(len , 0) ;
    for(int i = 0; i < len ; i++)
    {
        int topCard = dq.front() ;
        dq.pop_front() ;
        res[topCard] = deck[i] ;
        if(!dq.empty())
        {
            int nextTopCard = dq.front() ;
            dq.pop_front() ;
            dq.push_back(nextTopCard) ;
        }
        
        
    }
    return res ;
}
