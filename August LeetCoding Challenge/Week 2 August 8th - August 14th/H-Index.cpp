class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans=0;
        sort(citations.begin(),citations.end(),greater<int>());
        for(int i=0;i<citations.size();i++)
        {
            if(i+1<=citations[i])
                ans=i+1;
        }
        return ans;
    }
};
