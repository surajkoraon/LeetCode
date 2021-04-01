class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> v(n,false);
        v[0]=true;
        int count=1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int room=q.front();
                for(int j=0;j<rooms[room].size();j++)
                {
                    if(!v[rooms[room][j]])
                    {
                        v[rooms[room][j]]=true;
                        count++;
                        q.push(rooms[room][j]);
                    }
                }
                q.pop();
            }
        }
        return count==n;
    }
};
