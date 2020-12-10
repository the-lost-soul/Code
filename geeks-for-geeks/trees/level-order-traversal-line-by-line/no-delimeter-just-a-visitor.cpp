void levelOrder(Node* node)
{
    queue<Node*>q ;
    q.push(node) ;
    int sizeOfCurrLevel = 0 ;
    Node* temp ;
    while(!q.empty())
    {
        sizeOfCurrLevel = q.size() ;
        while(sizeOfCurrLevel--)
        {
            temp = q.front() ;
            q.pop() ;
            cout<<temp->data<<" " ;
            if(temp->left)
            q.push(temp->left) ;
            if(temp->right)
            q.push(temp->right) ;
        }
        cout<<"$ " ;
    }
}
