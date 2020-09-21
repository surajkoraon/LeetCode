class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passenger[1001]={0};
        int index=0;
        for(int i=0;i<trips.size();i++)
        {
            passenger[trips[i][1]]+=trips[i][0];
            passenger[trips[i][2]]-=trips[i][0];
            index=max(index,trips[i][2]);
        }
        for(int i=1;i<=index;i++)
        {
            passenger[i]+=passenger[i-1];
            if(passenger[i]>capacity)
                return false;
        }
        return true;
    }
};
