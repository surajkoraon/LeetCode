class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)
            return 0;
        int poisoned=0;
        for(int i=1;i<timeSeries.size();i++)
        {
            if(timeSeries[i-1]+duration-1>=timeSeries[i])
                poisoned+=timeSeries[i]-timeSeries[i-1];
            else
                poisoned+=duration;
        }
        return poisoned+duration;
    }
};
