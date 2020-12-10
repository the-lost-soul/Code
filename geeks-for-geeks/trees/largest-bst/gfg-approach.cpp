typedef struct info
{
    int minEle ;
    int maxEle ;
    bool bst ;
    int size ;
    int ans ;
} ;
info helper(Node* root)
{
    if(!root)
    {
        return {INT_MAX , INT_MIN , true , 0 , 0} ;
    }
    if(!root->left && !root->right)
        return {root->data , root->data , true , 1 , 1} ;
    
    info leftTree = helper(root->left) ;
    info rightTree = helper(root->right) ;
    info currentTree ;
    if(leftTree.bst && rightTree.bst)
    {
        int val = root->data ;
        if(val > leftTree.maxEle && val < rightTree.minEle)
        {
            currentTree.minEle = min(val , min(leftTree.minEle , rightTree.minEle)) ;
            currentTree.maxEle = max(val ,max(leftTree.maxEle , rightTree.maxEle)) ;
            currentTree.bst = true ;
            currentTree.size = 1 + leftTree.size + rightTree.size ;
            currentTree.ans = currentTree.size ;
            return currentTree ;
        }
    }
    currentTree.ans = max(leftTree.ans , rightTree.ans) ;
    currentTree.size = 1 + leftTree.size + rightTree.size ;
    currentTree.bst = false ;
    return currentTree ;
}
/*You are required to complete this method */
int largestBst(Node *root)
{
    info details = helper(root) ;
    return  details.ans ;
}
