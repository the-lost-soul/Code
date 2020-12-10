int helper(Node* root , int& ans)
{
    int maxVal = root->data ;
    int minVal = INT_MAX ;
    if(root->left)
        minVal = helper(root->left , ans) ;
    if(root->right)
        minVal = min(minVal , helper(root->right , ans)) ;
    ans = max(ans , maxVal - minVal) ;
    return min(maxVal , minVal) ;
}
int maxDiff(Node* root)
{
    int ans = INT_MIN , minVal = INT_MAX , maxVal = INT_MIN ;
    helper(root , ans) ;
    return ans ;
}
