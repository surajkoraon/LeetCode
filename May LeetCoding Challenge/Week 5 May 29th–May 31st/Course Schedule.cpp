class Solution {
public:
    bool topological_sort(vector<int> &indegree,vector<vector<int>> graph)
    {
        int c=0;
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<graph[u].size();i++)
            {
                if(--indegree[graph[u][i]]==0)
                    q.push(graph[u][i]);
            }
            c++;
        }
        if(c==graph.size())
            return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(vector<int> p:prerequisites)
        {
            indegree[p[1]]++;
            graph[p[0]].push_back(p[1]);
        }
        return topological_sort(indegree,graph);
    }
};