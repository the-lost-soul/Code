class Solution 
{
    int index = 0 ;
    public:
    TreeNode* bstFromPreorder(vector<int>& preorder) ;
    TreeNode * construct(vector<int>& preorder , int lowerBound , int upperBound) ;
};

TreeNode * Solution :: construct(vector<int>&preorder , int lowerBound , int upperBound)
{
    // Initialize root as NULL because if the below if not satisfies , then we will simply return NULL .
    TreeNode * root = NULL ;
    
    // If current element of preorder is in range , then onlt it can be a part of current sub-tree .
    if(index < preorder.size() && preorder[index] > lowerBound && preorder[index] < upperBound)
    {
        root = new TreeNode(preorder[index]) ;
        (index) ++ ;
        
        // Recursively construct left and right sub-tree with current node as parent .
        
        // All nodes which lies between (lowerBound , root->val) , lies in left sub - tree .
        root->left = construct(preorder , lowerBound , root->val) ;
        
        // All nodes which lies between (root->val , upperBound) , lies in right sub-tree .
        root->right = construct(preorder , root->val , upperBound) ;
    }
    
    return root ;
}

TreeNode * Solution :: bstFromPreorder(vector<int>&preorder)
{
    // In place of a pointer varible , we can use instance variable .
    // int index = 0 ;
    
    return construct(preorder , INT_MIN , INT_MAX) ;
}

