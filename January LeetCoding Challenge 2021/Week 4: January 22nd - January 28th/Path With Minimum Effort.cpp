class Solution {
public:
    typedef pair<int, pair<int, int>> node;
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size(), tmp;
        
        std::vector<vector<bool>>mark (n + 1, std::vector<bool> (m + 1, 0));
        auto comp = [](node p1, node p2){ return p1.first > p2.first;};
        std::priority_queue<node, vector<node>, decltype( comp ) > pq(comp);
        
        pq.push({0, {0,0}});
        
        while(!pq.empty()){
            auto [val, p] = pq.top();
            auto [i, j] = p;
            pq.pop();
            
            if(i == n - 1 && j == m - 1) return val;
            
            mark[i][j] = true;
        
            
            if(i - 1 >= 0 && !mark[i - 1][j]){
                pq.push({max(val, abs(heights[i][j] - heights[i - 1][j])), {i - 1, j}});    
            } 
            
            if(i + 1 < n && !mark[i + 1][j]){
                pq.push({max(val, abs(heights[i][j] - heights[i + 1][j])), {i + 1, j}});    
            }
            
            if(j - 1 >= 0 && !mark[i][j - 1]){
                pq.push({max(val, abs(heights[i][j] - heights[i][j - 1])), {i, j - 1}});    
            } 
            
            if(j + 1 < m && !mark[i][j + 1]){
                pq.push({max(val, abs(heights[i][j] - heights[i][j + 1])), {i, j + 1}});    
            }
            
        }
        return 0;
    }
}; 
