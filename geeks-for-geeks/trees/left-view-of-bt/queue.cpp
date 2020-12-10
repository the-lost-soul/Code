/*MY SOLUTION USING QUEUE*/
void leftView(Node *root)
{
    // Your code here
    int maxLevel=0,level=0;
    // Set a delimetre to chech if we 
    // have reached the given level
    Node *delimetre=new Node;
    
    queue<Node *>node;
    // printf("%d ",root->data);
    node.push(root);
    node.push(delimetre);
    
    while(!node.empty()&&node.front()!=delimetre)
    {
        Node *current=node.front();
        node.pop();
        // If right child is present then enqueue
        if(current->right!=NULL) node.push(current->right);
        // If left child is present then enqueue
        if(current->left!=NULL) node.push(current->left);
        
        // If the current node is equal to delimetre
        // then this means we have traversed all nodes
        // of that level,So increment level and
        // push delimetre again and pop ths last level's 
        // delimetre
        if(node.front()==delimetre)
        {
            level++;
            node.push(delimetre);
            node.pop();
        }
        // If the currenr Level is more than maxLevel
        // then print the current Node
        if(level>maxLevel)
        {
            printf("%d ",current->data);
            maxLevel=level;
        }
    }
    
    
}

