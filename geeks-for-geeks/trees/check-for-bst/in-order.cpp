
/* The idea is to use in-order traversal of BST and store 
 * each nodes data in a data structure(say vector or queue).
 * After this check whether each nodes data is in sorted order
 * or not , if yes , then tree is BST otherwise not a BST .
 */
void helper(Node * root , vector<int>&vec)
{
    if(!root) return ;
    
    helper(root->left , vec) ;
    vec.push_back(root->data) ;
    helper(root->right , vec) ;
    
}
bool isBST(Node* root) 
{
    if(!root)return true ;
    vector<int>vec ;
    helper(root , vec) ;
    
    for(int i = 0 ; i < vec.size() - 1 ; i++)
    {
        if(vec[i + 1] < vec[i])return false ;
    }
    
    return true ;
}

