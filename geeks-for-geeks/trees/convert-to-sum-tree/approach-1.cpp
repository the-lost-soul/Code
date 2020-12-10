int convert(Node *root)
{
    // If no tree exists , return 0 
    if(!root) return 0 ;
    
    // Find the left and right sub-tree value .
    int left = convert(root->left) ;
    int right = convert(root->right) ;
    
    // Store the current node's value , and replace the current nodes value
    // with sum of it's left and right sub-tree value .
    int old = root->data ;
    root->data = left + right ;
    
    // Return the sum of old value of current node and the new value of
    // current node .
    return old + root->data ;
}

// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
void toSumTree(Node *root)
{
    // Here this function returns value but we don't need to catch
    // that value .
    convert(root) ;
}
