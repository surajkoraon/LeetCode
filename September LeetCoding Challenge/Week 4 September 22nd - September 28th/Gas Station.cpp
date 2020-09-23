class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=0,gastank=0,shortage=0;
        for(int i=0;i<gas.size();i++)
        {
            gastank+=gas[i]-cost[i];
            if(gastank<0)
            {
                shortage+=gastank;
                index=i+1;
                gastank=0;
            }
        }
        if(gastank+shortage>=0)
            return index;
        return -1;
    }
};
