class Solution {
public:
    vector<vector<int> > sol;
    void dfs(vector<vector<int>>& graph,int node,vector<int> v)
    {
        v.push_back(node);
        int n=graph.size();
        if(node==n-1)
        {
            sol.push_back(v);
            return;
        }
        int m=graph[node].size();
        for(int i=0;i<m;i++)
        {
            dfs(graph,graph[node][i],v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        dfs(graph,0,v);
        return sol;
    }
};
