class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        struct TrieNode* children[26];
        bool end;
    };
    struct TrieNode* trie;
    WordDictionary() {
        trie=getNode();
    }
    
    struct TrieNode* getNode()
    {
        struct TrieNode* node= new TrieNode;
        for(int i=0;i<26;i++)
        {
            node->children[i]=NULL;
        }
        node->end=false;
        return node;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        struct TrieNode* root=trie; 
        for(char c:word)
        {
            int index=c-'a';
            if(!root->children[index])
            {
                root->children[index]=getNode();
            }
            root=root->children[index];
        }
        root->end=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return insert(word,trie);
    }
    
    bool insert(string word,TrieNode* root)
    {
        int index;
        for(int j=0;j<word.size();j++)
        {
            char c=word[j];
            if(c=='.')
            {
                bool flag=false;
                for(int i=0;i<26;i++)
                {
                    if(root->children[i])
                    {
                        flag=flag|insert(word.substr(j+1,word.size()-j-1),root->children[i]);
                    }
                }
                return flag;
            }
            index=c-'a';
            if(!root->children[index])
                return false;
            root=root->children[index];
        }
        if(root->end)
            return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */