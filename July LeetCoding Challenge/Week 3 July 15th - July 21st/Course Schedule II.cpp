class Solution {
public:
    bool isCyclic=false;
    void topological_sort(int i,stack<int> &st,vector<bool> &visited,vector<vector<int> > &graph,vector<bool> rec)
    {
        visited[i]=true;
        rec[i]=true;
        for(int j=0;j<graph[i].size();j++)
        {
            int vertex=graph[i][j];
            if(!visited[vertex])
            {
                topological_sort(vertex,st,visited,graph,rec); 
            }
            else if(rec[vertex])
            {
                isCyclic=true;
                return;
            }
        }
        st.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        for(vector<int> t:prerequisites)
        {
            graph[t[1]].push_back(t[0]);
        }
        vector<bool> visited(numCourses,false);
        stack<int> st;
        vector<bool> rec(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                topological_sort(i,st,visited,graph,rec);
            }
        }
        vector<int> v;
        if(isCyclic)
            return v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};