/* In list form , we are basically given level order traversal
 * of Tree .
 */
void convert(node *head , TreeNode * &root)
{
    if(!head)return ;
    // First node of list will be root of tree .
    TreeNode * tree = new TreeNode(head->data) ;
    root = tree ;
    head = head->next ;
    
    // push the root of tree to queue .
    queue<TreeNode * >q ;
    q.push(tree) ;
    TreeNode * parent ;
    TreeNode  * treeNode ;
    
    while(head)
    {
        // To this node's left and right we will assign the newly create
        // nodes for tree.
        parent = q.front() ;
        q.pop() ;
        
        // Make a new node for tree and make parent's left
        // point to this node .
        treeNode = new TreeNode(head->data) ;
        parent->left = treeNode ;
        head = head->next ;
        // enqueue this newly created node .
        q.push(treeNode) ;
        
        /* After moving the list one step ahead , if we get any node
         * then create a new node for desired data with that node of
         * list and make the parent's right point to this node .
         */
        if(head)
        {
            treeNode = new TreeNode(head->data) ;
            parent->right = treeNode ;
            head = head->next ;
            q.push(treeNode) ;
        }
        
    }
}
