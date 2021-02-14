class Solution {
public:
    bool graphColoring(vector<vector<int>>& graph,int node,int color,vector<int>& colors)
    {
        colors[node]=color;
        vector<int> edges=graph[node];
        for(int i=0;i<edges.size();i++)
        {
            if(colors[edges[i]]==color)
                return false;
            if(colors[edges[i]]==-1)
                if(!graphColoring(graph,edges[i],1-color,colors))
                    return false;
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==0)
            return true;
        vector<int> colors(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colors[i]==-1)
            {
                if(!graphColoring(graph,i,0,colors))
                {
                    return false;
                }
            }
        }
        return true;
    }
};