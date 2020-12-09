class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count=0;
        unordered_map<int,int> m;
        for(int x:time)
        {
            int t=x%60;
            if(t==0)
            {
                if(m.count(0)>0)
                    count+=m[0];
            }
            else if(m.count(60-t)>0)
                count+=m[60-t];
            m[t]++;
        }
        return count;
    }
};
