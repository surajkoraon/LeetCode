class Solution {
public:
    vector<vector<int>> s;
    void permutation(vector<int>& nums,vector<int>& temp,vector<bool>& visited)
    {
        int n=nums.size();
        if(temp.size()==n)
        {
            s.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && (i == 0 || nums[i] != nums[i-1] || !visited[i-1]))
            {
                temp.push_back(nums[i]);
                visited[i]=true;
                permutation(nums,temp,visited);
                visited[i]=false;
                temp.erase(temp.end()-1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        permutation(nums,temp,visited);
        return s;
    }
};
