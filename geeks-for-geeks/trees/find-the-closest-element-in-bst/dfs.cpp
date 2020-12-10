void dfs(Node* root , int val , int& ans)
{
    if(!root)return ;
    if(root->data == val)
    {
        ans = min(ans , 0) ;
        return ;
    }
    ans = min(ans , abs(root->data - val)) ;
    if(root->data > val)
    {
        dfs(root->left , val , ans) ;
    }
    else
    {
        dfs(root->right , val , ans) ;
    }
}
// Return the minimum absolute difference between any tree node and the integer K
int minDiff(Node *root, int val)
{
    int ans = INT_MAX ;
    dfs(root , val , ans) ;
    return ans ;
}
