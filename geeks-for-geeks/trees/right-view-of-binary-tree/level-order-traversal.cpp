// Should print right view of tree
/* Do level order traversal , and for each level 
 * print the first node from right . To know which
 * node is first rightmost node of a level , maintain
 * a variable "firstNodeOfCurrLevel" which if set to
 * true , then this means current node is first rightmost 
 * node of current level and if false , then the current
 * node is some other node .
 */
void rightView(Node *root)
{
    if(!root)return ;
    queue<Node *>q ;
    q.push(root) ;
    q.push(NULL) ;
    Node * temp ;
    bool firstNodeOfCurrLevel = true ;
    while(!q.empty())
    {
        temp = q.front() ;
        q.pop() ;
        if(firstNodeOfCurrLevel)
        {
            cout<<temp->data<<" " ;
            firstNodeOfCurrLevel = false ;
            
        }
        if(temp->right)q.push(temp->right) ;
        if(temp->left)q.push(temp->left) ;
        if(q.front() == nullptr)
        {
            q.pop() ;
            if(q.empty())break ;
            else
            {
                firstNodeOfCurrLevel = true ;
                q.push(nullptr) ;
            }
        }
    }
    
}
