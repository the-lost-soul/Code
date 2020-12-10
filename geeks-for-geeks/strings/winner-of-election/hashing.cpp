void winner(string str[] , int len)
{
    unordered_map<string , int>hash ;
    string name ;
    int vote = INT_MIN ;
    for(int i = 0 ; i < len ; i++)
    {
        // Increment the vote of current candidate .
        hash[str[i]]++ ;
        // If the number of vote which current candidate has
        // is greater than the earlier candidates votes , then
        // the current candidate may be a winner .
        if(hash[str[i]] > vote)
        {
            vote = hash[str[i]] ;
            name = str[i] ;
        }
        // If votes of current and earlier candidate's gets tied
        // then the winner can be the one with lexicographically
        // smaller name .
        else if(hash[str[i]] == vote)
        {
            if(str[i] < name)
            {
                name = str[i] ;
                vote = hash[str[i]] ;
            }
        }
    }
    cout << name << " " << vote ;
}
