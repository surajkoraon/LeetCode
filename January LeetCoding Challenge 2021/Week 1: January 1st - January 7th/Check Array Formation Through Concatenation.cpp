class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]=i;
        for(int i=0;i<pieces.size();i++)
        {
            int index=-1;
            for(int j=0;j<pieces[i].size();j++)
            {
                if(m.count(pieces[i][j])==0)
                    return false;
                if(index!=-1 && m[pieces[i][j]]!=index)
                    return false;
                index=m[pieces[i][j]]+1;
            }
        }
        return true;
    }
};
