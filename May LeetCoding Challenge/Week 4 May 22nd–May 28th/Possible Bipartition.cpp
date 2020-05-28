class Solution {
public:
    bool bipartite(vector<vector<int>> graph,vector<int> &color,int source)
    {
        int n=graph.size();
        color[source]=1;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=1;i<n;i++)
            {
                if(graph[u][i] && color[i]==-1)
                {
                    color[i]=1-color[u];
                    q.push(i);
                }
                else if(graph[u][i] && color[i]==color[u])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1,vector<int>(N+1,0));
        for(int i=0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]][dislikes[i][1]]=1;
            graph[dislikes[i][1]][dislikes[i][0]]=1;
        }
        vector<int> color(graph.size()+1,-1);
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
                if(!bipartite(graph,color,i))   
                    return false;
        }
        return true;
    }
};
