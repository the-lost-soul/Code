Node *createTree(int parent[], int n)
{
    if(n == 0)return nullptr ;
    
    vector<Node *>parentNode(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        Node * node = new Node(i) ;
        parentNode[i] = node ;
        
    }
    Node * root ;
    for(int i = 0 ; i < n ; i++)
    {
        if(parent[i] != -1)
        {
            if(!parentNode[parent[i]]->left)
            parentNode[parent[i]]->left = parentNode[i] ;
            else parentNode[parent[i]]->right = parentNode[i] ;
        }
        else root = parentNode[i] ;
    }
    
    return root ;
}
