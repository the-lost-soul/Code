/* The idea is to use level order traversal and
 * swap each node's children .
 */
void mirror(Node* node) 
{
    queue<Node*> q ;
    q.push(node) ;
    Node* parent = nullptr ;
    while(!q.empty())
    {
        parent = q.front() ;
        q.pop() ;
        // Swap left and right children .
        swap(parent->left , parent->right) ;
        // Push both childrens .
        if(parent->left)q.push(parent->left) ;
        if(parent->right)q.push(parent->right) ;
    }
}
