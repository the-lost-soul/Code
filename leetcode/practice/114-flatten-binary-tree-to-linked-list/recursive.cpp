class Solution {
public:
    void flatten(TreeNode* root) ;
    void helper(TreeNode * root , TreeNode * target) ;
};

void Solution :: flatten(TreeNode * root)
{
    // Between this node and it's right node , we will
    // connect the newly flatten tree from left sub-tree .
    TreeNode *target = NULL ;
    
    // Call to helper function to flatten the tree
    helper(root , target) ;
}

void Solution :: helper(TreeNode * root , TreeNode * target)
{
    // If root does not exist, return
    if(!root) return;
    
    // Flatten the left and right subtree recursively
    helper(root->left);
    helper(root->right);
    
    
    /* Here target will be NULL only when right sub-tree is already
       flatten and if not flatten then step inside . */
    if(target != NULL)
    {
        /* Find the last node of the newly flatten node of left sub-tree,
        *  if exists(it may be itself in the case when newly flatten tree
        *  of left sub-tree contains only one element) .
        *  The reason why we found that last element is that we will link
        *  that node with the node present at the right of target node .
        *  target--->>> root--->>> target->right
        */
        TreeNode * temp = root ;
        while(temp->right != NULL)
        {
            temp = temp ->right ;
        }
        
        // Here link the node present at right of target node .
        temp->right = target->right ;
        
        // Now link target node with the first node of the newly flatten 
        // tree obtained from left sub-tree and make left of target node NULL.
        target->right = root ;
        target->left = NULL ;
    }
}
