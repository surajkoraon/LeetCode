class Solution {
public:
    struct TrieNode
    {
        struct TrieNode* children[26];
        bool isendofword;
    };
    struct TrieNode* getNode()
    {
        struct TrieNode* trie=new TrieNode;
        for(int i=0;i<26;i++)
        {
            trie->children[i]=NULL;
        }
        trie->isendofword=false;
        return trie;
    }
    struct TrieNode* root;
    void insert(string word)
    {   
        struct TrieNode* trie=root;
        for(int i=0;i<word.size();i++)
        {
            if(!trie->children[word[i]-'a'])
                trie->children[word[i]-'a']=getNode();
            trie=trie->children[word[i]-'a'];
        }
        trie->isendofword=true;
    }
    bool search(string word,vector<int> &dp,int index)
    {
        if(index==word.size())
            return true;
        struct TrieNode* trie = root;
        for(int i=index;i<word.size();i++)
        {
            int ch = word[i]-'a';
            if(!trie->children[ch])
                return dp[i]=0;
            trie = trie->children[ch];
            if(trie->isendofword)
            {
                if(dp[i+1]!=-1)
                    return dp[i+1];
                else if(search(word,dp,i+1))
                    return dp[i+1]=1;
            }
        }
        return  dp[index]=trie->isendofword;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool arr[26]={false};
        for(string temp:wordDict)
        {
            for(char ch:temp)
            {
                arr[ch-'a']=true;
            }
        }
        for(char ch:s)
        {
            
            if(arr[ch-'a']==false)
                return false;
        }
        root=getNode();
        for(int i=0;i<wordDict.size();i++)
        {
            insert(wordDict[i]);
        }
        vector<int> dp(s.size()+1,-1);
        return search(s,dp,0);
    }
};