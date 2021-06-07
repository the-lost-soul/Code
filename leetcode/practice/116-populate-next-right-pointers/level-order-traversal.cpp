class Solution {
public:
    Node* connect(Node* root) ;
};

Node* Solution :: connect(Node *root)
{
     // If no tree exists
   if( !root ) return nullptr;
    
    queue<Node * > q;
    
    // Push the root of tree 
    q.push(root) ;
    
    // Push the delimetre as it shows the end of a level
    Node *delimetre = nullptr ;
    q.push(delimetre) ;
    
    
    while( !q.empty() )
    {
        // Take out the front of queue as with this variable
        // we will be connecting the node at right of this node
        Node * temp = q.front() ;
        q.pop() ;
        
        // If ahead of the present node , no node exists then
        // simply set Right of this node to NULL.
        // This also means that we have finished a level .
        if( q.front() == delimetre ) temp->next = q.front() ;
        
        else temp->next = q.front() ;
        
        // If left and right child of present node exists
        // push the childrens .
        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
        
        // If we have reached a level , then pop the delimetre
        if(q.front() == delimetre)
        {
            q.pop();
            
            // If after popping , delimetre queue doesn't become
            // empty then this means we have more levels to traverse
            if( !q.empty() )
            // Push the delimetre again to indicate the finish
            // of next level .
            q.push(delimetre) ;
        }
        
    }
    return root ;
}
