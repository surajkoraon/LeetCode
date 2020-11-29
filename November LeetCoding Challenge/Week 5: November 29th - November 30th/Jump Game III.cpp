class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> v(n,-1);
        return DFS(arr,v,start);
    }
    bool DFS(vector<int>& arr,vector<int>& v,int index)
    {
        if(index>=arr.size())
            return false;
        if(arr[index]==0)
            return true;
        if(v[index]!=-1)
            return v[index];
        v[index]=0;
        return DFS(arr,v,index+arr[index]) ||DFS(arr,v,index-arr[index]);
    }
};
