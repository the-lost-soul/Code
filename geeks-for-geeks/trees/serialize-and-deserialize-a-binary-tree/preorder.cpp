/*this  function serializes 
the binary tree and stores 
it in the vector A*/
/* The ides is to use preOrder travesral and for every
 * node having any child as NULL , we store -1 to denote
 * NULL child .
 */
void serialize(Node *root,vector<int> &tree)
{
    if(!root)
    {
        tree.push_back(-1) ;
        return ;
    }
    tree.push_back(root->data) ;
    serialize(root->left , tree) ;
    serialize(root->right , tree) ;
    
}
/*this function deserializes
 the serialized vector A*/
Node * helper(vector<int> &tree , int &start)
{
    if(tree[start] != -1)
    {
        Node * root = newNode(tree[start]) ;
        start ++ ;
        root->left = helper(tree , start) ;
        root->right = helper(tree , start) ;
        return root ;
        
    }
    else
    {
        start ++ ;
        return nullptr ;
    }
    
    
    
}
Node * deSerialize(vector<int> & tree)
{
    int length = 0 ;
    return helper(tree , length) ;
}
