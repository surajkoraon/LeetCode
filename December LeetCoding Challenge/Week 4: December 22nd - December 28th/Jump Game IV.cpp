class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 0 || n == 1){
            return 0;
        }
        
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++){
            map[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int level = 0;
        int temp, size;
        
        while(!q.empty()){
            size = q.size();
            while(size--){
                temp = q.front();
                q.pop();
                if(temp == n - 1){
                    return level;
                }
                
                if(temp - 1 > -1 && !visited[temp - 1]){
                    q.push(temp - 1);
                    visited[temp - 1] = true;
                }
                if(temp + 1 < n && !visited[temp + 1]){
                    q.push(temp + 1);
                    visited[temp + 1] = true;
                }
                
                for(int index: map[arr[temp]]){
                    if(!visited[index]){
                        q.push(index);
                        visited[index] = true;
                    }
                }
                map[arr[temp]] = {};
            }
            level++;
        }
        return -1;
    }
};
