class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root);
};

bool Compare(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second < b.second) return true;
    else if(a.second == b.second)
    {
        if(a.first < b.first) return true;
        else return false;
    }
    return false;
}

vector<vector<int>> Solution :: verticalTraversal(TreeNode *root)
{
    vector<vector<int>> answer;
    if(!root) return answer;
    
    // First perform the level order traversal and fill the map
    map<int, vector<pair<int,int>>> myMap;
    
    
    
    queue<pair<TreeNode*,pair<int,int>>> myQueue;
    myQueue.push(make_pair(root, make_pair(0,0)));
    myMap[0].push_back(make_pair(root->val,0));
    
    
    while(!myQueue.empty())
    {
        auto current = myQueue.front();
        myQueue.pop();
        
        int dist = (current.second).first;
        int level = (current.second).second;
            
        auto leftChild = (current.first)->left;
        auto rightChild = (current.first)->right;
        
        // Push the left child with 1 less distance
        if(leftChild) 
        {
            myMap[dist-1].push_back(make_pair(leftChild->val, level+1));
            myQueue.push(make_pair(leftChild, make_pair(dist-1,level+1)));
        }
        
        if(rightChild)
        {
            myMap[dist+1].push_back(make_pair(rightChild->val,level+1));
            myQueue.push(make_pair(rightChild, make_pair(dist+1,level+1)));
        }
    }
    
    int lines = myMap.size();
    answer.resize(lines);
    
    int index = 0;
    for(auto ele : myMap)
    {
        auto row_vec = ele.second;
        sort(row_vec.begin(), row_vec.end(), Compare);
        for(auto ele : row_vec)
        {
            answer[index].push_back(ele.first);
        }
        index++;
    }
    
    return answer;
}
