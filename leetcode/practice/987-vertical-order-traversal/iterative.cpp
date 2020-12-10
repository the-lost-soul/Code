class Solution 
{
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) ;
};

vector<vector<int>> Solution::verticalTraversal(TreeNode *root)
{
    // Hash each node's value according to it's horizontal distance.
    unordered_map<int,vector<pair<int,int>>>myMap;
    
    // Stores the width of the tree from min to max.
    int horizontalMax=INT_MIN;
    int horizontalMin=INT_MAX;
    
    // Initialize the root to be at co-ordinates (0,0).
    int horizontalDistance=0;
    int verticalDistance=0;
    
    // Stores the pair of Node * and horizontal and vertical distance.
    queue<pair<TreeNode *,pair<int,int>>>q;
    
    // Push the root.
    q.push(make_pair(root,make_pair(horizontalDistance,verticalDistance)));
    // DEBUGGING-->
    // cout<<"aquib-->"<<q.front().first->val<<" ";
    
    // Do,level order traversal
    while(!q.empty())
    {
        
        auto node=q.front().first;
        
        // DEBUGGING-->
        // cout<<"aquib-->"<<q.front().first->val<<" ";
        auto coOrdinate=q.front().second;
        int h=coOrdinate.first;
        int v=coOrdinate.second;
        
        q.pop();
        
        myMap[h].push_back(make_pair(v,node->val));
        
        // If left child is present,then enqueue it with co-ordinates(h-1,v+1).
        if(node->left!=NULL)q.push(make_pair(node->left,make_pair(h-1,v+1)));
        
        // If right child is present,then enqueue it with co-ordinates(h+1,v+1).                           
        if(node->right!=NULL)q.push(make_pair(node->right,make_pair(h+1,v+1)));
         
        // Find the horizontal min and max.
        if(horizontalMin>h)horizontalMin=h;
        if(horizontalMax<h)horizontalMax=h;
    }
      
    // Stores the answer
    vector<vector<int>>answer;
    int lines=myMap.size();
    answer.resize(lines);
    
    int index=0;    
    // Traverse the tree from max. horizontal direction in -ve x axis to
    // maximum horizontal distance in +ve x axis
    for(int i=horizontalMin; i<=horizontalMax; i++)
    {
        // sort the vector of pairs for i'th index.
        sort(myMap[i].begin(),myMap[i].end());
        
        // Now,traverse the sorted vector of i'th index and store
        // each elements value in answer vector.
        for(auto x:myMap[i])
        {
            answer[index].push_back(x.second);
        }
        index++;
        
    }
    
    return answer;
    
    
}
