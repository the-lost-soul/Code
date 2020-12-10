struct Node * helper(int n , int pre[] , char preLN[] , int &currNode)
{
    Node * root ;
    if(preLN[currNode] == 'N' and currNode < n)
    {
        root = newNode(pre[currNode]) ;
        currNode ++ ;
        root->left = helper(n , pre , preLN , currNode) ;
        root->right = helper(n , pre , preLN , currNode) ;
    }
    else if(preLN[currNode] == 'L' and currNode < n)
    {
        root = newNode(pre[currNode]) ;
        currNode ++ ;
    }
    return root ;
}
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int currNode = 0 ;
    return helper(n , pre , preLN , currNode) ;
}
