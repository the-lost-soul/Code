/* The idea used here is as follows -- >
 * 1.--> If the node say x ,whose successor we have to find has
 *       a right child , then simply find the node having min. ,
 *       value in right sub - tree of node x .
 
 * 2.--> If the node x has empty right child , then we have to
 *       traverse the tree till we reach the node x , and the
 *       result will be any ancestor of x .
 *       
 *       a.--> If x's data is less than current node's data , then
 *             traverse left sub-tree and update the ancestor address .
 
 *       b.--> If x's data is greater than current node's data , then
 *             traverse right sub-tree , and dont update the ancestor's
 *             address .
 */
Node * min(Node * root)
{
    int minimum = INT_MAX ;
    Node * minNode = nullptr ;
    while(root)
    {
        if(root->data < minimum)
        {
            minimum = root->data ;
            minNode = root ;
        }
        root = root->left ;
    }
    return minNode ;
    
}

Node *findSuccessor(Node * root , Node * key)
{
    Node * successor = nullptr ;
    while(root != key)
    {
        if(root->data > key->data)
        {
            successor = root ;
            root = root->left ;
        }
       else root = root->right ;
    }
    return successor ;
}


/* The below function should return the node which is
inorder successor of given node x. */
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(!root)return nullptr;
    
    if(x->right)return min(x->right) ;
    else return findSuccessor(root , x) ;
}
