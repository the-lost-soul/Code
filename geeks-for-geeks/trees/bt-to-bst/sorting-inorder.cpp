void getInOrder(Node* root , vector<int> &inOrder)
{
    if(root->left)getInOrder(root->left , inOrder) ;
    inOrder.push_back(root->data) ;
    if(root->right)getInOrder(root->right , inOrder) ;
}
Node* helper(vector<int> inOrder , int start , int end)
{
    if(start > end)return NULL ;
    // Get the mid , and make it root of current sub-tree .
    int mid = (start + end)/2 ;
    int val = inOrder[mid] ;
    Node* node = new Node ;
    node->data = val ;
    node->left = node->right = nullptr ;
    // Traverse for left and right sub-tree .
    node->left = helper(inOrder , start , mid - 1) ;
    node->right = helper(inOrder , mid + 1 , end) ;
    return node ;
}
Node *binaryTreeToBST (Node *root)
{
    // Store the in-order traversal of BT in a vector .
    vector<int>inOrder ;
    getInOrder(root , inOrder) ;
    // Sort the vector .
    sort(inOrder.begin() , inOrder.end()) ;
    // Make BST .
    return helper(inOrder , 0 , inOrder.size() - 1) ;
}
 
