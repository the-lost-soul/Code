typedef pair<int , int> pairs ;
class customComp
{
    public :
    bool operator()(pairs arg1 , pairs arg2)
    {
        if(arg1.second == arg2.second)return arg1.first < arg2.first ;
        return arg1.second > arg2.second ;
    }
} ;
void sortByFreq(int arr[] , int n)
{
    unordered_map<int , int>helper ;
    set<pairs , customComp>hash ;
    for(int i = 0 ; i < n ; i++)
    {
        // Current element is seen first time .
        if(helper.find(arr[i]) == helper.end())
        {
            helper[arr[i]]++ ;
            hash.insert({arr[i] , helper[arr[i]]}) ;
        }
        else
        {
            
            pairs details = {arr[i] , helper[arr[i]]} ;
            // Search the repeated element in set and delete it .
            set<pairs> :: iterator itr = hash.find(details) ;
            hash.erase(itr) ;
            helper[arr[i]]++ ;
            // Insert the currently deleted element back to set
            // incrementing it's frequency .
            hash.insert({arr[i] , helper[arr[i]]}) ;
        }
    }
    for(auto details : hash)
    {
        int ele = details.first , freq = details.second ;
        while(freq != 0)
        {
            cout << ele << " " ;
            freq-- ;
        }
    }
}
