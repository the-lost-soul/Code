class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) ;
};

bool Solution :: validateBinaryTreeNodes(int n , vector<int>& leftChild , vector<int>& rightChild)
{
    unordered_set<int>hash ;
    stack<int>myStack ;
    myStack.push(0) ;
    for(int i = 0 ; i < n ; i++)
    {
        /* If stack becomes empty before ending of the given number of nodes
         * i.e (n - 1) , then it means that there are disjoint Binary Trees
         * present .
         */
        if(myStack.empty())return false ;
        int lChild = leftChild[i] , rChild = rightChild[i] ;
        if(lChild != -1 and rChild != -1)
        {
            if(hash.find(lChild) == hash.end())
            {
                hash.insert(lChild) ;
                myStack.push(lChild) ;
            }
            else return false ;
            
            if(hash.find(rChild) == hash.end())
            {
                hash.insert(rChild) ;
                myStack.push(rChild) ;
            }
            else return false ;
        }
        else 
        {
            if(lChild != -1)
            {
                if(hash.find(lChild) == hash.end())
                {
                    hash.insert(lChild) ;
                    myStack.push(lChild) ;
                }
                else return false ;
            }
            if(rChild != -1)
            {
                if(hash.find(rChild) == hash.end())
                {
                    hash.insert(rChild) ;
                    myStack.push(rChild) ;
                }
                else return false ;  
            }   
        }
        if(hash.find(i) == hash.end())
        {
            hash.insert(i) ;
        }
        myStack.pop() ;
    }
    return true ;
}
