class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
        for(int i=1;i<w.size();i++)
            w[i]+=w[i-1];
        v=w;
    }
    
    int pickIndex() {
        int index=rand()%v[v.size()-1];
        auto it=upper_bound(v.begin(),v.end(),index);
        return it-v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
