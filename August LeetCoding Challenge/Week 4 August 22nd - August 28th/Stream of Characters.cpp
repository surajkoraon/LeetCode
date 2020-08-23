class StreamChecker {
public:
    int arr[40000];
    struct TrieNode
    {
        struct TrieNode *children[26];
        bool end;
    };
    struct TrieNode *root=new TrieNode;
    struct TrieNode *trie=new TrieNode;
    struct TrieNode *getNode()
    {
        struct TrieNode *temp=new TrieNode;
        temp->end=false;
        for(int i=0;i<26;i++)
        {
            temp->children[i]=NULL;
        }
        return temp;
    }
    void insert(struct TrieNode *trie,string word)
    {
        struct TrieNode *temp=trie;
        for(int i=word.size()-1;i>=0;i--)
        {
            if(!temp->children[word[i]-'a'])
                temp->children[word[i]-'a']=getNode();
            temp=temp->children[word[i]-'a'];
        }
        temp->end=true;
    }
    StreamChecker(vector<string>& words) {
        trie=getNode();
        for(string word:words)
        {
            insert(trie,word);
        }
        root=trie;
    }
    int i=-1;
    bool query(char letter) {
        int ch=letter-'a';
        i++;;
        arr[i]=ch;
        root=trie;
        if(root->children[ch])
        {
            int j=i;
            while(1)
            {
                if(!root->children[arr[j]])
                { 
                    return false; 
                }
                root=root->children[arr[j]];
                j--;
                if(root->end)
                {
                    return true;
                }
                if(j<0)
                {
                    return false;
                }
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */