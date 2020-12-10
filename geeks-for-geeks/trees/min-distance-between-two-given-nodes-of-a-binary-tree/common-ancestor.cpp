Node* findLCA(Node* root , int a , int b)
{
    if(!root)return nullptr ;
    if(root->data == a || root->data == b)return root ;
    Node* foundLeft = findLCA(root->left , a , b) ;
    Node* foundRight = findLCA(root->right , a , b) ;
    if(foundLeft and !foundRight)return foundLeft ;
    if(!foundLeft and foundRight)return foundRight ;
    if(foundLeft and foundRight)return root ;
    return nullptr ;
}
int helper(Node* root , int val , int depth)
{
    if(!root)return 0 ;
    if(root->data == val)return depth ;
    int leftDist = helper(root->left , val , depth + 1) ;
    int rightDist = helper(root->right , val , depth + 1) ;
    return leftDist + rightDist ;
}
int findDist(Node* root, int a, int b) 
{
    int ans = INT_MAX ;
    int distA = helper(root , a , 0) ;
    int distB = helper(root , b , 0) ;
    Node* lca = findLCA(root , a , b) ;
    int distLCA = helper(root , lca->data , 0) ;
    // cout << distA << distB << distLCA ; Debugg
    return distA + distB - 2*distLCA ;
}
