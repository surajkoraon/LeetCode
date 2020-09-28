class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> m;
    vector<double> v;
    void dfs(double &sol, double temp, string source, string &destination, unordered_map<string,bool> visited)
    {
        if(visited[source])
            return;
        if(source==destination)
        {
            sol=temp;
            return;
        }
        visited[source]=true;
        for(auto x:m[source])
        {
            if(!visited[x.first])
            {
                dfs(sol, temp*x.second, x.first, destination, visited);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++)
        {
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        for(int i=0;i<queries.size();i++)
        {
            string source=queries[i][0];
            string destination=queries[i][1];
            double sol=-1;
            if(m.count(source)>0 && m.count(destination)>0)
            {
                unordered_map<string,bool> visited;
                dfs(sol,1,source,destination,visited);
            }
            v.push_back(sol);
        }
        return v;
    }
};
