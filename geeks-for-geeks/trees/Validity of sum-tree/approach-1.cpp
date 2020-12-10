/* 1. Here we are finding the validity of our tree in bottom up approach
 * 2. We can easily solve this question using post-order traversal.
 *
 * 3. Here we first call the left and right sub-tree of a node
 * before processing that node and we check the validity of current
 * node i.e whether the sum of left and right sub-tree of current node
 * is equal to the current node's data .
*/
/* Function to find whether a node is leaf or not */
bool isLeaf(Node *root)
{
    // If current node is leaf , return true else false
    if(!root->left && !root->right) return true ;
    else return false ;
}
// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
    // Stores the sum of nodes of left and right sub-trees.
    int left ;
    int right ;
    
    // If current
    if(!root || (!root->left && !root->right)) return 1 ;
    
    // call left and right sub-trees 
    if(isSumTree(root->left) && isSumTree(root->right))
    {
        /* Get the sum of nodes in left sub-tree */
        
        // If current node has no left sub-tree
        if(!root->left) left = 0 ;
        
        // If current node's left children is a leaf node
        else if(isLeaf(root->left)) left = root->left->data ;
        
        /* If current node's left child is not a leaf node return
         * double the value of current node's data because the sub-trees
         * below it will also be a sum-tree whose sum will be equal to
         * current node's data .
         */
        else left = 2*root->left->data;
        
        /* Get the sum of nodes of right sub-tree */
        
        // If current node has no right sub-tree
        if(!root->right) right = 0 ;
        
        // If current node's children is a leaf node
        else if(isLeaf(root->right)) right = root->right->data;
        
        /* If current node's right child is not a leaf node return
         * double the value of current node's data because the sub-trees
         * below it will also be a sum-tree whose sum will be equal to
         * current node's data . 
         */
        else right = 2*root->right->data ;
        
        // If current node's data is equal to sum of left and right
        // sub-trees .
        return root->data == left + right ;
    }
    // If we reach here that means tree is not a sum-tree .
    return false ;
    
}
