/* Do an inOrder Traversal as it gives a BST in sorted form
 * and for every node check whether node's data lies between
 * l and h or not . If yes then print it else do nothing .
 */
void printNearNodes(Node *root, int l, int h)
{
    if(!root)return ;
    printNearNodes(root->left , l , h) ;
    if(root->data >= l and root->data < h)cout<<root->data<<" " ;
    printNearNodes(root->right , l , h) ;
}
