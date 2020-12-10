#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef struct trieNode
{
    struct trieNode* children[26] ;
    bool wordEnd = false ;
}trieNode ;
void scanArray(vector<string>& words , int size)
{
    for(int i = 0 ; i < size ; i++)
        cin >> words[i] ;
}

trieNode* getNode()
{
    trieNode* root = new trieNode ;
    for(int i = 0 ; i < 26 ; i++)
    {
        root->children[i] = nullptr ;
    }
    root->wordEnd = false ;
    return root ;
}

void insert(trieNode* root , string word)
{
    trieNode* crawl = root ;
    for(int i = 0 ; i < word.length() ; i++)
    {
        int index = word[i] - 'a' ;
        if(crawl->children[index] == nullptr)
        {
            crawl->children[index] = getNode() ;
        }
        crawl = crawl->children[index] ;
    }
    crawl->wordEnd = true ;
}

int search(trieNode* root , string target)
{
    trieNode* crawl = root ;
    for(int i = 0 ; i < target.length() ; i++)
    {
        int index = target[i] - 'a' ;
        if(!crawl->children[index])
        {
            return 0 ;
        }
        crawl = crawl->children[index] ;
    }
    return (crawl and crawl->wordEnd) ;
}
int solve(vector<string>& words , string target , int size)
{
    int len = words.size() ;
    trieNode* root = getNode() ;
    for(int i = 0 ; i < len ; i++)
    {
        insert(root , words[i]) ;
    }
    return search(root , target) ;
}
int main()
 {
	int testcase ;
	cin >> testcase ;
	while(testcase--)
	{
	    int size ;
    	cin >> size ;
    	vector<string>words(size) ;
    	scanArray(words , size) ;
    	string target ;
    	cin >> target ;
	   cout << solve(words , target , size) << endl ;
	}
	return 0;
}
