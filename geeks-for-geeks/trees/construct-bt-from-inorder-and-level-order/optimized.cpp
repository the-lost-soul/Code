Node* helper(int in[] , int start , int end)
{
    // Base case .
    if(start > end)return NULL ;
    // Get the middle element of our current sub-tree
    // and make this as root of current sub-tree .
    int currRootIndex = (start + end)/2 ;
    Node* node = new Node ;
    node->key = in[currRootIndex] ;
    node->left = node->right = NULL ;
    // Construct left and right sub-tree partitioned around
    // the element present at index "currRootIndex" .
    node->left = helper(in , start , currRootIndex - 1) ;
    node->right = helper(in , currRootIndex + 1 , end) ;
    return node ;
    
    
}
Node* buildTree(int in[] , int level[] , int iStart , int iEnd , int n)
{
    Node* node = new Node ;
    // Since we know in level order traversal , first
    // element is root , hence construct the tree with
    // level[0] as root element .
    node->key = level[0] ;
    node->left = node->right = NULL ;
    
    // Get the index of current root from inOrder array
    // This will help us to divide the tree around that
    // root element .
    int index = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        if(in[i] == level[0])
        {
            index = i ;
            break ;
        }
    }
    
    // Construct the left and right sub-tree , partitioned
    // around element at positio "index" of inOrder array .
    node->left = helper(in , iStart , index - 1) ;
    node->right = helper(in , index + 1 , iEnd) ;
    return node ;
}
