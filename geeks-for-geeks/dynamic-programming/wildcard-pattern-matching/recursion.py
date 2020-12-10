def wildCardUtil(pattern , text , i , j) :
    if i < 0 and j >= 0 : return 0
    if i < 0 and j < 0 : return 1 ;
    if j < 0 and i >= 0 :
        if pattern[i] == '*' :
            return wildCardUtil(pattern , text , i - 1 , j)
        return 0

    if pattern[i] == '*' :
        return wildCardUtil(pattern , text , i - 1 , j) or wildCardUtil(pattern , text , i , j - 1)
    
    if pattern[i] == '?' or pattern[i] == text[j] :
        return wildCardUtil(pattern , text , i - 1 , j - 1)
    
def wildCard(text , pattern):
    # Code here
    return wildCardUtil(pattern , text , len(pattern) - 1 , len(text) - 1)
    
