class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0)
            return 0;
        priority_queue<int> pq;
        for(int i:stones)
        {
            pq.push(i);
        }
        while(pq.size()!=1)
        {
            if(pq.empty())
                return 0;
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            int z=x-y;
            if(z>0)
                pq.push(z);
        }
        return pq.top();
    }
};