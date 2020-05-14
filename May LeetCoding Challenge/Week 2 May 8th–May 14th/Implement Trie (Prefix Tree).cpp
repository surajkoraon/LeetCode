/**
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
**/
class TrieNode
{   
    public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode()
    {
       for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isEnd=false; 
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* head=root;
        for(int i=0;i<word.size();i++)
        {
            if(head->children[word[i]-'a']==NULL)
            {
                head->children[word[i]-'a']=new TrieNode();
            }
            head=head->children[word[i]-'a'];
        }
        head->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* head=root;
        for(int i=0;i<word.size();i++)
        {
            if(!head->children[word[i]-'a'])
            {
                return false;
            }
            head=head->children[word[i]-'a'];
        }
        if(head->isEnd)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* head=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!head->children[prefix[i]-'a'])
                return false;
            head=head->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
