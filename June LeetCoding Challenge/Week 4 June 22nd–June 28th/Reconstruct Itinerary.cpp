class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        vector<string> sol;
        
        for (auto t : tickets)
            graph[t[0]].push(t[1]);
        
        dfs("JFK", graph, sol);
        reverse(sol.begin(), sol.end());
        return sol;
    }
    
    void dfs(string str, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& sol) {
        
        auto &v = graph[str];
        while (!v.empty()) {
            
            auto cur = v.top();
            v.pop();
            dfs(cur, graph, sol);
        }
        
        sol.push_back(str);
     }
};
