class Solution {
public:
    Node* target(Node* root) ;
    Node* connect(Node* root) ;
};
Node *Solution :: target(Node *root)
{
    if(!root) return root ;
    
    if(root->left) return root->left ;
    else if(root->right) return root->right ;
    
    return target(root->next);
}
Node* Solution :: connect(Node *root)
{
    if(!root) return root ;
    
    Node * newRoot = root ;
    
    // Declare it outside to prevent memory wastage
    Node * current ;
    while(root)
    {
        current = root ;
        while(current)
        {
            if(current->left)
                current->left->next = (current->right) ? current->right : target(current->next) ;
                
            if(current->right)
                current->right->next = target(current->next) ;
            
            current = current->next ;
        }
        
        root = target(root) ;
    }
    
     return newRoot ;
    
    
}
