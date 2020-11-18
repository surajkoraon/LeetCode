class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
                return a[0]<b[0];
        });
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=v[j][1])
            {
                vector<int> tmp;
                tmp.push_back(v[j][0]);
                tmp.push_back(max(v[j][1],intervals[i][1]));
                v.pop_back();
                v.push_back(tmp);
            }
            else
            {
                v.push_back(intervals[i]);
                j++;
            }
        }
        return v;
    }
};
