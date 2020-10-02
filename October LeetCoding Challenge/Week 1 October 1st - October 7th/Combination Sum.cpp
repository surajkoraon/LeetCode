class Solution {
public:
    vector<vector<int>> v;
    void backtracking(vector<int>& candidates, int target, int total, vector<int> temp, int index)
    {
        if(total==target)
        {
            v.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(total+candidates[i]<=target)
            {
                temp.push_back(candidates[i]);
                backtracking(candidates,target,total+candidates[i],temp,i);
                temp.erase(temp.end()-1);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtracking(candidates,target,0,temp,0);
        return v;
    }
};
