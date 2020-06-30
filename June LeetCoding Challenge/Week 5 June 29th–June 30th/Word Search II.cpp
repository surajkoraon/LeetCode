class TrieNode {
public:
    string word;
    TrieNode* children[26];
    TrieNode() {
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};

class Solution {
public:
    TrieNode* root;
    vector<string> sol;
    Solution()
    {
        root=new TrieNode();
    }
    void insert(string key)
    {
        TrieNode* head=root;
        for(int i=0;i<key.size();i++)
        {
            if(!head->children[key[i]-'a'])
            {
                head->children[key[i]-'a']=new TrieNode();
            }
            head=head->children[key[i]-'a'];
        }
        head->word=key;
    }
    void dfs(TrieNode* head,int row,int col,vector<vector<char>>& board)
    {
        if(board[row][col]=='$')
            return;
        int ch=board[row][col]-'a';
        if(!head->children[ch])
            return;
        head=head->children[ch];
        board[row][col]='$';
        if(head->word.size())
        {
            sol.push_back(head->word);
            head->word="";
        }
        if(row>0)
            dfs(head,row-1,col,board);
        if(row+1<board.size())
            dfs(head,row+1,col,board);
        if(col>0)
            dfs(head,row,col-1,board);
        if(col+1<board[0].size())
            dfs(head,row,col+1,board);
        board[row][col]='a'+ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(string word:words)
        {
            insert(word);
        }
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(root,i,j,board);
            }
        }
        return sol;
    }
};