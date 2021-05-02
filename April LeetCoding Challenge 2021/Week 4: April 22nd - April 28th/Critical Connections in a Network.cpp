class Solution {
private: int time = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n); 
        vector<int> disc(n, -1); 
        vector<int> low(n); 
        vector<vector<int>> res;
        for(auto connection : connections)
        {
            int a = connection[0], b = connection[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(disc[i] == -1)
                dfs(i, low, disc, graph, res, i);
        }
        return res;
    }
    
    void dfs(int u, vector<int>& low, vector<int>& disc, vector<vector<int>>& graph, vector<vector<int>>& res, int parent)
    {
        time++;
        disc[u] = time;
        low[u] = time;
        for(int v : graph[u])
        {
            if(v == parent) continue; 
            if(disc[v] == -1)
            { 
                dfs(v, low, disc, graph, res, u);
                low[u] = min(low[u], low[v]); 
                if(low[v] > disc[u]) 
                    res.push_back({u, v});
            }
            else
            {  
                low[u] = min(low[u], disc[v]); 
            }
        }
    }
};
