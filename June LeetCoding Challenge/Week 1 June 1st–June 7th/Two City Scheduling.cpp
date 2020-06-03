class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size=costs.size();
        int total=0;
        sort(costs.begin(),costs.end(),[&](vector<int> a,vector<int> b)
             {
                 return (a[1]-a[0])>(b[1]-b[0]);
             });
        for(int i=0;i<size;i++)
            if(i<size/2)
                total+=costs[i][0];
            else
                total+=costs[i][1];
        return total;
    }
};
