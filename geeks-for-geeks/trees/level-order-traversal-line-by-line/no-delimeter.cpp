void levelOrder(Node* node)
{
    if(!node)return ;
    // It tells the number of nodes at current level .
    int nodesAtNextLevel = 0 ;
    // It is set to one for root element .
    int nodesVisited = 1 ;
    queue<Node*>q ;
    q.push(node) ;
    Node* temp ;
    while(!q.empty())
    {
        temp = q.front() ;
        cout<<temp->data<<" " ;
        q.pop() ;
        // Decrement the node after visiting it .
        nodesVisited -= 1 ;
        if(temp->left)
        {
            q.push(temp->left) ;
            nodesAtNextLevel++ ;
        }
        if(temp->right)
        {
            q.push(temp->right) ;
            nodesAtNextLevel++ ;
        }
        // When this becomes zero , then it means that we have
        // visited all the nodes of that particular level .
        // Now , move ahead with another level .
        if(nodesVisited == 0)
        {
            cout<<"$ " ;
            nodesVisited = nodesAtNextLevel ;
            nodesAtNextLevel = 0 ;
        }
        
    }
}
