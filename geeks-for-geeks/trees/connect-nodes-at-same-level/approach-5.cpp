Node *target(Node *root)
{
    // If no tree exists return NULL
    if(!root) return root ;
    
    while(root)
    {
        // If left or right sub-tree exists return that .
        if(root->left) return root->left ;
        else if(root->right) return root->right ;
    
        /* If both right and left childrens of current node doesn't exists ,
        * then move to next right of current node 
        */
        root = root->nextRight ;
    }
    
    return root ;
}

// Should set the nextRight for all nodes
// It works  for all types of binary tree .
void connect(Node *root)
{
    // If no tree exists
    if(!root) return ;
    
    
    // Declare it outside to prevent memory wastage
    Node * current ;
    while(root)
    {
        current = root ;
        while(current)
        {
            // If left child exists .
            /* Then connect the right node of current to next node of current's left 
             * whereas if there is no right child of current node then traverse toward
             * right of current node and then find a suitable node to connect to left child
             * of current.
            */
            if(current->left)
                current->left->nextRight = (current->right) ? current->right : target(current->nextRight) ;
            
            // If right child exists .
            /* Here find the next node which is present at right of current node
             * and then find a suitable children of that node which will get connected
             * to right child of current .
            */
            if(current->right)
                current->right->nextRight = target(current->nextRight) ;
            
            // Traverse in rightwards to connect other nodes of that level
            current = current->nextRight ;
        }
        
        // Find the suitable node whose childrens(next Level) we will be connecting
        root = target(root) ;
    }
    
