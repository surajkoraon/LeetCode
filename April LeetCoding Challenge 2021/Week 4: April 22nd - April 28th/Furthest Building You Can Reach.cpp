class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum=0;
        for(int i=1;i<heights.size();i++)
        {
            int jump=heights[i]-heights[i-1];
            if(jump>0)
            {
                if(pq.size()<ladders)
                {
                    pq.push(jump);
                }
                else if(!pq.empty() && jump>pq.top())
                {
                    sum+=pq.top();
                    pq.pop();
                    pq.push(jump);
                }
                else
                {
                    sum+=jump;
                }
            }
            if(sum>bricks)
                return i-1;
        }
        return heights.size()-1;
    }
};
