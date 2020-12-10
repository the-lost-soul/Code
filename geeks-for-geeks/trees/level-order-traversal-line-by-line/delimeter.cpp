void levelOrder(Node* node)
{
    queue<Node *>myQueue;
    myQueue.push(node);
    myQueue.push(NULL);
    while(!myQueue.empty())
    {
        if(myQueue.front()->left!=NULL)
        myQueue.push(myQueue.front()->left);
        if(myQueue.front()->right!=NULL)
        myQueue.push(myQueue.front()->right);
        printf("%d ",myQueue.front()->data);
        myQueue.pop();
        if(myQueue.front()==NULL)
        {
            myQueue.pop();
            printf("$ ");
            if(myQueue.empty())break;
            else myQueue.push(NULL);
        }
        
    }
}
