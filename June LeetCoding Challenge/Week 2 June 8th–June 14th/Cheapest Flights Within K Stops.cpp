/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int k=K;
        if (src==dst)
            return 0;
        vector<vector<pair<int,int>>> grap(n+1);
        for (int i=0; i<flights.size(); i++)
            grap[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        vector<vector<int>> dp(k+1,vector<int>(n,1000000000));
        for (int i=0; i<grap[src].size(); i++)
            dp[0][grap[src][i].first]=grap[src][i].second;
        for (int i=1; i<=K; i++)
            for (int j=0; j<n; j++)
                if (dp[i-1][j]!=1000000000)
                    for (int k=0; k<grap[j].size(); k++)
                        dp[i][grap[j][k].first]=min(dp[i][grap[j][k].first],dp[i-1][j]+grap[j][k].second);
        int res=1000000000;
        for (int i=0; i<=k; i++)
            res=min(res,dp[i][dst]);
        if (res==1000000000)
            return -1;
        return res;
    }
};
