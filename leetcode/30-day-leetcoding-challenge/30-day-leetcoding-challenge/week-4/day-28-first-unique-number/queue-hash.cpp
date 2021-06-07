class FirstUnique 
{
    unordered_map<int , int>hash ;
    queue<int>myQueue ;
public:
    FirstUnique(vector<int>& nums) ;
    
    int showFirstUnique() ;
    
    void add(int value) ;
};

FirstUnique :: FirstUnique(vector<int>& nums)
{
    for(auto ele : nums) 
        hash[ele]++ ;
    for(auto ele : nums)
    {
        if(hash[ele] == 1)
            myQueue.push(ele) ;
    }
}

int FirstUnique :: showFirstUnique()
{
    int ele = -1 ;
    while(hash[ele] != 1)
    {
        if(myQueue.empty())return -1 ;
        ele = myQueue.front() ;
        if(hash[ele] != 1)
            myQueue.pop() ;
    }
    
    return ele ;
}

void FirstUnique :: add(int value)
{
    hash[value]++ ;
    if(hash[value] == 1)
        myQueue.push(value) ;
}

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
